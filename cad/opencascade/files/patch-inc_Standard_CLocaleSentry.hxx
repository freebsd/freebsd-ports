--- inc/Standard_CLocaleSentry.hxx.orig	2013-05-15 15:38:02.000000000 +0700
+++ inc/Standard_CLocaleSentry.hxx	2013-05-15 15:57:18.000000000 +0700
@@ -29,7 +29,7 @@
 //! Notice that this is impossible to test (_POSIX_C_SOURCE >= 200809L)
 //! since POSIX didn't declared such identifier.
 //! We check _GNU_SOURCE for glibc extensions here and it is always defined by g++ compiler.
-#if defined(__APPLE__) || defined(_GNU_SOURCE) || defined(HAVE_XLOCALE_H)
+#if defined(__APPLE__) || (defined(_GNU_SOURCE) && !defined(__FreeBSD__)) || defined(HAVE_XLOCALE_H) || (defined(__FreeBSD__) && (__FreeBSD_version>=900506))
   #include <xlocale.h>
   #ifndef HAVE_XLOCALE_H
     #define HAVE_XLOCALE_H
