
$FreeBSD$

--- lib/sources/xpv_dynamic_loader.cpp.orig	Sun Dec 22 17:50:59 2002
+++ lib/sources/xpv_dynamic_loader.cpp	Sun Dec 22 17:51:18 2002
@@ -209,7 +209,7 @@
 	loader.load(type_name);
 }
 
-int file_selector(const struct dirent* my_dirent)
+int file_selector(struct dirent* my_dirent)
 {
 	string filename = my_dirent->d_name;
 	string wanted_ending = '.' + DynamicLoaderBase::mapfile_extension();
