/*-
 * Copyright (c) 2016 - 2021 Rozhuk Ivan <rozhuk.im@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Author: Rozhuk Ivan <rozhuk.im@gmail.com>
 *
 */

#include <sys/param.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/ucred.h>
#include <sys/mount.h>
#include <sys/fcntl.h> /* open, fcntl */
#include <sys/queue.h>

#include <inttypes.h>
#include <stdlib.h> /* malloc, exit */
#include <unistd.h> /* close, write, sysconf */
#include <string.h> /* bcopy, bzero, memcpy, memmove, memset, strerror... */
#include <dirent.h> /* opendir, readdir */
#include <errno.h>
#include <pthread.h>
#include <glib.h>

#include "kqueue_fnm.h"


/* Preallocate items count. */
#ifndef FILES_ALLOC_BLK_SIZE
#	define FILES_ALLOC_BLK_SIZE	32
#endif


typedef struct readdir_context_s {
	int		fd;
	uint8_t		*buf;
	size_t		buf_size;
	size_t		buf_used;
	size_t		buf_pos;
} readdir_ctx_t, *readdir_ctx_p;


typedef struct file_info_s { /* Directory file. */
	int		fd;		/* For notify kqueue(). */
	struct dirent 	de;		/* d_reclen used for action. */
	struct stat	sb;
} file_info_t, *file_info_p;


typedef struct kq_file_nonify_monitor_obj_s	*kq_fnmo_p;

typedef struct kq_file_nonify_monitor_entry_s {
	TAILQ_ENTRY(kq_file_nonify_monitor_entry_s) next;
	kq_fnmo_p	fnmo;
	void		*udata;
	volatile int	enabled;
} kq_fnme_t;

TAILQ_HEAD(kq_fnme_head, kq_file_nonify_monitor_entry_s);

typedef struct kq_file_nonify_monitor_obj_s {
	int		fd;		/* For notify kqueue(). */
	int		is_dir;
	int		is_local;	/* Is file system local. */
	int		is_removed;	/* File/dir deleted, reported and can be only free. */
	int		is_cached;	/* Added to fnmo_cache. */
	struct stat	sb;
	char		path[(PATH_MAX + sizeof(void*))];
	size_t		path_size;
	size_t		name_offset;	/* Parent path size. */
	uint32_t	rate_lim_cur_interval;	/* From rate_limit_time_init to rate_limit_time_max. 0 disabled. */
	size_t		rate_lim_ev_cnt;	/* Events count then rate_lim_cur_interval != 0 since last report. */
	sbintime_t	rate_lim_ev_last;	/* Last event time. */
	void		*udata;
	kq_fnm_p	kfnm;
	struct kq_fnme_head entry_head;
	/* For dir. */
	file_info_p	files;
	volatile size_t	files_count;
	size_t		files_allocated;
} kq_fnmo_t;


typedef struct kq_file_nonify_monitor_s {
	int		fd;		/* kqueue() fd. */
	int		pfd[2];		/* pipe queue specific. */
	GHashTable	*fnmo_cache;
	struct statfs	*mounts;
	size_t		mounts_count;
	kfnm_event_handler_cb cb_func;	/* Callback on dir/file change. */
	kq_file_mon_settings_t s;
	sbintime_t	rate_lim_time_init; /* rate_limit_time_init */
	pthread_t	tid;
} kq_fnm_t;


typedef void (*kq_msg_cb)(void *arg);

typedef struct kq_file_mon_msg_pkt_s {
	size_t		magic;
	kq_msg_cb	msg_cb;
	void		*arg;
	size_t		chk_sum;
} kq_fnm_msg_pkt_t, *kq_fnm_msg_pkt_p;

#define KF_MSG_PKT_MAGIC	0xffddaa00


#ifdef O_PATH
#	define OPEN_MODE_FLAG	O_PATH
#elif defined(O_EVTONLY)
#	define OPEN_MODE_FLAG	O_EVTONLY
#else
#	define OPEN_MODE_FLAG	O_RDONLY
#endif
#ifndef O_NOATIME
#	define O_NOATIME	0
#endif
#define OPEN_FILE_MON_FLAGS	(O_NONBLOCK | O_NOFOLLOW | O_NOATIME | O_CLOEXEC | OPEN_MODE_FLAG)
#define OPEN_FILE_READ_FLAGS	(O_NONBLOCK | O_NOFOLLOW | O_NOATIME | O_CLOEXEC | O_RDONLY)

#ifndef NOTE_CLOSE_WRITE
#	define NOTE_CLOSE_WRITE	0
#endif
#define EVFILT_VNODE_SUB_FLAGS	(NOTE_WRITE |				\
				NOTE_EXTEND |				\
				NOTE_ATTRIB |				\
				NOTE_LINK |				\
				NOTE_CLOSE_WRITE)

#define EVFILT_VNODE_FLAGS_ALL	(NOTE_DELETE |				\
				EVFILT_VNODE_SUB_FLAGS |		\
				NOTE_RENAME |				\
				NOTE_REVOKE)

#ifndef _GENERIC_DIRSIZ
#	define _GENERIC_DIRSIZ(__de)	MIN((__de)->d_reclen, sizeof(struct dirent))
#endif

#define IS_NAME_DOTS(__name)	('.' == (__name)[0] &&			\
				 ('\0' == (__name)[1] || 		\
				  ('.' == (__name)[1] && '\0' == (__name)[2])))
#define IS_DE_NAME_EQ(__de1, __de2)  (0 == mem_cmpn((__de1)->d_name,	\
						    (__de1)->d_namlen,	\
						    (__de2)->d_name,	\
						    (__de2)->d_namlen))
#define zalloc(__size)		calloc(1, (__size))

#if (!defined(HAVE_REALLOCARRAY) && (!defined(__FreeBSD_version) || __FreeBSD_version < 1100000))
#	define reallocarray(__mem, __size, __count)	realloc((__mem), ((__size) * (__count)))
#endif

/* To not depend from compiler version. */
#define MSTOSBT(__ms)		((sbintime_t)((((uint64_t)1 << 32) * (uint64_t)(__ms)) / 1000))

#ifndef TAILQ_FOREACH_SAFE
#define	TAILQ_FOREACH_SAFE(var, head, field, tvar)			\
	for ((var) = TAILQ_FIRST((head));				\
	    (var) && ((tvar) = TAILQ_NEXT((var), field), 1);		\
	    (var) = (tvar))
