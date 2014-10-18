--- inc/Standard_CLocaleSentry.hxx.orig	2014-04-29 11:40:41.000000000 +0200
+++ inc/Standard_CLocaleSentry.hxx	2014-05-15 21:33:15.000000000 +0200
@@ -25,7 +25,7 @@
 //! Notice that this is impossible to test (_POSIX_C_SOURCE >= 200809L)
 //! since POSIX didn't declared such identifier.
 //! We check _GNU_SOURCE for glibc extensions here and it is always defined by g++ compiler.
-#if defined(__APPLE__) || defined(_GNU_SOURCE) || defined(HAVE_XLOCALE_H)
+#if defined(__APPLE__) || defined(_GNU_SOURCE) || (defined(__FreeBSD__) && (__FreeBSD_version > 910000)) || defined(HAVE_XLOCALE_H)
   #include <xlocale.h>
   #ifndef HAVE_XLOCALE_H
     #define HAVE_XLOCALE_H
