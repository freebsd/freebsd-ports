/*
 * Copyright (c) 2002  The FreeBSD Project
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* This matches struct stat64 in glibc2.1, hence the absolutely
 * insane amounts of padding around dev_t's.
 */
struct stat64 {
    unsigned short	st_dev;
    unsigned char	__pad0[10];

#define STAT64_HAS_BROKEN_ST_INO	1
    unsigned long	__st_ino;

    unsigned int	st_mode;
    unsigned int	st_nlink;

    unsigned long	st_uid;
    unsigned long	st_gid;

    unsigned short	st_rdev;
    unsigned char	__pad3[10];

    long long	st_size;
    unsigned long	st_blksize;

    unsigned long	st_blocks;	/* Number 512-byte blocks allocated. */
    unsigned long	__pad4;		/* future possible st_blocks high bits */

    unsigned long	st_atime_;
    unsigned long	__pad5;

    unsigned long	st_mtime_;
    unsigned long	__pad6;

    unsigned long	st_ctime_;
    unsigned long	__pad7;		/* will be high 32 bits of ctime someday */

    unsigned long long	st_ino;
};


struct stat64 stat2stat64(struct stat sb) {
    static struct stat64 sb64;

    sb64.st_dev     = sb.st_dev;
    sb64.st_ino     = sb.st_ino; 
    sb64.st_mode    = sb.st_mode; 
    sb64.st_nlink   = sb.st_nlink;
    sb64.st_uid     = sb.st_uid; 
    sb64.st_gid     = sb.st_gid; 
    sb64.st_rdev    = sb.st_rdev; 
    sb64.st_size    = sb.st_size; 
    sb64.st_blksize = sb.st_blksize;
    sb64.st_blocks  = sb.st_blocks;
    sb64.st_atime_  = sb.st_atime;
    sb64.st_mtime_  = sb.st_mtime;
    sb64.st_ctime_  = sb.st_ctime;

    return sb64;
}


int __fxstat64 (int __ver, int __fildes, struct stat64 *__stat_buf) {
    struct stat sb;
    int result;

    result = fstat (__fildes, &sb);
    *__stat_buf = stat2stat64(sb);
    return result;
}


int __xstat64 (int __ver, __const char *__filename,
	       struct stat64 *__stat_buf) {
    struct stat sb;
    int result;

    result = stat (__filename, &sb);
    *__stat_buf = stat2stat64(sb);
    return result;
}


#include <stdio.h>

void __xstat() {
    fprintf(stderr, __FILE__ ": __xstat() is dummy.\n");
};
void __fxstat() {
    fprintf(stderr, __FILE__ ": __fxstat() is dummy.\n");
};
void __lxstat() {
    fprintf(stderr, __FILE__ ": __lxstat() is dummy.\n");
};
void __lxstat64() {
    fprintf(stderr, __FILE__ ": __lxstat64() is dummy.\n");
};


typedef int32_t         l_long;
typedef l_long          l_off_t;

l_off_t Lseek(int fildes, l_off_t offset, int whence)
{
    return (l_off_t) lseek(fildes, (off_t) offset, whence);
}
