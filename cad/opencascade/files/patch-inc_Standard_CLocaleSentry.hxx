--- inc/Standard_CLocaleSentry.hxx.orig	2014-11-07 16:16:43.000000000 +0100
+++ inc/Standard_CLocaleSentry.hxx	2014-11-16 14:42:51.000000000 +0100
@@ -25,7 +25,7 @@
   //! and become part of POSIX since '2008.
   //! Notice that this is impossible to test (_POSIX_C_SOURCE >= 200809L)
   //! since POSIX didn't declared such identifier.
-  #if defined(__APPLE__)
+  #if defined(__APPLE__) || (defined(__FreeBSD__) && (__FreeBSD_version > 910000))
     #define HAVE_XLOCALE_H
   #endif
 