#endif

#ifndef CLOCK_MONOTONIC_FAST
#	define CLOCK_MONOTONIC_FAST	CLOCK_MONOTONIC
#endif


void 	*kq_fnm_proccess_events_proc(void *data);

static inline int
mem_cmpn(const void *buf1, const size_t buf1_size,
    const void *buf2, const size_t buf2_size) {

	if (buf1_size != buf2_size)
		return (((buf1_size > buf2_size) ? 127 : -127));
	if (0 == buf1_size || buf1 == buf2)
		return (0);
	if (NULL == buf1)
		return (-127);
	if (NULL == buf2)
		return (127);
	return (memcmp(buf1, buf2, buf1_size));
}

static int
realloc_items(void **items, const size_t item_size,
    size_t *allocated, const size_t alloc_blk_cnt, const size_t count) {
	size_t allocated_prev, allocated_new;
	uint8_t *items_new;

	if (NULL == items || 0 == item_size || NULL == allocated ||
	    0 == alloc_blk_cnt)
		return (EINVAL);
	allocated_prev = (*allocated);
	if (NULL != (*items) &&
	    allocated_prev > count &&
	    allocated_prev <= (count + alloc_blk_cnt))
		return (0);
	allocated_new = (((count / alloc_blk_cnt) + 1) * alloc_blk_cnt);
	items_new = (uint8_t*)reallocarray((*items), item_size, allocated_new);
	if (NULL == items_new) /* Realloc fail! */
		return (ENOMEM);

	if (allocated_new > allocated_prev) { /* Init new mem. */
		memset((items_new + (allocated_prev * item_size)), 0x00,
		    ((allocated_new - allocated_prev) * item_size));
	}
	(*items) = items_new;
	(*allocated) = allocated_new;

	return (0);
}

/* Like getmntinfo() but allow free mem. */
static int
getmntinfo_ex(struct statfs **mntbufp, int mode) {
	int ret;
	struct statfs *buf;

	if (NULL == mntbufp)
		return (EINVAL);
	/* Request count. */
	ret = getfsstat(NULL, 0, mode);
	if (-1 == ret)
		return (ret);
	/* Alloc mem. */
	buf = calloc((ret + 1), sizeof(struct statfs));
	if (NULL == buf)
		return (-1);
	/* Request data. */
	ret = getfsstat(buf, ((ret + 1) * sizeof(struct statfs)), mode);
	if (-1 == ret) {
		free(buf);
		buf = NULL;
	}
	(*mntbufp) = buf;

	return (ret);
}

static int
mounts_find_name(struct statfs *mounts, size_t mounts_count,
    const char *mntonname) {
	size_t i;

	if (NULL == mounts || NULL == mntonname)
		return (0);
	for (i = 0; i < mounts_count; i ++) {
		if (0 != strncmp(mntonname, mounts[i].f_mntonname, MNAMELEN))
			continue;
		return (1);
	}
	return (0);
}


static void
readdir_free(readdir_ctx_p rdd) {

	if (NULL == rdd)
		return;

	if (-1 != rdd->fd) {
		close(rdd->fd);
		rdd->fd = -1;
	}
	if (NULL != rdd->buf) {
		free(rdd->buf);
		rdd->buf = NULL;
	}
}

static int
readdir_start(const int fd, struct stat *sb, const size_t exp_count,
    readdir_ctx_p rdd) {
	struct stat _sb;

	if (-1 == fd || NULL == rdd)
		return (EINVAL);

	if (NULL == sb) {
		sb = &_sb;
		if (0 != fstat(fd, sb))
			return (errno);
	}
	/* Init. */
	memset(rdd, 0x00, sizeof(readdir_ctx_t));
	/* Reopen for read. */
	rdd->fd = openat(fd, ".", (OPEN_FILE_READ_FLAGS | O_DIRECTORY));
	if (-1 == rdd->fd)
		return (errno);
	/* Calculate buf size for getdents(). */
	rdd->buf_size = MAX((size_t)sb->st_size, (exp_count * sizeof(struct dirent)));
	if (0 == rdd->buf_size) {
		rdd->buf_size = (16 * PAGE_SIZE);
	}
	/* Make buf size well aligned. */
	if (0 != sb->st_blksize) {
		if (powerof2(sb->st_blksize)) {
			rdd->buf_size = roundup2(rdd->buf_size, sb->st_blksize);
		} else {
			rdd->buf_size = roundup(rdd->buf_size, sb->st_blksize);
		}
	} else {
		rdd->buf_size = round_page(rdd->buf_size);
	}
	/* Allocate buf. */
	rdd->buf = malloc(rdd->buf_size);
	if (NULL == rdd->buf) {
		readdir_free(rdd);
		return (ENOMEM);
	}

	return (0);
}

static int
readdir_next(readdir_ctx_p rdd, struct dirent *de) {
	int error = 0;
	ssize_t ios;
	uint8_t *ptr;

	if (NULL == rdd || NULL == rdd->buf || NULL == de)
		return (EINVAL);

	for (;;) {
		if (rdd->buf_used <= rdd->buf_pos) {
			/* Called once if buf size calculated ok. */
			ios = getdents(rdd->fd, (char*)rdd->buf, rdd->buf_size);
			if (-1 == ios) {
				error = errno;
				break;
			}
			if (0 == ios) {
				error = ESPIPE; /* EOF. */
				break;
			}
			rdd->buf_used = (size_t)ios;
			rdd->buf_pos = 0;
		}
		/* Keep data aligned. */
		ptr = (rdd->buf + rdd->buf_pos);
		memcpy(de, ptr, (sizeof(struct dirent) - sizeof(de->d_name)));
		if (0 == de->d_reclen) {
			error = ESPIPE; /* EOF. */
			break;
		}
		rdd->buf_pos += de->d_reclen;
#ifdef DT_WHT
		if (DT_WHT == de->d_type)
			continue;
#endif
		if (0 == de->d_namlen)
			continue; /* Empty. */
		memcpy(de, ptr, _GENERIC_DIRSIZ(de));
		if (0 == de->d_name[0])
			continue; /* Empty. */
		if (IS_NAME_DOTS(de->d_name))
			continue; /* Dots. */
		return (0); /* OK. */
	}

	/* Err or no more files, auto cleanup. */
	readdir_free(rdd);

	return (error);
}


