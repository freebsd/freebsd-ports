--- util/Directories.cpp.orig	2023-03-21 15:16:58 UTC
+++ util/Directories.cpp
@@ -4,9 +4,8 @@
 #include "i18n.h"
 
 #include <boost/algorithm/string/trim.hpp>
-#include <boost/filesystem/convenience.hpp>
-#include <boost/filesystem/operations.hpp>
 #include <boost/date_time/posix_time/posix_time.hpp>
+#include <boost/filesystem.hpp>
 
 #include <cstdlib>
 #include <mutex>
@@ -266,7 +265,7 @@ void InitBinDir(std::string const& argv0)
 #if defined(FREEORION_WIN32)
     try {
         fs::path binary_file = fs::system_complete(FilenameToPath(argv0));
-        bin_dir = binary_file.branch_path();
+        bin_dir = binary_file.parent_path();
     } catch (const fs::filesystem_error &) {
         bin_dir = fs::initial_path();
     }
@@ -315,7 +314,7 @@ void InitBinDir(std::string const& argv0)
             std::string path_text(buf);
 
             fs::path binary_file = fs::system_complete(fs::path(path_text));
-            bin_dir = binary_file.branch_path();
+            bin_dir = binary_file.parent_path();
 
             // check that a "freeoriond" file (hopefully the freeorion server binary) exists in the found directory
             fs::path p(bin_dir);
