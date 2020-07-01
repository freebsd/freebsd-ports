polyexport fails to unwind the stack on aarch64 with pthread signals enabled
ref: https://github.com/polyml/polyml/issues/110

--- libpolyml/sighandler.cpp.orig	2020-06-07 19:41:16 UTC
+++ libpolyml/sighandler.cpp
@@ -70,7 +70,7 @@
 #include <semaphore.h>
 #endif
 
-#if ((!defined(_WIN32) || defined(__CYGWIN__)) && defined(HAVE_LIBPTHREAD) && defined(HAVE_PTHREAD_H) && defined(HAVE_SEMAPHORE_H))
+#if ((!defined(_WIN32) || defined(__CYGWIN__)) && defined(HAVE_LIBPTHREAD) && defined(HAVE_PTHREAD_H) && defined(HAVE_SEMAPHORE_H)) && !defined(__aarch64__)
 // If we have the pthread library and header and we have semaphores we can use the pthread
 // signalling mechanism.  But if this is a native Windows build we don't use semaphores or
 // pthread even if they're provided.