static int
file_info_find_ni(file_info_p files, size_t files_count,
    file_info_p fi, size_t *idx) {
	size_t i;
	mode_t st_ftype;

	if (NULL == files || NULL == fi || NULL == idx)
		return (0);
	st_ftype = (S_IFMT & fi->sb.st_mode);
	for (i = 0; i < files_count; i ++) {
		if ((S_IFMT & files[i].sb.st_mode) != st_ftype)
			continue;
		if ((fi->sb.st_ino != files[i].sb.st_ino ||
		     fi->de.d_fileno != files[i].de.d_fileno) &&
		    0 == IS_DE_NAME_EQ(&fi->de, &files[i].de))
			continue;
		(*idx) = i;
		return (1);
	}
	(*idx) = files_count;
	return (0);
}

static int
file_info_find_ino(file_info_p files, size_t files_count,
    file_info_p fi, size_t *idx) {
	size_t i;
	mode_t st_ftype;

	if (NULL == files || NULL == fi || NULL == idx)
		return (0);
	st_ftype = (S_IFMT & fi->sb.st_mode);
	for (i = 0; i < files_count; i ++) {
		if ((S_IFMT & files[i].sb.st_mode) != st_ftype ||
		    fi->sb.st_ino != files[i].sb.st_ino ||
		    fi->de.d_fileno != files[i].de.d_fileno)
			continue;
		(*idx) = i;
		return (1);
	}
	(*idx) = files_count;
	return (0);
}

static int
file_info_find_name(file_info_p files, size_t files_count,
    file_info_p fi, size_t *idx) {
	size_t i;
	mode_t st_ftype;

	if (NULL == files || NULL == fi || NULL == idx)
		return (0);
	st_ftype = (S_IFMT & fi->sb.st_mode);
	for (i = 0; i < files_count; i ++) {
		if ((S_IFMT & files[i].sb.st_mode) != st_ftype ||
		    0 == IS_DE_NAME_EQ(&fi->de, &files[i].de))
			continue;
		(*idx) = i;
		return (1);
	}
	(*idx) = files_count;
	return (0);
}

static void
file_info_fd_close(file_info_p files, size_t files_count) {
	size_t i;

	if (NULL == files || 0 == files_count)
		return;
	for (i = 0; i < files_count; i ++) {
		if (-1 == files[i].fd)
			continue;
		close(files[i].fd);
		files[i].fd = -1;
	}
}


static int
is_fs_local(struct statfs *stfs, const char **local_fs, const char **non_local_fs) {
	size_t i;

	if (NULL == stfs)
		return (0);
	/* White listed fs. */
	if (NULL != local_fs) {
		for (i = 0; NULL != local_fs[i]; i ++) {
			if (0 == strncmp(stfs->f_fstypename, local_fs[i],
			    sizeof(stfs->f_fstypename)))
				return (1);
		}
	}
	if (0 == (MNT_LOCAL & stfs->f_flags))
		return (0);
	/* Filter out black listed fs. */
	if (NULL != non_local_fs) {
		for (i = 0; NULL != non_local_fs[i]; i ++) {
			if (0 == strncmp(stfs->f_fstypename, non_local_fs[i],
			    sizeof(stfs->f_fstypename)))
				return (0);
		}
	}
	return (1);
}


static void
kq_fnmo_rate_lim_stop(kq_fnmo_p fnmo) {
	struct kevent kev;

	if (NULL == fnmo || 0 == fnmo->rate_lim_cur_interval)
		return;
	fnmo->rate_lim_cur_interval = 0;
	fnmo->rate_lim_ev_cnt = 0;
	EV_SET(&kev, (uintptr_t)fnmo, EVFILT_TIMER,
	    (EV_DELETE | EV_CLEAR), 0, 0, NULL);
	kevent(fnmo->kfnm->fd, &kev, 1, NULL, 0, NULL);
}

static int
kq_fnmo_rate_lim_shedule_next(kq_fnmo_p fnmo) {
	u_short flags = (EV_ADD | EV_CLEAR | EV_ONESHOT);
	struct kevent kev;

	if (NULL == fnmo || -1 == fnmo->fd ||
	    0 == fnmo->kfnm->s.rate_limit_time_init)
		return (EINVAL);
	if (0 == fnmo->rate_lim_cur_interval) { /* First call. */
		fnmo->rate_lim_cur_interval = fnmo->kfnm->s.rate_limit_time_init;
	} else {
		if (fnmo->rate_lim_cur_interval == fnmo->kfnm->s.rate_limit_time_max)
			return (0); /* No need to modify timer. */
		/* Increase rate limit interval. */
		fnmo->rate_lim_cur_interval *= fnmo->kfnm->s.rate_limit_time_mul;
	}
	if (fnmo->rate_lim_cur_interval >= fnmo->kfnm->s.rate_limit_time_max) {
		/* Check upper limit and shedule periodic timer with upper rate limit time. */
		flags &= ~EV_ONESHOT;
		fnmo->rate_lim_cur_interval = fnmo->kfnm->s.rate_limit_time_max;
	}
	/* Setup timer. */
	EV_SET(&kev, (uintptr_t)fnmo, EVFILT_TIMER, flags,
	    NOTE_MSECONDS, fnmo->rate_lim_cur_interval, fnmo);
	if (-1 == kevent(fnmo->kfnm->fd, &kev, 1, NULL, 0, NULL)) {
		fnmo->rate_lim_cur_interval = 0;
		return (errno);
	}
	if (0 != (EV_ERROR & kev.flags)) {
		fnmo->rate_lim_cur_interval = 0;
		return ((int)kev.data);
	}
	return (0);
}

/* Return:
 * 0 for events that not handled
 * 1 for handled = rate limited
 * -1 on error.
 */
static int
kq_fnmo_rate_lim_check(kq_fnmo_p fnmo) {
	sbintime_t sbt, sbt_now;
	struct timespec ts;

	if (NULL == fnmo)
		return (-1);
	if (-1 == fnmo->fd ||
	    0 == fnmo->kfnm->s.rate_limit_time_init)
		return (0);
	if (0 != fnmo->rate_lim_cur_interval) {
		fnmo->rate_lim_ev_cnt ++; /* Count event, timer is active. */
		return (1);
	}

	/* Do we need to enable rate limit? */
	if (0 != clock_gettime(CLOCK_MONOTONIC_FAST, &ts))
		return (-1);
	sbt_now = tstosbt(ts);
	sbt = (fnmo->rate_lim_ev_last + fnmo->kfnm->rate_lim_time_init);
	fnmo->rate_lim_ev_last = sbt_now;
	if (sbt < sbt_now) /* Events rate to low. */
		return (0);
	/* Try to enable rate limit. */
	if (0 != kq_fnmo_rate_lim_shedule_next(fnmo))
		return (-1);
	/* Ok. */
	fnmo->rate_lim_ev_cnt ++;

	return (1);
}

