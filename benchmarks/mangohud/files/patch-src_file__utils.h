--- src/file_utils.h.orig	2023-04-13 17:40:23 UTC
+++ src/file_utils.h
@@ -17,6 +17,7 @@ bool file_exists(const std::string& path);
 bool dir_exists(const std::string& path);
 std::string read_symlink(const char * link);
 std::string read_symlink(const std::string&& link);
+template <typename T> T read_sysctl(const char*);
 std::string get_basename(const std::string&& path); //prefix so it doesn't conflict libgen
 std::string get_exe_path();
 std::string get_wine_exe_name(bool keep_ext = false);
