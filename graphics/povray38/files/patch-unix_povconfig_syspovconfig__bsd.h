--- unix/povconfig/syspovconfig_bsd.h.orig	2021-07-11 11:08:43 UTC
+++ unix/povconfig/syspovconfig_bsd.h
@@ -58,7 +58,7 @@
     // Unable to detect `off_t` size at compile-time.
     // This variant of BSD _may or may not_ provide large file support via the `lseek` function.
     // Comment-out the following line to proceed anyway
-    #error "Image size may be limited to approx. 100 Megapixels. Proceed at your own risk."
+    //#error "Image size may be limited to approx. 100 Megapixels. Proceed at your own risk."
     #define POV_LSEEK(handle,offset,whence) lseek(handle,offset,whence)
     #define POV_OFF_T off_t
 #endif
