--- src/common/Mutex.cpp.orig	2019-05-07 05:18:11 UTC
+++ src/common/Mutex.cpp
@@ -40,7 +40,6 @@
 #if !defined(WIN32)
 # if !defined(_XOPEN_SOURCE) || _XOPEN_SOURCE < 500
 #  undef _XOPEN_SOURCE
-#  define _XOPEN_SOURCE 500 /* to define PTHREAD_MUTEX_RECURSIVE */
 #  if (!defined(POSIX_C_SOURCE) || POSIX_C_SOURCE < 199801L) && !__DARWIN_UNIX03
 #   warning "Seems you don't have a UNIX98 compatible system."
 #   warning "Please run LinuxSampler's selftest to make sure this won't be a problem!"
