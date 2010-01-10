--- util/Directories.cpp.orig	2010-01-10 18:41:05.000000000 +0100
+++ util/Directories.cpp	2010-01-10 18:47:22.000000000 +0100
@@ -201,7 +201,10 @@
         problem = true;
     }
 
-    if (problem || !exists(bin_dir)) {
+    fs::path p(bin_dir);
+    p /= "freeorion";
+
+    if (problem || !exists(p)) {
         // failed trying to parse the call path, so try hard-coded standard location...
         char* dir_name = br_find_bin_dir("/usr/local/bin");
         fs::path p(dir_name);
