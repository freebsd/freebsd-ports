/*
 * Stub mpthreadport.h for mpy-cross.
 * mpy-cross does not use threading, but qstr generation for the unix port
 * preprocesses mpy-cross sources with -DMICROPY_PY_THREAD=1, requiring this
 * header to be present.
 */
#include <pthread.h>
typedef pthread_mutex_t mp_thread_mutex_t;
typedef pthread_mutex_t mp_thread_recursive_mutex_t;
