/*-
 * Copyright (c) 2003 Alexey Zelkin <phantom@FreeBSD.org>
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
 * Test pthreads primitives for required functionality in order to run
 * native FreeBSD JDK1.4.2 port.
 *
 * Returns:
 *    0 - test passed
 *    1 - general failure
 *  200 - tests failed
 *
 * $FreeBSD$
 */

#include <stdio.h>
#include <pthread.h>
#include <pthread_np.h>

#define TRY(call) {							\
  if ((call) != 0) {							\
    printf("LIBC_R TEST: Unexpected error.  Report to MAINTAINER\n");	\
    exit(200);								\
  }									\
}

void *
doit(void *data)
{
	pthread_attr_t attr;
	void *mystack = NULL;

	TRY(pthread_attr_init(&attr));
	TRY(pthread_attr_get_np(pthread_self(), &attr));
	TRY(pthread_attr_getstackaddr(&attr, &mystack));

	if (mystack == NULL) {
		printf("LIBC_R TEST FAILED: libc_r update required\n");
		exit(1);
	}

	printf("LIBC_R TEST PASSED: All Ok\n");
	return(NULL);
}

int
main()
{
	pthread_t tid;
	pthread_attr_t attr;

	int sz = 128*1024;

	TRY(pthread_attr_init(&attr));
	TRY(pthread_attr_setstacksize(&attr, sz));
	TRY(pthread_create(&tid, &attr, doit, NULL));
	TRY(pthread_join(tid, NULL));

	exit(0);
}
