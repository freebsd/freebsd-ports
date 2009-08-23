--- src/common/Mutex.cpp.orig	Tue Mar  6 20:42:00 2007
+++ src/common/Mutex.cpp	Tue Mar  6 20:42:06 2007
@@ -35,7 +35,6 @@
 
 #if !defined(_XOPEN_SOURCE) || _XOPEN_SOURCE < 500
 # undef _XOPEN_SOURCE
-# define _XOPEN_SOURCE 500 /* to define PTHREAD_MUTEX_ERRORCHECK */
 # warning "Seems you don't have a UNIX98 compatible system."
 # warning "Please run LinuxSampler's selftest to make sure this won't be a problem!"
 # warning "(compile tests with 'make tests', run them with 'src/testcases/linuxsamplertest')"