static void
kq_fnmo_clean(kq_fnmo_p fnmo) {

	if (NULL == fnmo)
		return;

	kq_fnmo_rate_lim_stop(fnmo);
	if (-1 != fnmo->fd) {
		close(fnmo->fd);
		fnmo->fd = -1;
	}
	fnmo->is_removed ++;

	/* Stop monitoring files/dirs. */
	file_info_fd_close(fnmo->files, fnmo->files_count);
	free(fnmo->files);
	fnmo->files = NULL;
	fnmo->files_count = 0;
	fnmo->files_allocated = 0;
}

static void
kq_fnmo_free(kq_fnmo_p fnmo) {

	if (NULL == fnmo)
		return;

	kq_fnmo_clean(fnmo);

	if (0 != fnmo->is_cached &&
	    NULL != fnmo->kfnm &&
	    g_hash_table_lookup(fnmo->kfnm->fnmo_cache, fnmo->path) == fnmo) {
		g_hash_table_remove(fnmo->kfnm->fnmo_cache, fnmo->path);
	}
	free(fnmo);
}

static kq_fnmo_p
kq_fnmo_alloc(kq_fnm_p kfnm, const char *path, kq_fnme_p fnme) {
	kq_fnmo_p fnmo;

	if (NULL == kfnm || NULL == path)
		return (NULL);
	fnmo = zalloc(sizeof(kq_fnmo_t));
	if (NULL == fnmo)
		return (NULL);
	fnmo->fd = -1;
	/* Remember args. */
	fnmo->path_size = strlcpy(fnmo->path, path, PATH_MAX);
	/* Make sure that no trailing '/'. */
	while (1 < fnmo->path_size && '/' == fnmo->path[(fnmo->path_size - 1)]) {
		fnmo->path_size --;
		fnmo->path[fnmo->path_size] = 0;
	}
	/* Get parent folder name. */
	fnmo->name_offset = fnmo->path_size;
	while (0 < fnmo->name_offset && '/' != fnmo->path[(fnmo->name_offset - 1)]) {
		fnmo->name_offset --;
	}
	fnmo->kfnm = kfnm;
	TAILQ_INIT(&fnmo->entry_head);
	if (NULL != fnme) {
		TAILQ_INSERT_HEAD(&fnmo->entry_head, fnme, next);
	}

	return (fnmo);
}

static void
kq_fnmo_cb_func_call(kq_fnmo_p fnmo, uint32_t event,
    const char *base, const char *filename, const char *new_filename) {
	kq_fnm_p kfnm;
	kq_fnme_p fnme;

	if (NULL == fnmo)
		return;
	kfnm = fnmo->kfnm;
	TAILQ_FOREACH(fnme, &fnmo->entry_head, next) {
		if (0 == fnme->enabled) /* XXX: try lock here? */
			continue;
		kfnm->cb_func(kfnm, fnme, fnme->udata, event,
		    base, filename, new_filename);
	}

}

static int
kq_fnmo_readdir(kq_fnmo_p fnmo, size_t exp_count) {
	int error;
	struct dirent *de;
	file_info_p tmfi;
	readdir_ctx_t rdd;

	if (NULL == fnmo || -1 == fnmo->fd || 0 == fnmo->is_dir)
		return (EINVAL);

	free(fnmo->files);
	fnmo->files = NULL;
	fnmo->files_count = 0;
	fnmo->files_allocated = 0;
	/* Pre allocate. */
	if (0 != realloc_items((void**)&fnmo->files,
	    sizeof(file_info_t), &fnmo->files_allocated,
	    FILES_ALLOC_BLK_SIZE, (exp_count + 1)))
		return (ENOMEM);

	error = readdir_start(fnmo->fd, &fnmo->sb, exp_count, &rdd);
	if (0 != error)
		return (error);
	for (;;) {
		if (0 != realloc_items((void**)&fnmo->files,
		    sizeof(file_info_t), &fnmo->files_allocated,
		    FILES_ALLOC_BLK_SIZE, fnmo->files_count)) {
			free(fnmo->files);
			fnmo->files = NULL;
			fnmo->files_count = 0;
			fnmo->files_allocated = 0;
			readdir_free(&rdd); /* Force cleanup here. */
			return (ENOMEM);
		}
		de = &fnmo->files[fnmo->files_count].de; /* Use short name. */
		/* Get file name from folder. */
		if (0 != readdir_next(&rdd, de))
			break;
		/* Get file attrs. */
		if (0 != fstatat(fnmo->fd, de->d_name,
		    &fnmo->files[fnmo->files_count].sb,
		    AT_SYMLINK_NOFOLLOW)) {
			if (ENOENT == errno)
				continue; /* File deleted. */
			memset(&fnmo->files[fnmo->files_count].sb, 0x00,
			    sizeof(struct stat));
		}
		fnmo->files[fnmo->files_count].fd = -1;
		fnmo->files_count ++;
	}

	/* Mem compact. */
	tmfi = reallocarray(fnmo->files, sizeof(file_info_t), (fnmo->files_count + 1));
	if (NULL != tmfi) { /* realloc ok. */
		fnmo->files = tmfi;
		fnmo->files_allocated = (fnmo->files_count + 1);
	}

	return (0); /* OK. */
}


static void
kq_fnmo_fi_start(kq_fnmo_p fnmo, file_info_p fi) {
	struct kevent kev;

	if (NULL == fnmo || -1 == fnmo->fd || NULL == fi)
		return;
	/* Filter files that can not be monitored, redice openat() calls. */
	switch (fi->de.d_type) {
	case DT_FIFO:
	case DT_SOCK:
#ifdef DT_WHT
	case DT_WHT:
#endif
		return;
	}
	fi->fd = openat(fnmo->fd, fi->de.d_name, OPEN_FILE_MON_FLAGS);
	if (-1 == fi->fd)
		return;
	EV_SET(&kev, fi->fd, EVFILT_VNODE,
	    (EV_ADD | EV_CLEAR),
	    EVFILT_VNODE_SUB_FLAGS, 0, fnmo);
	if (-1 == kevent(fnmo->kfnm->fd, &kev, 1, NULL, 0, NULL)) {
		close(fi->fd);
		fi->fd = -1;
	}
}

