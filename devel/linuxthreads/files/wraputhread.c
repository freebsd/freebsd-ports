/*
 * Copyright (c) 2001 Daniel Eischen <deischen@FreeBSD.org>.
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
 * THIS SOFTWARE IS PROVIDED BY DANIEL EISCHEN AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
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
 * $FreeBSD: /tmp/pcvs/ports/devel/linuxthreads/files/wraputhread.c,v 1.2 2001-06-14 01:34:18 tegge Exp $
 */

#include <pthread.h>
#include <stdlib.h>
#include <sys/errno.h>

void *__pthread_getspecific(pthread_key_t);
int   __pthread_setspecific(pthread_key_t, const void *);
int   __pthread_key_create(pthread_key_t *, void (*) (void *));
int   __pthread_mutex_destroy(pthread_mutex_t *);
int   __pthread_mutex_init(pthread_mutex_t *, const pthread_mutexattr_t *);
int   __pthread_mutex_lock(pthread_mutex_t *);
int   __pthread_mutex_trylock(pthread_mutex_t *);
int   __pthread_mutex_unlock(pthread_mutex_t *);

void *
_pthread_getspecific(pthread_key_t key)
{
	return __pthread_getspecific(key);
}

int
_pthread_key_create(pthread_key_t *key, void (*destructor) (void *))
{
	return __pthread_key_create(key, destructor);
}

int
_pthread_key_delete(pthread_key_t key)
{
	return pthread_key_delete(key);
}

int
_pthread_mutex_destroy(pthread_mutex_t **mutex)
{
	int ret;
	
	ret = __pthread_mutex_destroy(*mutex);
	if (ret == 0)
		free(*mutex);
	return ret;
}


static pthread_mutex_t allocmutexlock = PTHREAD_MUTEX_INITIALIZER;

static int
allocmutex(pthread_mutex_t **mutex)
{
	pthread_mutex_t *m;
	int ret;

	m = malloc(sizeof(pthread_mutex_t));
	if (m == NULL)
		return ENOMEM;
	ret = __pthread_mutex_init(m, NULL);
	if (ret != 0) {
		free(m);
		return ret;
	}
	__pthread_mutex_lock(&allocmutexlock);
	if (*mutex != NULL) {
		__pthread_mutex_unlock(&allocmutexlock);
		__pthread_mutex_destroy(m);
		free(m);
		return 0;
	}
	*mutex = m;
	__pthread_mutex_unlock(&allocmutexlock);
	return 0;
}

int
_pthread_mutex_init(pthread_mutex_t **mutex, const pthread_mutexattr_t *mattr)
{
	(void) mattr;
	*mutex = malloc(sizeof(pthread_mutex_t));
	return __pthread_mutex_init(*mutex, NULL);	// XXX
}

int
_pthread_mutex_lock(pthread_mutex_t **mutex)
{
	int ret;
	if (*mutex == NULL) {
		ret = allocmutex(mutex);
		if (ret != 0)
			return ret;
	}
	return __pthread_mutex_lock(*mutex);
}

int
_pthread_mutex_trylock(pthread_mutex_t **mutex)
{
	int ret;
	if (*mutex == NULL) {
		ret = allocmutex(mutex);
		if (ret != 0)
			return ret;
	}
	return __pthread_mutex_trylock(*mutex);
}

int
_pthread_mutex_unlock(pthread_mutex_t **mutex)
{
	int ret;
	if (*mutex == NULL) {
		ret = allocmutex(mutex);
		if (ret != 0)
			return ret;
	}
	return __pthread_mutex_unlock(*mutex);
}

int
_pthread_mutexattr_init(pthread_mutexattr_t *mattr)
{
	return EINVAL;
}

int
_pthread_mutexattr_destroy(pthread_mutexattr_t *mattr)
{
	return EINVAL;
}

int
_pthread_mutexattr_settype(pthread_mutexattr_t *mattr, int type)
{
	return EINVAL;
}

struct uthread_pthread_once {
	int		state;
	pthread_mutex_t	*mutex;
};
typedef struct uthread_pthread_once uthread_pthread_once_t;

/*
 * Flags for once initialization.
 */
#define UTHREAD_PTHREAD_NEEDS_INIT  0
#define UTHREAD_PTHREAD_DONE_INIT   1

int
_pthread_once(uthread_pthread_once_t *once_control,
	      void (*init_routine) (void))
{
	if (once_control->state == UTHREAD_PTHREAD_NEEDS_INIT) {
		_pthread_mutex_lock(&(once_control->mutex));
		if (once_control->state == UTHREAD_PTHREAD_NEEDS_INIT) {
			init_routine();
			once_control->state = UTHREAD_PTHREAD_DONE_INIT;
		}
		_pthread_mutex_unlock(&(once_control->mutex));
	}
	return (0);
}

pthread_t
_pthread_self(void)
{
	return pthread_self();
}

int
_pthread_setspecific(pthread_key_t key, const void *value)
{
	return __pthread_setspecific(key, value);
}
