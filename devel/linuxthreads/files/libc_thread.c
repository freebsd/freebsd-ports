/*
 * Copyright (c) 1999 Richard Seaman, Jr.
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
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Richard Seaman, Jr.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY RICHARD SEAMAN, Jr. AND CONTRIBUTORS ``AS IS'' AND
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
 */

#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <dlfcn.h>
#include <errno.h>
#include <stdlib.h>
#include "pthread.h"
#include "internals.h"

typedef struct {
	volatile long	lock;
	volatile int	nreaders; /* -1 when a write lock is held. */
} rwlock_t;

#define	_RWLOCK_PROTECT(l)	_spinlock(&((l)->lock))
#define _RWLOCK_UNPROTECT(l)	(l)->lock = 0

/*
 * This is defined in lib/libc/stdlib/exit.c.  It turns on thread safe behavior
 * in libc if non-zero.
 */
extern int __isthreaded;

/*
 * Optional.  In case our code is dependant on the existence of
 * the posix priority extentions kernel option.
 */
#include <sys/sysctl.h>
int _posix_priority_scheduling;

#if defined(NEWLIBC)
/*
 * The following are needed if we're going to get thread safe behavior in the
 * time functions in lib/libc/stdtime/localtime.c.
 */
static pthread_mutex_t	_lcl_mutex	= PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t	_gmt_mutex	= PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t	_localtime_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t	_gmtime_mutex	= PTHREAD_MUTEX_INITIALIZER;

extern pthread_mutex_t	*lcl_mutex;
extern pthread_mutex_t	*gmt_mutex;
extern pthread_mutex_t	*localtime_mutex;
extern pthread_mutex_t	*gmtime_mutex;
#endif

/* Use the constructor attribute so this gets run before main does. */
static void _pthread_initialize(void) __attribute__((constructor));

/* Defined in _atomic_lock.S. */
long	 _atomic_lock(volatile long *);

void	 _spinlock(volatile long *lock);
void	*lock_create (void *context);
void	 rlock_acquire (void *lock);
void	 wlock_acquire (void *lock);
void	 lock_release (void *lock);
void	 lock_destroy (void *lock);

static void _pthread_initialize(void)
{
	int mib[2];
	size_t len;

	len = sizeof (_posix_priority_scheduling);
	mib[0] = CTL_P1003_1B;
	mib[1] = CTL_P1003_1B_PRIORITY_SCHEDULING;
	if (-1 == sysctl (mib, 2, &_posix_priority_scheduling, &len, NULL, 0))
		_posix_priority_scheduling = 0;

	/* This turns on thread safe behaviour in libc when we link with it. */
	__isthreaded = 1;

	dllockinit (NULL,
		    lock_create,
		    rlock_acquire,
		    wlock_acquire,
		    lock_release,
		    lock_destroy,
		    NULL);

#if defined(NEWLIBC)
	/* Set up pointers for lib/libc/stdtime/localtime.c. */
	lcl_mutex       = &_lcl_mutex;
	gmt_mutex       = &_gmt_mutex;
	localtime_mutex = &_localtime_mutex;
	gmtime_mutex    = &_gmtime_mutex;
#endif
}

void
_spinlock(volatile long *lock)
{
	while(_atomic_lock(lock)) {
		/* Spin. */
	}
}

/*
 * Simple nested spinning reader/writer lock implementation.  We can't use the
 * normal library implementation for bootstrapping reasons.  This implementation
 * allows one writer or any number of concurrent readers.  No lock grant
 * ordering guarantees are made.
 */

void *
lock_create (void *context)
{
	rwlock_t	*retval;

	retval = (rwlock_t *)malloc(sizeof(rwlock_t));
	if (retval == NULL)
		goto RETURN;

	bzero(retval, sizeof(rwlock_t));
  RETURN:
	return ((void *)retval);
}

void
rlock_acquire (void *lock)
{
	rwlock_t	*rwlock = lock;
	
	_RWLOCK_PROTECT(rwlock);
	while (rwlock->nreaders < 0) {
		_RWLOCK_UNPROTECT(rwlock);
		_RWLOCK_PROTECT(rwlock);
	}
	rwlock->nreaders++;
	
	_RWLOCK_UNPROTECT(rwlock);
}

void
wlock_acquire (void *lock)
{
	rwlock_t	*rwlock = lock;
	
	_RWLOCK_PROTECT(rwlock);
	while (rwlock->nreaders != 0) {
		_RWLOCK_UNPROTECT(rwlock);
		_RWLOCK_PROTECT(rwlock);
	}
	rwlock->nreaders--;
	
	_RWLOCK_UNPROTECT(rwlock);
}

void
lock_release (void *lock)
{
	rwlock_t	*rwlock = lock;

	_RWLOCK_PROTECT(rwlock);

	if (rwlock->nreaders < 0)
		rwlock->nreaders++;
	else
		rwlock->nreaders--;
	
	_RWLOCK_UNPROTECT(rwlock);
}

void
lock_destroy (void *lock)
{
	free(lock);
}
