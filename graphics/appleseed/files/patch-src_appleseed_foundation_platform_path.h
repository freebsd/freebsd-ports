--- src/appleseed/foundation/platform/path.h.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/foundation/platform/path.h
@@ -42,7 +42,7 @@
 #include "boost/filesystem/path.hpp"
 
 // Platform headers.
-#if defined __APPLE__
+#if defined __APPLE__ || defined __FreeBSD__
 #include <sys/param.h>
 #elif defined __linux__
 #include <linux/limits.h>
@@ -60,7 +60,7 @@ namespace foundation
     #define FOUNDATION_MAX_PATH_LENGTH  MAX_PATH
 
 // OS X.
-#elif defined __APPLE__
+#elif defined __APPLE__ || defined __FreeBSD__
     #define FOUNDATION_MAX_PATH_LENGTH  MAXPATHLEN
 
 // Linux.
