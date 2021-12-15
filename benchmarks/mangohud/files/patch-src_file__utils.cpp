--- src/file_utils.cpp.orig	2021-07-08 06:23:59 UTC
+++ src/file_utils.cpp
@@ -2,6 +2,7 @@
 #include "string_utils.h"
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/sysctl.h>
 #include <unistd.h>
 #include <dirent.h>
 #include <limits.h>
@@ -107,9 +108,36 @@ std::string read_symlink(const char * link)
     return std::string(result, (count > 0) ? count : 0);
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
@@ -119,14 +147,14 @@ std::string get_wine_exe_name(bool keep_ext)
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
