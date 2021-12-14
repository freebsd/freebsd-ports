--- src/file_utils.cpp.orig	2021-07-08 06:23:59 UTC
+++ src/file_utils.cpp
@@ -109,7 +109,7 @@ std::string read_symlink(const char * link)
 
 std::string get_exe_path()
 {
-    return read_symlink("/proc/self/exe");
+    return read_symlink(PROCDIR "/self/exe");
 }
 
 std::string get_wine_exe_name(bool keep_ext)
@@ -119,14 +119,14 @@ std::string get_wine_exe_name(bool keep_ext)
         return std::string();
     }
 
-    std::string line = read_line("/proc/self/comm"); // max 16 characters though
+    std::string line = read_line(PROCDIR "/self/comm"); // max 16 characters though
     if (ends_with(line, ".exe", true))
     {
         auto dot = keep_ext ? std::string::npos : line.find_last_of('.');
         return line.substr(0, dot);
     }
 
-    std::ifstream cmdline("/proc/self/cmdline");
+    std::ifstream cmdline(PROCDIR "/self/cmdline");
     // Iterate over arguments (separated by NUL byte).
     while (std::getline(cmdline, line, '\0')) {
         auto n = std::string::npos;
