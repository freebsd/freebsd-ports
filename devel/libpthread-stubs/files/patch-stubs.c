XXX This is a big hack as we cannot define pthread_condattr_{init,destroy}
here, or we will conflict with the weak symbols in libthr.  The way our linker
works, the weak symbols will be resolved here, and pthread_condattr functions
will not work even in threaded applications.

I am working to get these symbols added to libc, but in the meantime, this
is needed to avoid crashes in threaded applications which make use of
pthread_condattr*.
--- stubs.c.orig	2009-11-27 17:15:30.000000000 -0500
+++ stubs.c	2009-11-27 17:16:29.000000000 -0500
@@ -91,7 +91,7 @@ int pthread_cond_destroy() __attribute__
 # endif
 #endif
 
-#ifndef HAVE_PTHREAD_CONDATTR_INIT
+#if 0
 #define NEED_ZERO_STUB
 # ifdef SUPPORT_ATTRIBUTE_ALIAS
 int pthread_condattr_init() __attribute__ ((weak, alias ("__pthread_zero_stub")));
@@ -100,7 +100,7 @@ int pthread_condattr_init() __attribute_
 # endif
 #endif
 
-#ifndef HAVE_PTHREAD_CONDATTR_DESTROY
+#if 0
 #define NEED_ZERO_STUB
 # ifdef SUPPORT_ATTRIBUTE_ALIAS
 int pthread_condattr_destroy() __attribute__ ((weak, alias ("__pthread_zero_stub")));