static int
kq_fnmo_is_fi_monitored(kq_fnmo_p fnmo, file_info_p fi) {

	if (NULL == fnmo)
		return (0);
	if (0 == fnmo->is_local ||
	    (0 != fnmo->kfnm->s.max_dir_files &&
	     fnmo->kfnm->s.max_dir_files < fnmo->files_count))
		return (0);
	if (NULL != fi &&
	    0 == fnmo->kfnm->s.mon_local_subdirs &&
	    S_ISDIR(fi->sb.st_mode))
		return (0);
	return (1);
}

static int
kq_fnmo_reopen_fd(kq_fnmo_p fnmo) {
	int error, fd;
	struct statfs stfs;
	struct kevent kev;

	if (NULL == fnmo)
		return (EINVAL);

	/* Close fd and stop timer. */
	kq_fnmo_rate_lim_stop(fnmo);
	if (-1 != fnmo->fd) {
		close(fnmo->fd);
		fnmo->fd = -1;
	}

	fd = open(fnmo->path, (OPEN_FILE_MON_FLAGS | O_DIRECTORY));
	if (-1 == fd)
		return (errno);
	if (0 != fstat(fd, &fnmo->sb)) {
		error = errno;
		goto err_out;
	}
	if (0 == fnmo->sb.st_nlink) {
		error = ENOENT;
		goto err_out;
	}
	if (S_ISDIR(fnmo->sb.st_mode)) {
		fnmo->is_dir = 1;
		/* Is file system local? */
		if (0 != fnmo->kfnm->s.mon_local_subfiles &&
		    0 == fstatfs(fd, &stfs)) {
			fnmo->is_local = is_fs_local(&stfs, fnmo->kfnm->s.local_fs,
			    fnmo->kfnm->s.non_local_fs);
		}
	}

	/* Add to kqueue. */
	EV_SET(&kev, fd, EVFILT_VNODE, (EV_ADD | EV_CLEAR),
	    EVFILT_VNODE_FLAGS_ALL, 0, fnmo);
	if (-1 == kevent(fnmo->kfnm->fd, &kev, 1, NULL, 0, NULL) ||
	    0 != (EV_ERROR & kev.flags)) {
		error = errno;
		goto err_out;
	}

	fnmo->is_removed = 0;
	fnmo->fd = fd;

	return (0); /* OK. */

err_out:
	close(fd);
	return (error);
}

static int
kq_fnmo_init(kq_fnmo_p fnmo) {
	int error;
	size_t i;

	if (NULL == fnmo)
		return (EINVAL);

	error = kq_fnmo_reopen_fd(fnmo);
	if (0 != error)
		goto err_out;

	if (0 == fnmo->is_dir)
		return (0); /* OK. */
	/* Dir special processing. */

	/* Read and remember dir content. */
	error = kq_fnmo_readdir(fnmo, 0);
	if (0 != error)
		goto err_out;
	/* Add monitor sub files/dirs, ignory errors. */
	/* Check twice for performance reason. */
	if (0 != kq_fnmo_is_fi_monitored(fnmo, NULL)) {
		for (i = 0; i < fnmo->files_count; i ++) {
			if (0 != kq_fnmo_is_fi_monitored(fnmo, &fnmo->files[i])) {
				kq_fnmo_fi_start(fnmo, &fnmo->files[i]);
			}
		}
	}

	return (0); /* OK. */

err_out:
	kq_fnmo_clean(fnmo);
	return (error);
}

static void
kq_fnme_init_cb(void *arg) {
	kq_fnme_p fnme = arg;
	kq_fnmo_p fnmo;
	kq_fnm_p kfnm;

	if (NULL == fnme || NULL == fnme->fnmo)
		return;
	kfnm = fnme->fnmo->kfnm;
	/* Is in cache? */
	fnmo = g_hash_table_lookup(kfnm->fnmo_cache, fnme->fnmo->path);
	if (NULL == fnmo) {
		/* Init and add to cache. */
		g_hash_table_insert(kfnm->fnmo_cache,
		    fnme->fnmo->path, fnme->fnmo);
		fnme->fnmo->is_cached ++;
		kq_fnmo_init(fnme->fnmo);
		return;
	}
	/* Found in cache, use it. */
	TAILQ_REMOVE(&fnme->fnmo->entry_head, fnme, next);
	kq_fnmo_free(fnme->fnmo);
	fnme->fnmo = fnmo;
	TAILQ_INSERT_HEAD(&fnmo->entry_head, fnme, next);
	if (-1 == fnmo->fd) {
		/* Re init existing, no notify. */
		kq_fnmo_init(fnme->fnmo);	
	}
}

static void
kq_fnme_free(kq_fnme_p fnme) {

	if (NULL == fnme)
		return;
	if (NULL != fnme->fnmo) {
		TAILQ_REMOVE(&fnme->fnmo->entry_head, fnme, next);
		if (TAILQ_EMPTY(&fnme->fnmo->entry_head)) {
			kq_fnmo_free(fnme->fnmo);
		}
	}
	free(fnme);
}

static void
kq_fnme_free_cb(void *arg) {

	kq_fnme_free((kq_fnme_p)arg);
}


static void
kq_handle_notify_removed(kq_fnmo_p fnmo) {
	size_t i;

	if (NULL == fnmo || 0 != fnmo->is_removed)
		return;

	if (0 != fnmo->is_dir) {
		/* Notify removed files first. */
		for (i = 0; i < fnmo->files_count; i ++) {
			kq_fnmo_cb_func_call(fnmo, KF_EVENT_DELETED,
			    fnmo->path, fnmo->files[i].de.d_name, NULL);
		}
	}
	fnmo->path[fnmo->name_offset - 1] = 0;
	kq_fnmo_cb_func_call(fnmo, KF_EVENT_DELETED, fnmo->path,
	    (fnmo->path + fnmo->name_offset), NULL);
	fnmo->path[fnmo->name_offset - 1] = '/';
	kq_fnmo_clean(fnmo);
}

