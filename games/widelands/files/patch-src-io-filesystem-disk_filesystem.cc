--- src/io/filesystem/disk_filesystem.cc.orig	2011-04-15 22:40:26.000000000 +0400
+++ src/io/filesystem/disk_filesystem.cc	2011-05-25 00:53:00.000000000 +0400
@@ -436,10 +436,10 @@
 	int file = 0;
 	void * data = 0;
 
-#ifdef __APPLE__
-	file = open(fullname.c_str(), O_RDONLY);
-#else
+#ifdef __linux__
 	file = open(fullname.c_str(), O_RDONLY|O_NOATIME);
+#else
+	file = open(fullname.c_str(), O_RDONLY);
 #endif
 	length = lseek(file, 0, SEEK_END);
 	lseek(file, 0, SEEK_SET);
