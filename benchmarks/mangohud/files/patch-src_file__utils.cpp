--- src/file_utils.cpp.orig	2023-04-13 17:40:23 UTC
+++ src/file_utils.cpp
@@ -2,6 +2,7 @@
 #include "string_utils.h"
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/sysctl.h>
 #include <unistd.h>
 #include <dirent.h>
 #include <limits.h>
@@ -35,7 +36,6 @@ std::string get_basename(const std::string&& path)
     return path;
 }
 
-#ifdef __linux__
 std::vector<std::string> ls(const char* root, const char* prefix, LS_FLAGS flags)
 {
     std::vector<std::string> list;
@@ -109,9 +109,36 @@ std::string read_symlink(const std::string&& link)
     return read_symlink(link.c_str());
 }
 
+template <>
+int read_sysctl(const char* name)
+{
+    int value;
+    size_t len = sizeof(value);
+
+    if (sysctlbyname(name, &value, &len, NULL, 0) == 0)
+        return value;
+    else return -1;
+}
+
+template <>
+std::string read_sysctl(const char* name)
+{
+    size_t len;
+
+    // How large buffer do we need?
+    if (sysctlbyname(name, NULL, &len, NULL, 0) != 0)
+        return "";
+
+    char value[len];
+    // Now read the actual value into it.
+    if (sysctlbyname(name, value, &len, NULL, 0) == 0)
+        return value;
+    else return "";
+}
+
 std::string get_exe_path()
 {
-    return read_symlink("/proc/self/exe");
+    return read_symlink(PROCDIR "/self/exe");
 }
 
 std::string get_wine_exe_name(bool keep_ext)
@@ -121,14 +148,14 @@ std::string get_wine_exe_name(bool keep_ext)
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
@@ -185,16 +212,13 @@ std::string get_config_dir()
 }
 
 bool lib_loaded(const std::string& lib) {
-    fs::path path("/proc/self/map_files/");
-    for (auto& p : fs::directory_iterator(path)) {
-        auto file = p.path().string();
-        auto sym = read_symlink(file.c_str());
-        if (sym.find(lib) != std::string::npos) {
+    std::ifstream proc_maps(PROCDIR "/self/maps");
+    std::string line;
+    while (std::getline(proc_maps, line)) {
+        if (line.find(lib) != std::string::npos) {
             return true;
         }
     }
     return false;
 
 }
-
-#endif // __linux__