static void
kq_handle_changes(kq_fnmo_p fnmo) {
	size_t i, k, files_count;
	file_info_p files;

	if (NULL == fnmo || -1 == fnmo->fd)
		return;
	if (0 != fstat(fnmo->fd, &fnmo->sb) ||
	    0 == fnmo->sb.st_nlink) {
		kq_handle_notify_removed(fnmo);
		return;
	}
	if (0 == fnmo->is_dir) {
		fnmo->path[fnmo->name_offset - 1] = 0;
		kq_fnmo_cb_func_call(fnmo, KF_EVENT_CHANGED, fnmo->path,
		    (fnmo->path + fnmo->name_offset), NULL);
		fnmo->path[fnmo->name_offset - 1] = '/';
		return;
	}

	/* Dir processing. */

	/* Save prev. */
	files = fnmo->files;
	files_count = fnmo->files_count;
	fnmo->files = NULL;
	fnmo->files_count = 0;
	/* Update dir. */
	if (0 != kq_fnmo_readdir(fnmo, files_count)) {
		/* Restore prev state on fail. */
		fnmo->files = files;
		fnmo->files_count = files_count;
		return;
	}

	/* Notify removed first. */
	for (i = 0; i < files_count; i ++) {
		if (0 != file_info_find_ni(fnmo->files, fnmo->files_count,
		    &files[i], &k)) /* Deleted? */
			continue;
		if (-1 != files[i].fd) {
			close(files[i].fd);
			files[i].fd = -1;
		}
		kq_fnmo_cb_func_call(fnmo, KF_EVENT_DELETED, fnmo->path,
		    files[i].de.d_name, NULL);
	}
	/* Notify. */
	for (i = 0; i < fnmo->files_count; i ++) {
		/* Is new file/folder? */
		if (0 == file_info_find_ino(files, files_count, &fnmo->files[i], &k) &&
		    0 == file_info_find_name(files, files_count, &fnmo->files[i], &k)) { /* Add new. */
			/* Add monitor sub files/dirs, ignory errors. */
			if (0 != kq_fnmo_is_fi_monitored(fnmo, &fnmo->files[i])) {
				kq_fnmo_fi_start(fnmo, &fnmo->files[i]);
			}
			kq_fnmo_cb_func_call(fnmo, KF_EVENT_CREATED,
			    fnmo->path, fnmo->files[i].de.d_name, NULL);
			continue;
		}
		/* Keep file fd. */
		fnmo->files[i].fd = files[k].fd;
		files[k].fd = -1;
		/* Is renamed? */
		if (0 == IS_DE_NAME_EQ(&files[k].de, &fnmo->files[i].de)) {
			kq_fnmo_cb_func_call(fnmo, KF_EVENT_RENAMED,
			    fnmo->path, files[k].de.d_name,
			    fnmo->files[i].de.d_name);
			continue;
		}
		/* Is modified? */
		if (0 != memcmp(&fnmo->files[i].sb, &files[k].sb, sizeof(struct stat))) {
			kq_fnmo_cb_func_call(fnmo, KF_EVENT_CHANGED,
			    fnmo->path, fnmo->files[i].de.d_name, NULL);
			continue;
		}
		/* Not changed. */
	}

	/* Prevent FD leak die to race conditions.
	 * All fd must be -1, check this while debuging.
	 */
	file_info_fd_close(files, files_count);
	free(files);
}

static int
kq_handle_rename(kq_fnmo_p fnmo) {
	int error, up_dir_fd, found = 0;
	readdir_ctx_t rdd;
	struct dirent de;
	struct stat sb;
	char old_filename[(MAXNAMLEN + sizeof(void*))];
	size_t old_filename_size;

	if (NULL == fnmo || -1 == fnmo->fd)
		return (EINVAL);
	if (0 != fstat(fnmo->fd, &fnmo->sb) ||
	    0 == fnmo->sb.st_nlink) {
notify_removed_errno:
		error = errno;
notify_removed:
		kq_handle_notify_removed(fnmo);
		return (error);
	}
	/* Save old file name. */
	old_filename_size = (fnmo->path_size - fnmo->name_offset);
	memcpy(old_filename,
	    (fnmo->path + fnmo->name_offset),
	    old_filename_size);
	old_filename[old_filename_size] = 0;

	/* Get parent folder name. */
	fnmo->path[fnmo->name_offset] = 0;
	/* Try to open. */
	up_dir_fd = open(fnmo->path, (OPEN_FILE_MON_FLAGS | O_DIRECTORY));
	/* Restore '/' after parent folder. */
	fnmo->path[fnmo->name_offset] = '/';
	if (-1 == up_dir_fd)
		goto notify_removed_errno;
	error = readdir_start(up_dir_fd, NULL, 0, &rdd);
	if (0 != error) {
		close(up_dir_fd);
		goto notify_removed;
	}
	/* Find new name by inode. */
	while (0 == readdir_next(&rdd, &de)) {
		if (0 == fstatat(up_dir_fd, de.d_name, &sb, AT_SYMLINK_NOFOLLOW) &&
		    0 == memcmp(&fnmo->sb, &sb, sizeof(struct stat))) {
			readdir_free(&rdd); /* Force cleanup here. */
			found ++;
			break;
		}
	}
	close(up_dir_fd);
	if (0 == found) {
		error = ENOENT;
		goto notify_removed; /* Not found. */
	}
	/* Update name. */
	if (PATH_MAX < (fnmo->name_offset + de.d_namlen)) {
		error = EINVAL;
		goto notify_removed;
	}
	memcpy((fnmo->path + fnmo->name_offset), de.d_name, de.d_namlen);
	fnmo->path_size = (fnmo->name_offset + de.d_namlen);
	fnmo->path[fnmo->path_size] = 0;
	/* Notify. */
	kq_fnmo_cb_func_call(fnmo, KF_EVENT_RENAMED, fnmo->path,
	    old_filename, de.d_name);

	return (0);
}


static void
kq_fnm_delay_call_process(kq_fnm_p kfnm, kq_msg_cb forced_msg_cb) {
	ssize_t ios;
	kq_fnm_msg_pkt_t msg;

	for (;;) {
		ios = read(kfnm->pfd[0], &msg, sizeof(msg));
		if (0 >= ios)
			return;
		if (sizeof(msg) != ios ||
		    KF_MSG_PKT_MAGIC != msg.magic ||
		    (((size_t)msg.msg_cb) ^ ((size_t)msg.arg)) != msg.chk_sum)
			continue;
		if (NULL != forced_msg_cb) {
			forced_msg_cb(msg.arg);
			continue;
		}
		if (NULL == msg.msg_cb)
			continue;
		msg.msg_cb(msg.arg);
	}
}

