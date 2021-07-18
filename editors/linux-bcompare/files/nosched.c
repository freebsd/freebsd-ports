#define _GNU_SOURCE

#include <dlfcn.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>

/* Thanks to shkhln (https://forums.freebsd.org/members/shkhln.54069/) and
 * aragats (https://forums.freebsd.org/members/aragats.37029/) for coming
 * up with the nosched.c fix
 */

int pthread_noop() {
  fprintf(stderr, "%s(...)\n", __func__);
  return 0;
}

/* https://stackoverflow.com/questions/15599026/how-can-i-intercept-dlsym-calls-using-ld-preload/18825060#18825060 */
void* _dl_sym(void*, const char*, void*);

static void* (*libc_dlsym)(void*, const char*) = NULL;

void* dlsym(void* handle, const char* symbol) {

  if (!libc_dlsym) {
    libc_dlsym = _dl_sym(RTLD_NEXT, "dlsym", dlsym);
  }

  if (strcmp(symbol, "pthread_attr_setinheritsched") == 0) {
    return pthread_noop;
  }

  return libc_dlsym(handle, symbol);
}

