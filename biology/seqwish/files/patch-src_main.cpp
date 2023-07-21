--- src/main.cpp.orig	2023-07-21 20:57:07 UTC
+++ src/main.cpp
@@ -24,6 +24,8 @@
 #include "version.hpp"
 #include "tempfile.hpp"
 
+#include <sys/param.h>
+
 using namespace seqwish;
 
 int main(int argc, char** argv) {
@@ -116,9 +118,10 @@ int main(int argc, char** argv) {
     if (tmp_base) {
         temp_file::set_dir(args::get(tmp_base));
     } else {
-        char* cwd = get_current_dir_name();
+        char cwd[MAXPATHLEN];
+	getwd(cwd);
         temp_file::set_dir(std::string(cwd));
-        free(cwd);
+        //free(cwd);
     }
 
     temp_file::set_keep_temp(args::get(keep_temp_files));