static int
kq_fnm_delay_call(kq_fnm_p kfnm, kq_msg_cb msg_cb,
    void *arg) {
	kq_fnm_msg_pkt_t msg;

	if (NULL == kfnm || NULL == arg)
		return (EINVAL);
	msg.magic = KF_MSG_PKT_MAGIC;
	msg.msg_cb = msg_cb;
	msg.arg = arg;
	msg.chk_sum = (((size_t)msg.msg_cb) ^ ((size_t)msg.arg));
	if (sizeof(msg) == write(kfnm->pfd[1], &msg, sizeof(msg)))
		return (0);
	return (errno);
}


static void
kq_fnm_free_cb(void *arg) {
	kq_fnm_p kfnm = arg;

	if (NULL == kfnm)
		return;
	close(kfnm->fd);
	kfnm->fd = -1;
}
void
kq_fnm_free(kq_fnm_p kfnm) {
	GHashTableIter iter;
	gpointer key;
	kq_fnmo_p fnmo;
	kq_fnme_p fnme, fnme_temp;

	if (NULL == kfnm)
		return;
	kq_fnm_delay_call(kfnm, kq_fnm_free_cb, kfnm);
	pthread_join(kfnm->tid, NULL);
	/* Free all in delay calls queue. */
	close(kfnm->pfd[1]);
	kq_fnm_delay_call_process(kfnm, kq_fnme_free_cb);
	close(kfnm->pfd[0]);
	/* Remove all objects. */
	g_hash_table_iter_init(&iter, kfnm->fnmo_cache);
	while (g_hash_table_iter_next(&iter, &key, (gpointer)&fnmo)) {
		TAILQ_FOREACH_SAFE(fnme, &fnmo->entry_head, next, fnme_temp) {
			TAILQ_REMOVE(&fnmo->entry_head, fnme, next);
			fnme->fnmo = NULL; /* Do not free fnmo here. */
			kq_fnme_free(fnme);
		}
		g_hash_table_iter_remove(&iter); /* Remove from cache here. */
		/* Prevent remove from cache or g_hash_table_iter_next() will fail. */
		fnmo->is_cached = 0;
		kq_fnmo_free(fnmo);
	}
	g_hash_table_destroy(kfnm->fnmo_cache);

	free(kfnm->mounts);
	free(kfnm);
}

kq_fnm_p
kq_fnm_create(kq_file_mon_settings_p s, kfnm_event_handler_cb cb_func) {
	kq_fnm_p kfnm;
	struct kevent kev;

	if (NULL == s || NULL == cb_func)
		return (NULL);
	kfnm = zalloc(sizeof(kq_fnm_t));
	if (NULL == kfnm)
		return (NULL);
	kfnm->fd = kqueue();
	if (-1 == kfnm->fd)
		goto err_out;
	if (-1 == pipe2(kfnm->pfd, O_NONBLOCK))
		goto err_out;
	kfnm->fnmo_cache = g_hash_table_new(g_str_hash, g_str_equal);
	kfnm->cb_func = cb_func;
	memcpy(&kfnm->s, s, sizeof(kq_file_mon_settings_t));
	if (kfnm->s.rate_limit_time_init >= kfnm->s.rate_limit_time_max) {
		kfnm->s.rate_limit_time_max = kfnm->s.rate_limit_time_init;
	}
	if (0 == kfnm->s.rate_limit_time_mul) {
		kfnm->s.rate_limit_time_mul ++;
	}
	kfnm->rate_lim_time_init = MSTOSBT(kfnm->s.rate_limit_time_init);

	EV_SET(&kev, kfnm->pfd[0], EVFILT_READ, EV_ADD, 0, 0, NULL);
	if (-1 == kevent(kfnm->fd, &kev, 1, NULL, 0, NULL) ||
	    0 != (EV_ERROR & kev.flags))
		goto err_out;
	EV_SET(&kev, 0, EVFILT_FS, EV_ADD, 0, 0, NULL);
	if (-1 == kevent(kfnm->fd, &kev, 1, NULL, 0, NULL) ||
	    0 != (EV_ERROR & kev.flags))
		goto err_out;
	/* Get initial mounts points. */
	kfnm->mounts_count = (size_t)getmntinfo_ex(&kfnm->mounts, MNT_WAIT);

	if (0 != pthread_create(&kfnm->tid, NULL,
	    kq_fnm_proccess_events_proc, kfnm))
		goto err_out;

	return (kfnm);

err_out:
	kq_fnm_free(kfnm);
	return (NULL);
}

kq_fnme_p
kq_fnm_add(kq_fnm_p kfnm, const char *path, void *udata) {
	int error;
	kq_fnme_p fnme;

	if (NULL == kfnm || NULL == path)
		return (NULL);
	fnme = zalloc(sizeof(kq_fnme_t));
	if (NULL == fnme)
		return (NULL);
	fnme->fnmo = kq_fnmo_alloc(kfnm, path, fnme);
	if (NULL == fnme->fnmo)
		goto err_out;
	fnme->udata = udata;
	fnme->enabled = 1;
	/* Shedule delay call to init. */
	error = kq_fnm_delay_call(kfnm, kq_fnme_init_cb, fnme);
	if (0 != error) { /* Error, do no directly init to avoid freezes. */
		kq_fnmo_free(fnme->fnmo);
err_out:
		fnme->fnmo = NULL;
		kq_fnme_free(fnme);
		return (NULL);
	}
	return (fnme);
}

void
kq_fnm_del(kq_fnm_p kfnm, kq_fnme_p fnme) {
	int error;

	if (NULL == kfnm || NULL == fnme)
		return;
	/* Cancel notifications. */
	/* XXX: lock here? */
	fnme->enabled = 0;
	/* Shedule delay call to free. */
	error = kq_fnm_delay_call(kfnm, kq_fnme_free_cb, fnme);
	if (0 == error)
		return;
	/* Error, free directly. */
	kq_fnme_free(fnme);
}


