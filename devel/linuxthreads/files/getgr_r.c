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

#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <grp.h>
#include "pthread.h"

static pthread_mutex_t getgr_mutex = PTHREAD_MUTEX_INITIALIZER;

static int
convert (struct group *ret, struct group *result,
       char *buf, int buflen)
{
  int len;
  int count;
  char **gr_mem;
  char *buf1;

  if (!buf) return -1;

  *result = *ret;

  result->gr_name = (char *) buf;
  /* This is the size. */
  len = strlen (ret->gr_name) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->gr_name, ret->gr_name);

  result->gr_passwd = (char *) buf;
  /* This is the size. */
  len = strlen (ret->gr_passwd) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->gr_passwd, ret->gr_passwd);

  count = 0;
  gr_mem = ret->gr_mem;
  while (*gr_mem){
       count++;
       gr_mem++;
  }
  len = sizeof (*gr_mem)*(count+1);
  if (len > buflen) return -1;
  buf1 = buf;
  buflen -= len;
  buf += len;
  gr_mem = ret->gr_mem;
  while (*gr_mem){
       len = strlen (*gr_mem) + 1;
       if (len > buflen) return -1;
       buf1 = buf;
       strcpy (buf, *gr_mem);
       buflen -= len;
       buf += len;
       buf1 += sizeof (buf1);
       gr_mem++;
  }
  buf1 = NULL;
  return 0;
}

int getgrnam_r (const char *name, struct group *result,
                char *buffer, size_t buflen,
                struct group ** resptr)
{
  struct group * p;
  int retval;

  pthread_mutex_lock (&getgr_mutex);
  p = getgrnam (name);
  if (p == NULL) {
    *resptr = NULL;
    retval = ESRCH;
  } else
  if (convert (p, result, buffer, buflen) != 0) {
    *resptr = NULL;
    retval = ERANGE;
  } else {
    *resptr = result;
    retval = 0;
  }
  pthread_mutex_unlock (&getgr_mutex);
  return retval;
}

int getgrgid_r (uid_t uid, struct group *result, 
                char *buffer, size_t buflen,
                struct group ** resptr)
{
  struct group * p;
  int retval;

  pthread_mutex_lock (&getgr_mutex);
  p = getgrgid (uid);
  if (p == NULL) {
    *resptr = NULL;
    retval = ESRCH;
  } else
  if (convert (p, result, buffer, buflen) != 0) {
    *resptr = NULL;
    retval = ERANGE;
  } else {
    *resptr = result;
    retval = 0;
  }
  pthread_mutex_unlock (&getgr_mutex);
  return retval;
}
