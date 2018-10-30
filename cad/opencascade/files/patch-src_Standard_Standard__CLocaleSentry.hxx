--- src/Standard/Standard_CLocaleSentry.hxx.orig	2018-05-25 19:14:11 UTC
+++ src/Standard/Standard_CLocaleSentry.hxx
@@ -31,7 +31,7 @@
   //! Presence of this extension cannot be checked in straightforward way (like (_POSIX_C_SOURCE >= 200809L))
   //! due to missing such declarations in standard.
   //! On macOS new functions are declared within "xlocale.h" header (the same is for glibc, but this header has been removed since glibc 2.26).
-  #if defined(__APPLE__)
+  #if defined(__APPLE__) || (defined(__FreeBSD__) && (__FreeBSD_version > 910000))
     #define OCCT_CLOCALE_POSIX2008
   #endif
 
