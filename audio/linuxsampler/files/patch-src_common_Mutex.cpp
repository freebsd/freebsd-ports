--- src/common/Mutex.cpp.orig	2007-11-14 23:42:15 UTC
+++ src/common/Mutex.cpp
@@ -36,7 +36,6 @@
 #if !defined(WIN32)
 #if !defined(_XOPEN_SOURCE) || _XOPEN_SOURCE < 500
 # undef _XOPEN_SOURCE
-# define _XOPEN_SOURCE 500 /* to define PTHREAD_MUTEX_ERRORCHECK */
 # warning "Seems you don't have a UNIX98 compatible system."
 # warning "Please run LinuxSampler's selftest to make sure this won't be a problem!"
 # warning "(compile tests with 'make tests', run them with 'src/testcases/linuxsamplertest')"
