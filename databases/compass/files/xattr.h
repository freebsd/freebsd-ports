/*
 * xattr is a Linux kernel API that has to be mapped to the FreeBSD API
 * code below is adopted and simplified from the 'xattr' python module
 * https://github.com/xattr/xattr/blob/master/xattr/lib_build.c
 */

#ifdef __FreeBSD__
#include <sys/types.h>

/* FreeBSD compatibility API */
#define XATTR_XATTR_NOFOLLOW 0x0001
#define XATTR_XATTR_CREATE 0x0002
#define XATTR_XATTR_REPLACE 0x0004
#define XATTR_XATTR_NOSECURITY 0x0008

#define XATTR_CREATE 0x1
#define XATTR_REPLACE 0x2

ssize_t getxattr(const char *path, const char *name,
                 void *value, ssize_t size, u_int32_t position,
                 int options);
ssize_t setxattr(const char *path, const char *name,
                 void *value, ssize_t size, u_int32_t position,
                 int options);
ssize_t removexattr(const char *path, const char *name,
                    int options);
ssize_t listxattr(const char *path, char *namebuf,
                  size_t size, int options);
ssize_t fgetxattr(int fd, const char *name, void *value,
                  ssize_t size, u_int32_t position, int options);
ssize_t fsetxattr(int fd, const char *name, void *value,
                  ssize_t size, u_int32_t position, int options);
ssize_t fremovexattr(int fd, const char *name, int options);
ssize_t flistxattr(int fd, char *namebuf, size_t size, int options);

#endif

#ifndef XATTR_MAXNAMELEN
#define XATTR_MAXNAMELEN 127
#endif
