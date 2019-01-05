/* -*- ugly-hack-mode -*- */
/* $FreeBSD$ */

#include <sys/stat.h>

struct old_dirent;
struct old_stat;

__asm(".symver	old_readdir_r, readdir_r@FBSD_1.0");
int old_readdir_r(void *dirp, struct old_dirent *entry,
    struct old_dirent **result);
__asm(".symver	old_stat, stat@FBSD_1.0");
int old_stat(const char * restrict path, struct old_stat * restrict sb);
__asm(".symver	old_lstat, lstat@FBSD_1.0");
int old_lstat(const char * restrict path, struct old_stat * restrict sb);
__asm(".symver	old_fstat, fstat@FBSD_1.0");
int old_fstat(int fd, struct old_stat *sb);
__asm(".symver	old_mknod, mknod@FBSD_1.0");
int old_mknod(const char *path, mode_t mode, uint32_t dev);

int
__wrap_readdir_r(void *dirp, struct old_dirent *entry,
    struct old_dirent **result)
{

	return (old_readdir_r(dirp, entry, result));
}

int
__wrap_stat(const char * restrict path, struct old_stat * restrict sb)
{

	return (old_stat(path, sb));
}

int
__wrap_lstat(const char * restrict path, struct old_stat * restrict sb)
{

	return (old_lstat(path, sb));
}

int
__wrap_fstat(int fd, struct old_stat *sb)
{

	return (old_fstat(fd, sb));
}

int
__wrap_mknod(const char *path, mode_t mode, uint32_t dev)
{

	return (old_mknod(path, mode, dev));
}
