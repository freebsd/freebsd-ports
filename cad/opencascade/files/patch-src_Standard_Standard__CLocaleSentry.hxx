--- src/Standard/Standard_CLocaleSentry.hxx.orig	2025-02-17 22:00:23 UTC
+++ src/Standard/Standard_CLocaleSentry.hxx
@@ -32,7 +32,7 @@
   //! 200809L)) due to missing such declarations in standard. On macOS new functions are declared
   //! within "xlocale.h" header (the same is for glibc, but this header has been removed since
   //! glibc 2.26).
-  #if defined(__APPLE__)
+  #if defined(__APPLE__) || (defined(__FreeBSD__) && (__FreeBSD_version > 910000))
     #define OCCT_CLOCALE_POSIX2008
   #endif
 
