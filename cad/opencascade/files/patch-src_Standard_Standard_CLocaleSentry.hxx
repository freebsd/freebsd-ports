--- src/Standard/Standard_CLocaleSentry.hxx.orig	2013-04-18 17:20:16.000000000 +0200
+++ src/Standard/Standard_CLocaleSentry.hxx	2013-05-13 18:57:58.000000000 +0200
@@ -29,7 +29,10 @@
 //! Notice that this is impossible to test (_POSIX_C_SOURCE >= 200809L)
 //! since POSIX didn't declared such identifier.
 //! We check _GNU_SOURCE for glibc extensions here and it is always defined by g++ compiler.
-#if defined(__APPLE__) || defined(_GNU_SOURCE) || defined(HAVE_XLOCALE_H)
+#ifdef __FreeBSD__
+  #include <sys/param.h>
+#endif
+#if defined(__APPLE__) || defined(_GNU_SOURCE) || defined(HAVE_XLOCALE_H) || (__FreeBSD_version >= 900506)
   #include <xlocale.h>
   #ifndef HAVE_XLOCALE_H
     #define HAVE_XLOCALE_H
