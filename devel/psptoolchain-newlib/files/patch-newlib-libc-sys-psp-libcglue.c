--- newlib/libc/sys/psp/libcglue.c.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/libcglue.c	2007-06-01 12:22:26.000000000 +0300
@@ -0,0 +1,936 @@
+/*
+ * PSP Software Development Kit - http://www.pspdev.org
+ * -----------------------------------------------------------------------
+ * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
+ *
+ * libcglue.c - Newlib-compatible system calls.
+ *
+ * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
+ * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
+ * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
+ * Copyright (c) 2005 Jim Paris <jim@jtan.com>
+ * 
+ */
+#include <errno.h>
+#include <malloc.h>
+#include <reent.h>
+#include <stdarg.h>
+#include <stdlib.h>
+#include <string.h>
+#include <time.h>
+#include <sys/fcntl.h>
+#include <sys/stat.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#include <sys/unistd.h>
+#include <sys/dirent.h>
+#include <sys/socket.h>
+
+#include <psptypes.h>
+#include <pspiofilemgr.h>
+#include <pspmodulemgr.h>
+#include <pspsysmem.h>
+#include <pspthreadman.h>
+#include <psputils.h>
+#include <psputility.h>
+#include <pspstdio.h>
+#include <pspintrman.h>
+#include "fdman.h"
+
+extern char __psp_cwd[MAXPATHLEN + 1];
+extern void __psp_init_cwd(char *argv_0);
+extern int __psp_path_absolute(const char *in, char *out, int len);
+extern int  pspDisableInterrupts();
+extern void pspEnableInterrupts(int); 
+
+/* The following functions are defined in socket.c.  They have weak linkage so
+   that the user doesn't have to link against the PSP network libraries if they
+   don't use the sockets API. */
+extern int __psp_socket_close(int s) __attribute__((weak));
+extern ssize_t __psp_socket_recv(int s, void *buf, size_t len, int flags) __attribute__((weak));
+extern ssize_t __psp_socket_send(int s, const void *buf, size_t len, int flags) __attribute__((weak));
+
+extern int pipe(int fildes[2]);
+extern int __psp_pipe_close(int filedes);
+extern int __psp_pipe_nonblocking_read(int fd, void *buf, size_t len);
+extern int __psp_pipe_read(int fd, void *buf, size_t len);
+extern int __psp_pipe_write(int fd, const void *buf, size_t size);
+extern int __psp_pipe_nonblocking_write(int fd, const void *buf, size_t len);
+
+int __psp_set_errno(int code);
+
+#ifdef F___psp_set_errno
+int __psp_set_errno(int code)
+{
+	if ((code & 0x80010000) == 0x80010000) {
+		errno = code & 0xFFFF;
+		return -1;
+	}
+	return code;
+}
+#endif
+
+#ifdef F_getcwd
+char *getcwd(char *buf, size_t size)
+{
+	if(!buf) {
+		errno = EINVAL;
+		return NULL;
+	}		
+
+	if(strlen(__psp_cwd) >= size) {
+		errno = ERANGE;
+		return NULL;
+	}
+
+	strcpy(buf, __psp_cwd);
+	return buf;
+}
+#endif
+
+#ifdef F_chdir
+int chdir(const char *path)
+{
+	char dest[MAXPATHLEN + 1];
+	SceUID uid;
+
+	if(__psp_path_absolute(path, dest, MAXPATHLEN) < 0) {
+		errno = ENAMETOOLONG;
+		return -1;
+	}
+
+	/* sceIoChdir doesn't give an indication of whether it worked,
+	   so test for existence by attempting to open the dir */
+	uid = sceIoDopen(dest);
+	if(uid < 0) {
+		errno = ENOTDIR;
+		return -1;
+	}
+	sceIoDclose(uid);
+
+	sceIoChdir(dest);
+	strcpy(__psp_cwd, dest);
+	return 0;
+}
+#endif
+
+#ifdef F_mkdir
+int mkdir(const char *pathname, mode_t mode)
+{
+	char dest[MAXPATHLEN + 1];
+
+	if(__psp_path_absolute(pathname, dest, MAXPATHLEN) < 0) {
+		errno = ENAMETOOLONG;
+		return -1;
+	}
+
+	return __psp_set_errno(sceIoMkdir(dest, mode));
+}
+#endif
+
+#ifdef F_rmdir
+int rmdir(const char *pathname)
+{
+	char dest[MAXPATHLEN + 1];
+
+	if(__psp_path_absolute(pathname, dest, MAXPATHLEN) < 0) {
+		errno = ENAMETOOLONG;
+		return -1;
+	}
+
+	return __psp_set_errno(sceIoRmdir(dest));
+}
+#endif
+
+#ifdef F_realpath
+char *realpath(const char *path, char *resolved_path)
+{
+	if(!path || !resolved_path) {
+		errno = EINVAL;
+		return NULL;
+	}
+	if(__psp_path_absolute(path, resolved_path, MAXPATHLEN) < 0) {
+		errno = ENAMETOOLONG;
+		return NULL;
+	}
+	if(access(resolved_path, F_OK) < 0) {
+		errno = ENOENT;
+		return NULL;
+	}
+	return resolved_path;
+}
+#endif
+
+/* Wrappers of the standard open(), close(), read(), write(), unlink() and lseek() routines. */
+#ifdef F__open
+int _open(const char *name, int flags, int mode)
+{
+	int scefd, fd;
+	int sce_flags;
+	char dest[MAXPATHLEN + 1];
+
+	if(__psp_path_absolute(name, dest, MAXPATHLEN) < 0) {
+		errno = ENAMETOOLONG;
+		return -1;
+	}
+
+	/* O_RDONLY starts at 0, where PSP_O_RDONLY starts at 1, so remap the read/write
+	   flags by adding 1. */
+	sce_flags = (flags & O_ACCMODE) + 1;
+
+	/* Translate standard open flags into the flags understood by the PSP kernel. */
+	if (flags & O_APPEND) {
+		sce_flags |= PSP_O_APPEND;
+	}
+	if (flags & O_CREAT) {
+		sce_flags |= PSP_O_CREAT;
+	}
+	if (flags & O_TRUNC) {
+		sce_flags |= PSP_O_TRUNC;
+	}
+	if (flags & O_EXCL) {
+		sce_flags |= PSP_O_EXCL;
+	}
+	if (flags & O_NONBLOCK) {
+		sce_flags |= PSP_O_NBLOCK;
+	}
+	
+	scefd = sceIoOpen(dest, sce_flags, mode);
+	if (scefd >= 0) {
+		fd = __psp_fdman_get_new_descriptor();
+		if (fd != -1) {
+			__psp_descriptormap[fd]->sce_descriptor = scefd;
+			__psp_descriptormap[fd]->type     		= __PSP_DESCRIPTOR_TYPE_FILE;
+			__psp_descriptormap[fd]->flags    		= flags;
+			__psp_descriptormap[fd]->filename 		= strdup(dest);
+			return fd;
+		}
+		else {
+			sceIoClose(scefd);
+			errno = ENOMEM;
+			return -1;
+		}
+	} 
+	else {
+		return __psp_set_errno(scefd);
+	}
+	
+}
+#endif
+
+#ifdef F__close
+int _close(int fd)
+{
+	int ret = 0;
+
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	switch(__psp_descriptormap[fd]->type)
+	{
+		case __PSP_DESCRIPTOR_TYPE_FILE:
+		case __PSP_DESCRIPTOR_TYPE_TTY:
+			if (__psp_descriptormap[fd]->ref_count == 1) {
+				ret = __psp_set_errno(sceIoClose(__psp_descriptormap[fd]->sce_descriptor));
+			}
+			__psp_fdman_release_descriptor(fd);
+			return ret;
+			break;
+		case __PSP_DESCRIPTOR_TYPE_PIPE:
+			return __psp_pipe_close(fd);
+			break;
+		case __PSP_DESCRIPTOR_TYPE_SOCKET:
+			if (__psp_socket_close != NULL) {
+				ret = __psp_socket_close(fd);
+				return ret;
+			}
+			break;
+		default:
+			break;
+	}
+
+	errno = EBADF;
+	return -1;
+}
+#endif
+
+#ifdef F__read
+int _read(int fd, void *buf, size_t size)
+{
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	switch(__psp_descriptormap[fd]->type)
+	{
+		case __PSP_DESCRIPTOR_TYPE_FILE:
+		case __PSP_DESCRIPTOR_TYPE_TTY:
+			return __psp_set_errno(sceIoRead(__psp_descriptormap[fd]->sce_descriptor, buf, size));
+			break;
+		case __PSP_DESCRIPTOR_TYPE_PIPE:
+			if (__psp_descriptormap[fd]->flags & O_NONBLOCK) {
+				return __psp_pipe_nonblocking_read(fd, buf, size);
+			}
+			else {
+				return __psp_pipe_read(fd, buf, size);
+			}
+			break;
+		case __PSP_DESCRIPTOR_TYPE_SOCKET:
+			if (__psp_socket_recv != NULL) {
+				return __psp_socket_recv(fd, buf, size, 0);
+			}
+			break;
+		default:
+			break;
+	}
+
+	errno = EBADF;
+	return -1;
+
+}
+#endif
+
+#ifdef F__write
+int _write(int fd, const void *buf, size_t size)
+{
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	switch(__psp_descriptormap[fd]->type)
+	{
+		case __PSP_DESCRIPTOR_TYPE_FILE:
+		case __PSP_DESCRIPTOR_TYPE_TTY:
+			return __psp_set_errno(sceIoWrite(__psp_descriptormap[fd]->sce_descriptor, buf, size));
+			break;
+		case __PSP_DESCRIPTOR_TYPE_PIPE:
+			if (__psp_descriptormap[fd]->flags & O_NONBLOCK) {
+				return __psp_pipe_nonblocking_write(fd, buf, size);
+			}
+			else {
+				return __psp_pipe_write(fd, buf, size);
+			}
+			break;
+			break;
+		case __PSP_DESCRIPTOR_TYPE_SOCKET:
+			if (__psp_socket_send != NULL) {
+				return __psp_socket_send(fd, buf, size, 0);
+			}
+			break;
+		default:
+			break;
+	}
+
+	errno = EBADF;
+	return -1;
+}
+#endif
+
+#ifdef F__lseek
+off_t _lseek(int fd, off_t offset, int whence)
+{
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	switch(__psp_descriptormap[fd]->type)
+	{
+		case __PSP_DESCRIPTOR_TYPE_FILE:
+			/* We don't have to do anything with the whence argument because SEEK_* == PSP_SEEK_*. */
+			return (off_t) __psp_set_errno(sceIoLseek(__psp_descriptormap[fd]->sce_descriptor, offset, whence));
+			break;
+		case __PSP_DESCRIPTOR_TYPE_PIPE:
+			break;
+		case __PSP_DESCRIPTOR_TYPE_SOCKET:
+			break;
+		default:
+			break;
+	}
+
+	errno = EBADF;
+	return -1;
+
+}
+#endif
+
+#ifdef F__unlink
+int _unlink(const char *path)
+{
+	char dest[MAXPATHLEN + 1];
+
+	if(__psp_path_absolute(path, dest, MAXPATHLEN) < 0) {
+		errno = ENAMETOOLONG;
+		return -1;
+	}
+
+	return __psp_set_errno(sceIoRemove(dest));
+}
+#endif
+
+#ifdef F__link
+int _link(const char *name1, const char *name2)
+{
+	errno = ENOSYS;
+	return -1; /* not supported */
+}
+#endif
+
+#ifdef F_opendir
+DIR *opendir(const char *filename)
+{
+	char dest[MAXPATHLEN + 1];
+	DIR *dirp;
+	SceUID uid;
+
+	/* Normalize pathname so that opendir(".") works */
+	if(__psp_path_absolute(filename, dest, MAXPATHLEN) < 0) {
+		errno = ENOENT;
+		return NULL;
+	}
+
+	dirp = (DIR *)malloc(sizeof(DIR));
+
+	uid = sceIoDopen(dest);
+
+	if (uid < 0)
+	{
+		free(dirp);
+		(void) __psp_set_errno(uid);
+		return NULL;
+	}
+
+	dirp->uid = uid;
+
+	return dirp;
+}
+#endif
+
+#ifdef F_readdir
+struct dirent *readdir(DIR *dirp)
+{
+	int ret;
+
+	/* Zero the dirent, to avoid possible problems with sceIoDread */
+	memset(&dirp->de, 0, sizeof(struct dirent));
+
+	ret = sceIoDread(dirp->uid, (SceIoDirent *)&dirp->de);
+	if (ret == 0) {
+		/* EOF */
+		errno = 0;
+		return NULL;
+	}
+	if (ret < 0) {
+		(void) __psp_set_errno(ret);
+		return NULL;
+	}
+
+	return &dirp->de;
+}
+#endif
+
+#ifdef F_closedir
+int closedir(DIR *dirp)
+{
+	if (dirp != NULL)
+	{
+		int uid;
+		uid = dirp->uid;
+		free (dirp);
+		return __psp_set_errno(sceIoDclose(uid));
+	}
+	errno = EBADF;
+	return -1; 
+}
+#endif
+
+/* Time routines.  These wrap around the routines provided by the kernel. */
+#ifdef F__gettimeofday
+int _gettimeofday(struct timeval *tp, struct timezone *tzp)
+{
+	return __psp_set_errno(sceKernelLibcGettimeofday(tp, tzp));
+}
+
+#endif
+
+#if defined(F_clock)
+clock_t clock(void)
+{
+	return sceKernelLibcClock();
+}
+#endif
+
+#if defined(F_time)
+time_t time(time_t *t)
+{
+	return __psp_set_errno(sceKernelLibcTime(t));
+}
+#endif
+
+#if defined(F_sleep)
+unsigned int sleep(unsigned int secs) {
+	while(secs--) {	
+		sceKernelDelayThreadCB(1000000);
+	}
+	return 0;
+}
+#endif
+
+/* PSP-compatible sbrk(). */
+#if defined(F__sbrk) || defined(F_glue__sbrk)
+/* TODO: Currently our default heap is set to the maximum available block size
+   when sbrk() is first called.  Sony seems to always use a default of 64KB,
+   with the expectation that user programs will override the default size with
+   their own desired size.  The only reason I can think of them doing this is
+   to allow each PRX to have their own seperate heap.  I think that their
+   method is overkill for most user programs.
+
+   What I'd like to do instead is to use the default of 64KB for PRXes as Sony
+   does, but use the maximum available block size for executables.  This avoids
+   the requirement of specifying the heap size manually in user programs.
+   However, we currently don't have a clean way to distinguish PRXes and normal
+   executables, so this code needs to be revisited once we do come up with a
+   way. */
+#define DEFAULT_PRX_HEAP_SIZE_KB 64
+
+/* If defined it specifies the desired size of the heap, in KB. */
+extern unsigned int sce_newlib_heap_kb_size __attribute__((weak));
+extern int __pspsdk_is_prx __attribute__((weak));
+
+/* UID of the memory block that represents the heap. */
+static SceUID __psp_heap_blockid;
+
+void * _sbrk(ptrdiff_t incr)
+{
+	static void * heap_bottom = NULL;
+	static void * heap_top = NULL;
+	static void * heap_ptr = NULL;
+
+	/* Has our heap been initialized? */
+	if (heap_bottom == NULL) {
+		/* No, initialize the heap. */
+		SceSize heap_size;
+
+		if (&sce_newlib_heap_kb_size != NULL) {
+			heap_size = sce_newlib_heap_kb_size * 1024;
+		} else {
+			if (&__pspsdk_is_prx != NULL) {
+				heap_size = DEFAULT_PRX_HEAP_SIZE_KB * 1024;
+			} else {
+				heap_size = sceKernelMaxFreeMemSize();
+			}
+		}
+
+		__psp_heap_blockid = sceKernelAllocPartitionMemory(2, "block", PSP_SMEM_Low, heap_size, NULL);
+		if (__psp_heap_blockid > 0) {
+			heap_bottom = sceKernelGetBlockHeadAddr(__psp_heap_blockid);
+			heap_ptr = heap_bottom;
+			heap_top = (unsigned char *) heap_bottom + heap_size;
+		}
+	}
+
+	void * heap_addr = (void *) -1;
+	void * next_heap_ptr = (void *) ((ptrdiff_t) heap_ptr + incr);
+	if ((heap_bottom != NULL) && (next_heap_ptr >= heap_bottom) && (next_heap_ptr < heap_top)) {
+		heap_addr = heap_ptr;
+		heap_ptr = next_heap_ptr;
+	}
+
+	return heap_addr;
+}
+
+/* Free the heap. */
+int __psp_free_heap(void)
+{
+	if (__psp_heap_blockid > 0) {
+		return sceKernelFreePartitionMemory(__psp_heap_blockid);
+	}
+
+	return __psp_heap_blockid;
+}
+#endif
+
+/* Other POSIX routines that must be defined. */
+#ifdef F__fstat
+int _fstat(int fd, struct stat *sbuf)
+{
+	int ret;
+	SceOff oldpos;
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	switch(__psp_descriptormap[fd]->type)
+	{
+		case __PSP_DESCRIPTOR_TYPE_TTY:
+			memset(sbuf, '\0', sizeof(struct stat));
+			sbuf->st_mode = S_IFCHR;
+			return 0;
+			break;		
+		case __PSP_DESCRIPTOR_TYPE_FILE:
+			if (__psp_descriptormap[fd]->filename != NULL) {
+				ret = stat(__psp_descriptormap[fd]->filename, sbuf);
+				
+				/* Find true size of the open file */
+				oldpos = sceIoLseek(__psp_descriptormap[fd]->sce_descriptor, 0, SEEK_CUR);
+				if (oldpos != (off_t) -1) {
+					sbuf->st_size = (off_t) sceIoLseek(__psp_descriptormap[fd]->sce_descriptor, 0, SEEK_END);
+					sceIoLseek(__psp_descriptormap[fd]->sce_descriptor, oldpos, SEEK_SET);
+				}
+				return ret;
+			}
+			break;
+		case __PSP_DESCRIPTOR_TYPE_PIPE:
+		case __PSP_DESCRIPTOR_TYPE_SOCKET:
+		default:
+			break;
+	}
+
+	errno = EBADF;
+	return -1;
+}
+#endif
+
+#ifdef F_isatty
+int isatty(int fd)
+{
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return 0;
+	}
+
+	if (__psp_descriptormap[fd]->type == __PSP_DESCRIPTOR_TYPE_TTY) {
+		return 1;
+	}
+	else {
+		return 0;
+	}
+}
+#endif
+
+#ifdef F__stat
+static time_t psp_to_epoch_time(ScePspDateTime psp_time)
+{
+	struct tm conv_time;
+	conv_time.tm_year = psp_time.year;
+	conv_time.tm_mon = psp_time.month;
+	conv_time.tm_mday = psp_time.day;
+	conv_time.tm_hour = psp_time.hour;
+	conv_time.tm_min = psp_time.minute;
+	conv_time.tm_sec = psp_time.second;
+	conv_time.tm_isdst = -1;
+	return mktime(&conv_time);
+}
+
+int _stat(const char *filename, struct stat *buf)
+{
+	SceIoStat psp_stat;
+	char dest[MAXPATHLEN + 1];
+	int ret;
+
+	if(__psp_path_absolute(filename, dest, MAXPATHLEN) < 0) {
+		errno = ENAMETOOLONG;
+		return -1;
+	}
+
+	memset(buf, '\0', sizeof(struct stat));
+	ret = sceIoGetstat(dest, &psp_stat);
+	if (ret < 0) {
+		return __psp_set_errno(ret);
+	}
+	
+	buf->st_ctime = psp_to_epoch_time(psp_stat.st_ctime);
+	buf->st_atime = psp_to_epoch_time(psp_stat.st_atime);
+	buf->st_mtime = psp_to_epoch_time(psp_stat.st_mtime);
+
+	buf->st_mode = (psp_stat.st_mode & 0xfff) |
+		       ((FIO_S_ISLNK(psp_stat.st_mode))?(S_IFLNK):(0)) |
+		       ((FIO_S_ISREG(psp_stat.st_mode))?(S_IFREG):(0)) |
+		       ((FIO_S_ISDIR(psp_stat.st_mode))?(S_IFDIR):(0));
+	buf->st_size = psp_stat.st_size;
+	return 0;
+}
+#endif
+
+/* from stat.h in ps2sdk, this function may be correct */
+#define FIO_CST_SIZE	0x0004
+
+#ifdef F_truncate
+int truncate(const char *filename, off_t length)
+{
+	SceIoStat psp_stat;
+	char dest[MAXPATHLEN + 1];
+
+	if(__psp_path_absolute(filename, dest, MAXPATHLEN) < 0) {
+		errno = ENAMETOOLONG;
+		return -1;
+	}
+
+	psp_stat.st_size = length;
+	if(length < 0)
+	{
+		errno = EINVAL;
+		return -1;
+	}
+	return __psp_set_errno(sceIoChstat(dest, &psp_stat, FIO_CST_SIZE));
+}
+#endif
+
+/* Unsupported newlib system calls. */
+#ifdef F__fork
+pid_t fork(void)
+{
+	errno = ENOSYS;
+	return (pid_t) -1;
+}
+#endif
+
+#ifdef F__getpid
+pid_t _getpid(void)
+{
+	errno = ENOSYS;
+	return (pid_t) -1;
+}
+#endif
+
+#ifdef F__kill
+int _kill(int unused, int unused2)
+{
+	errno = ENOSYS;
+	return -1;
+}
+#endif
+
+#ifdef F__wait
+pid_t _wait(int *unused)
+{
+	errno = ENOSYS;
+	return (pid_t) -1;
+}
+#endif
+
+#ifdef F_access
+int access(const char *fn, int flags)
+{
+	struct stat s;
+	if (stat(fn, &s))
+		return -1;
+	if (s.st_mode & S_IFDIR)
+		return 0;
+	if (flags & W_OK)
+	{
+		if (s.st_mode & S_IWRITE)
+			return 0;
+		errno = EACCES;
+		return -1;
+	}
+	return 0;
+}
+#endif
+
+#ifdef F__fcntl
+int _fcntl(int fd, int cmd, ...)
+{
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	switch (cmd)
+	{
+		case F_DUPFD:
+		{
+			return __psp_fdman_get_dup_descriptor(fd);
+			break;
+		}
+		case F_GETFL:
+		{
+			return __psp_descriptormap[fd]->flags;
+			break;
+		}
+		case F_SETFL:
+		{
+			int newfl;
+			va_list args;
+	
+			va_start (args, cmd);         /* Initialize the argument list. */
+			newfl =  va_arg(args, int);
+			va_end (args);                /* Clean up. */
+
+			__psp_descriptormap[fd]->flags = newfl;
+
+			switch(__psp_descriptormap[fd]->type)
+			{
+				case __PSP_DESCRIPTOR_TYPE_FILE:
+					break;
+				case __PSP_DESCRIPTOR_TYPE_PIPE:
+					break;
+				case __PSP_DESCRIPTOR_TYPE_SOCKET:
+					if (newfl & O_NONBLOCK)
+					{
+						int one = 1;
+						return setsockopt(fd, SOL_SOCKET, SO_NONBLOCK, (char *)&one, sizeof(one));
+					}
+					else
+					{
+						int zero = 0;
+						return setsockopt(fd, SOL_SOCKET, SO_NONBLOCK, (char *)&zero, sizeof(zero));
+					}
+					break;
+				default:
+					break;
+			}
+			return 0;
+			break;
+		}
+	}
+
+	errno = EBADF;
+	return -1;
+}
+#endif /* F__fcntl */
+
+#ifdef F_tzset
+void tzset(void)
+{
+	static int initialized = 0;
+
+	if (!initialized)
+	{
+		initialized = 1;
+
+		/* Don't init if TZ has already been set once, this probably means the user
+		   wanted to override what we would set below. */
+		if (getenv("TZ") == NULL)
+		{
+			/* Initialize timezone from PSP configuration */
+			int tzOffset = 0;
+			sceUtilityGetSystemParamInt(PSP_SYSTEMPARAM_ID_INT_TIMEZONE, &tzOffset);
+			int tzOffsetAbs = tzOffset < 0 ? -tzOffset : tzOffset;
+			int hours = tzOffsetAbs / 60;
+			int minutes = tzOffsetAbs - hours * 60;
+			int pspDaylight = 0;
+			sceUtilityGetSystemParamInt(PSP_SYSTEMPARAM_ID_INT_DAYLIGHTSAVINGS, &pspDaylight);
+			static char tz[18];
+			sprintf(tz, "GMT%s%02i:%02i%s", tzOffset < 0 ? "+" : "-", hours, minutes, pspDaylight ? "daylight" : "");
+			setenv("TZ", tz, 1);
+		}
+	}
+
+	_tzset_r(_REENT);
+}
+#endif
+
+#ifdef F_mlock
+static unsigned int lock_count = 0;
+static unsigned int intr_flags = 0;
+
+void __malloc_lock(struct _reent *ptr)
+{
+	unsigned int flags = pspDisableInterrupts();
+
+	if (lock_count == 0) {
+		intr_flags = flags;
+	}
+
+	lock_count++;
+}
+
+void __malloc_unlock(struct _reent *ptr)
+{
+	if (--lock_count == 0) {
+		pspEnableInterrupts(intr_flags);
+	}
+}
+#endif
+
+/* Exit. */
+#if defined(F__exit) || defined(F_glue__exit)
+extern int sce_newlib_nocreate_thread_in_start __attribute__((weak));
+
+extern int __psp_free_heap(void);
+
+void _exit(int status)
+{
+	if (&sce_newlib_nocreate_thread_in_start == NULL) {
+		/* Free the heap created by _sbrk(). */
+		__psp_free_heap();
+
+		sceKernelSelfStopUnloadModule(1, 0, NULL);
+	} else {
+		if (status == 0) {
+			/* Free the heap created by _sbrk(). */
+			__psp_free_heap();
+		}
+
+		sceKernelExitThread(status);
+	}
+
+	while (1) ;
+}
+
+/* Note: This function is being linked into _exit.o.  
+
+   Because __psp_libc_init is a weak import in crt0.c, the linker
+   chooses to ignore an object file in libc.a that contains just this
+   function, since it's not necessary for successful compilation.
+
+   By putting it instead in _exit.o, which is already used by crt0.c,
+   the linker sees __psp_libc_init and resolves the symbol properly.
+*/
+void __psp_libc_init(int argc, char *argv[])
+{
+	(void) argc;
+
+	/* Initialize cwd from this program's path */
+	__psp_init_cwd(argv[0]);
+
+	/* Initialize filedescriptor management */
+	__psp_fdman_init();
+}
+
+#endif /* F__exit */
+
+#ifdef F__rename
+int _rename(const char *old, const char *new)
+{
+   char oldname[MAXPATHLEN + 1];
+   char newname[MAXPATHLEN + 1];
+
+   if(__psp_path_absolute(old, oldname, MAXPATHLEN) < 0) {
+       errno = ENAMETOOLONG;
+       return -1;
+   }
+
+   if(__psp_path_absolute(new, newname, MAXPATHLEN) < 0) {
+       errno = ENAMETOOLONG;
+       return -1;
+   }
+
+   return __psp_set_errno(sceIoRename(oldname, newname));
+}
+#endif
+
+#ifdef F_nanosleep
+/* note: we don't use rem as we have no signals */
+int nanosleep(const struct timespec *req, struct timespec *rem)
+{
+    if( req == NULL )
+        return EFAULT;
+
+    if( rem != NULL ) {
+        rem->tv_sec = 0;
+        rem->tv_nsec = 0;
+    }
+
+    sceKernelDelayThreadCB( 1000000 * req->tv_sec + (req->tv_nsec / 1000) );
+
+    return 0;
+}
+#endif
+
