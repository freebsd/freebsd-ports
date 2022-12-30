--- include/astrometry/os-features.h.orig	2022-12-19 21:41:15 UTC
+++ include/astrometry/os-features.h
@@ -4,6 +4,8 @@
 */
 #ifndef OS_FEATURES_H
 #define OS_FEATURES_H
+#define NEED_CANONICALIZE_FILE_NAME 1
+#define HAVE_NETPBM 1
 
 #include "astrometry/os-features-config.h"
 
