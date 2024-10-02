--- src/hugin_base/hugin_utils/filesystem.h.orig	2023-05-08 18:19:14 UTC
+++ src/hugin_base/hugin_utils/filesystem.h
@@ -64,6 +64,12 @@
     #endif
     #include <boost/filesystem.hpp>
     namespace fs = boost::filesystem;
-    #define OVERWRITE_EXISTING boost::filesystem::copy_option::overwrite_if_exists
+    #if BOOST_VERSION>=107400
+      // in Boost 1.74 and later filesystem::copy_option is deprecated
+      // use filesystem::copy_options instead
+      #define OVERWRITE_EXISTING boost::filesystem::copy_options::overwrite_existing
+    #else
+      #define OVERWRITE_EXISTING boost::filesystem::copy_option::overwrite_if_exists
+    #endif
 #endif
 #endif // _HUGIN_UTILS_FILESYSTEM_H
