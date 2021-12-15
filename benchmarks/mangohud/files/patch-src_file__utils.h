--- src/file_utils.h.orig	2021-07-08 06:23:59 UTC
+++ src/file_utils.h
@@ -19,6 +19,7 @@ std::vector<std::string> ls(const char* root, const ch
 bool file_exists(const std::string& path);
 bool dir_exists(const std::string& path);
 std::string read_symlink(const char * link);
+template <typename T> T read_sysctl(const char*);
 std::string get_exe_path();
 std::string get_wine_exe_name(bool keep_ext = false);
 std::string get_home_dir();
