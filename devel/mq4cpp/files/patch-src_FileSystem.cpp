--- src/FileSystem.cpp.orig	Sat Mar 17 09:51:21 2007
+++ src/FileSystem.cpp	Sat Jun 23 09:45:31 2007
@@ -354,7 +354,11 @@
 	Directory* ret=new Directory(path);
 	ret->search();
 #else
+#ifdef __FreeBSD__
+	char* ptr=getcwd (NULL, PATH_MAX);
+#else
 	char* ptr=get_current_dir_name();
+#endif
 	TRACE("Current directory=" << ptr)
 	Directory* ret=new Directory(ptr);
 	ret->search();
