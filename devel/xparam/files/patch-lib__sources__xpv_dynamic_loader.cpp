--- lib/sources/xpv_dynamic_loader.cpp.orig	Sun Nov 25 03:43:26 2001
+++ lib/sources/xpv_dynamic_loader.cpp	Sat Dec 28 10:59:43 2002
@@ -209,7 +209,7 @@
 	loader.load(type_name);
 }
 
-int file_selector(const struct dirent* my_dirent)
+int file_selector(struct dirent* my_dirent)
 {
 	string filename = my_dirent->d_name;
 	string wanted_ending = '.' + DynamicLoaderBase::mapfile_extension();