static void
kq_fnm_handle_mnt_point_change(kq_fnm_p kfnm, const char *mntonname) {
	int error;
	GHashTableIter iter;
	gpointer key;
	kq_fnmo_p fnmo;
	size_t mntonname_size;

	if (NULL == kfnm || NULL == mntonname || 0 == mntonname[0])
		return;
	mntonname_size = strnlen(mntonname, MNAMELEN);
	/* Remove all objects. */
	g_hash_table_iter_init(&iter, kfnm->fnmo_cache);
	while (g_hash_table_iter_next(&iter, &key, (gpointer)&fnmo)) {
		if (NULL == fnmo || -1 == fnmo->fd) /* Do not reopen deleted. */
			continue;
		if (mntonname_size > fnmo->path_size)
			continue;
		if (0 != memcmp(fnmo->path, mntonname, mntonname_size))
			continue;
		/* Try to reopen mount point after unmount. */
		error = kq_fnmo_reopen_fd(fnmo);
		if (0 != error) {
			kq_handle_notify_removed(fnmo);
			continue;
		}
		/* Reread dir and notify about deleted and new files. */
		kq_handle_changes(fnmo);
	}
}
static void
kq_handle_mount_changes(kq_fnm_p kfnm) {
	size_t i, mounts_count;
	struct statfs *mounts;

	if (NULL == kfnm)
		return;

	/* Save prev. */
	mounts = kfnm->mounts;
	mounts_count = kfnm->mounts_count;
	kfnm->mounts = NULL;
	kfnm->mounts_count = (size_t)getmntinfo_ex(&kfnm->mounts, MNT_WAIT);

	/* Removed mounts. */
	for (i = 0; i < mounts_count; i ++) {
		if (0 != mounts_find_name(kfnm->mounts, kfnm->mounts_count,
		    mounts[i].f_mntonname))
			continue;
		kq_fnm_handle_mnt_point_change(kfnm, mounts[i].f_mntonname);
	}
	/* New mounts. */
	for (i = 0; i < kfnm->mounts_count; i ++) {
		if (0 != mounts_find_name(mounts, mounts_count,
		    kfnm->mounts[i].f_mntonname))
			continue;
		kq_fnm_handle_mnt_point_change(kfnm, kfnm->mounts[i].f_mntonname);
	}

	/* Free old mounts. */
	free(mounts);
}


static void
kq_fnm_proccess_event(kq_fnm_p kfnm, struct kevent *kev) {
	int error;
	kq_fnmo_p fnmo;
	file_info_p fi;
	size_t i;
	int is_rate_lim_checked = 0;
	struct stat sb;

	if (NULL == kfnm || NULL == kev)
		return;

	/* Handle delay calls. */
	if (kev->ident == (uintptr_t)kfnm->pfd[0]) {
		if (EVFILT_READ == kev->filter) {
			kq_fnm_delay_call_process(kfnm, NULL);
		}
		return;
	}

	/* Handle mount/unmount events. */
	if (EVFILT_FS == kev->filter) {
		kq_handle_mount_changes(kfnm);
		return;
	}

	if (0 == kev->udata)
		return; /* No associated data, skip. */
	fnmo = (kq_fnmo_p)kev->udata;

	/* FS delayed notifications. */
	if (EVFILT_TIMER == kev->filter) {
		if (0 == fnmo->rate_lim_ev_cnt) {
			/* No delayed events, disable rate limit polling. */
			kq_fnmo_rate_lim_stop(fnmo);
			return;
		}
		fnmo->rate_lim_ev_cnt = 0; /* Reset counter. */
		kq_fnmo_rate_lim_shedule_next(fnmo);
		kq_handle_changes(fnmo);
		return;
	}

	/* FS notifications. */
	if (EVFILT_VNODE != kev->filter)
		return; /* Unknown event, skip. */
	/* Subdir/file */
	if (kev->ident != (uintptr_t)fnmo->fd) {
		/* Is files changes rate limited? */
		if (1 == kq_fnmo_rate_lim_check(fnmo))
			return;
		is_rate_lim_checked ++;
		/* Try to find file and check it, without call kq_handle_changes(). */
		fi = NULL;
		for (i = 0; i < fnmo->files_count; i ++) {
			if (kev->ident != (uintptr_t)fnmo->files[i].fd)
				continue;
			fi = &fnmo->files[i];
			break;
		}
		if (NULL != fi) {
			/* Get file attrs. */
			if (0 != fstat(fi->fd, &sb)) {
				memset(&sb, 0x00, sizeof(struct stat));
			}
			/* Is modified? */
			if (0 != memcmp(&fi->sb, &sb, sizeof(struct stat))) {
				memcpy(&fi->sb, &sb, sizeof(struct stat));
				kq_fnmo_cb_func_call(fnmo, KF_EVENT_CHANGED,
				    fnmo->path, fi->de.d_name, NULL);
				return;
			}
		}
		/* fd not found or changes not found, rescan dir. */
		kev->fflags = NOTE_WRITE;
	}
	/* Monitored object. */
	/* All flags from EVFILT_VNODE_FLAGS_ALL must be handled here. */
	if (EV_ERROR & kev->flags) {
		kev->fflags |= NOTE_REVOKE; /* Treat error as unmount. */
	}
	if ((NOTE_DELETE | NOTE_REVOKE) & kev->fflags) {
		/* No ratelimit here. */
		if (0 != fnmo->is_dir) {
			/* Try to reopen mount point after unmount. */
			error = kq_fnmo_reopen_fd(fnmo);
			if (0 == error) {
				/* This will reread dir and notify about
				 * deleted and new files. */
				kq_handle_changes(fnmo);
			}
		} else {
			error = -1;
		}
		if (0 != error) {
			kq_handle_notify_removed(fnmo);
		}
		return; /* All events processed. */
	}
	if (NOTE_RENAME & kev->fflags) {
		error = kq_handle_rename(fnmo);
		if (0 != error)
			return;
	}
	if ((NOTE_WRITE | NOTE_EXTEND | NOTE_ATTRIB | NOTE_LINK | NOTE_CLOSE_WRITE) & kev->fflags) {
		if (0 == is_rate_lim_checked &&
		    1 != kq_fnmo_rate_lim_check(fnmo)) {
			kq_handle_changes(fnmo);
		}
	}
}

void *
kq_fnm_proccess_events_proc(void *data) {
	struct kevent kev;
	kq_fnm_p kfnm = data;

	if (NULL == kfnm)
		return (NULL);
	/* Get and proccess events, no wait. */
	while (0 < kevent(kfnm->fd, NULL, 0, &kev, 1, NULL)) {
		kq_fnm_proccess_event(kfnm, &kev);
	}
	return (NULL);
}
