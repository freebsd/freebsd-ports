--- sources/xray_re/xr_file_system.cxx.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_file_system.cxx
@@ -235,7 +235,7 @@ xr_reader* xr_file_system::r_open(const char* path, co
 xr_writer* xr_file_system::w_open(const char* path, const char* name) const
 {
 	const path_alias* pa = find_path_alias(path);
-	return pa ? w_open(pa->root + name) : false;
+	return pa ? w_open(pa->root + name) : 0x0;
 }
 
 bool xr_file_system::folder_exist(const char* path, const char* name) const
@@ -256,6 +256,7 @@ uint32_t xr_file_system::file_age(const char* path, co
 	return pa ? file_age(pa->root + name) : 0;
 }
 
+#if 0
 bool xr_file_system::copy_file(const char* src_path, const char* src_name,
 		const char* tgt_path, const char* tgt_name) const
 {
@@ -269,6 +270,7 @@ bool xr_file_system::copy_file(const char* src_path, c
 		tgt_name = src_name;
 	return copy_file(src_pa->root + src_name, tgt_pa->root + tgt_name);
 }
+#endif
 
 bool xr_file_system::create_folder(const char* path, const char* name) const
 {
