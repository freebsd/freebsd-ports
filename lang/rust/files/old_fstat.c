/* $FreeBSD$ */

#include <sys/syscall.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct stat;

int
fstat(int fd, struct stat *sb)
{

	return (syscall(SYS_freebsd11_fstat, fd, sb));
}

int
stat(const char *path, struct stat *sb)
{

	return (syscall(SYS_freebsd11_stat, path, sb));
}

int
lstat(const char *path, struct stat *sb)
{

	return (syscall(SYS_freebsd11_lstat, path, sb));
}

int
fstatat(int fd, const char *path, struct stat *sb, int flag)
{

	return (syscall(SYS_freebsd11_fstatat, fd, path, sb, flag));
}

struct ODIR;
struct freebsd11_dirent;

/*
__asm(".symver  old_readdir, readdir@FBSD_1.0");
int old_readdir(struct ODIR *);
int
readdir(struct ODIR *dirp)
{

	return (old_readdir(dirp));
}
*/

__asm(".symver  old_readdir_r, readdir_r@FBSD_1.0");
int old_readdir_r(struct ODIR *, struct freebsd11_dirent *,
    struct freebsd11_dirent **);
int
readdir_r(struct ODIR *dirp, struct freebsd11_dirent *entry,
    struct freebsd11_dirent **result)
{
	void *libc;
	void *fptr;
	int error;

	libc = dlopen("libc.so.7", RTLD_LAZY | RTLD_GLOBAL);
	if (libc == NULL) {
		fprintf(stderr, "libc open: %s\n", dlerror());
		abort();
	}
	fptr = dlvsym(libc, "readdir_r", "FBSD_1.0");
	if (fptr == NULL) {
		fprintf(stderr, "readdir_r: %s\n", dlerror());
		abort();
	}
	error = ((int (*)(struct ODIR *, struct freebsd11_dirent *,
	    struct freebsd11_dirent **))fptr)(dirp, entry, result);
	dlclose(libc);
	return (error);
}

/*
__asm(".symver	old_scandir, scandir@FBSD_1.0");
int old_scandir(const char *, struct freebsd11_dirent ***,
    int (*)(const struct freebsd11_dirent *),
    int (*)(const struct freebsd11_dirent **,
	const struct freebsd11_dirent **));
int
scandir(const char *dirname, struct freebsd11_dirent ***namelist,
    int (*select)(const struct freebsd11_dirent *),
    int (*dcomp)(const struct freebsd11_dirent **,
	const struct freebsd11_dirent **))
{

	return (old_scandir(dirname, namelist, select, dcomp));
}
*/

struct old_statfs;
int
fstatfs(int fd, struct old_statfs *buf)
{

	return (syscall(SYS_freebsd11_fstatfs, fd, buf));
}
