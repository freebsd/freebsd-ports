--- src/Standard/Standard_CLocaleSentry.hxx.orig	2017-08-30 13:28:31 UTC
+++ src/Standard/Standard_CLocaleSentry.hxx
@@ -25,7 +25,7 @@
   //! and become part of POSIX since '2008.
   //! Notice that this is impossible to test (_POSIX_C_SOURCE >= 200809L)
   //! since POSIX didn't declared such identifier.
-  #if defined(__APPLE__)
+  #if defined(__APPLE__) || (defined(__FreeBSD__) && (__FreeBSD_version > 910000))
     #define HAVE_XLOCALE_H
   #endif
 
