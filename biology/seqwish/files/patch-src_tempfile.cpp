--- src/tempfile.cpp.orig	2023-07-21 20:48:46 UTC
+++ src/tempfile.cpp
@@ -3,6 +3,8 @@
 #include <unistd.h>
 #include "tempfile.hpp"
 
+#include <sys/param.h>
+
 namespace temp_file {
 
     // We use this to make the API thread-safe
@@ -96,9 +98,10 @@ namespace temp_file {
 
         // Get the default temp dir from environment variables.
         if (temp_dir.empty()) {
-            char* cwd = get_current_dir_name();
+            char cwd[MAXPATHLEN];
+            getwd(cwd);
             temp_dir = std::string(cwd);
-            free(cwd);
+            //free(cwd);
             /*const char *system_temp_dir = nullptr;
             for (const char *var_name : {"TMPDIR", "TMP", "TEMP", "TEMPDIR", "USERPROFILE"}) {
                 if (system_temp_dir == nullptr) {
@@ -114,4 +117,4 @@ namespace temp_file {
     void set_keep_temp(bool setting) {
         keep_temp = setting;
     }
-}
\ No newline at end of file
+}
