--- ddtrace/profile/collector/stack.pyx.orig	2020-03-13 18:20:41 UTC
+++ ddtrace/profile/collector/stack.pyx
@@ -34,7 +34,7 @@ IF UNAME_SYSNAME == "Linux":
 
     cdef extern from "<pthread.h>":
         # POSIX says this might be a struct, but CPython relies on it being an integer.
-        ctypedef int pthread_t
+        ctypedef struct pthread_t
         int pthread_getcpuclockid(pthread_t thread, clockid_t *clock_id)
 
     cdef p_pthread_getcpuclockid(tid):
