--- Src/posix.c.orig	Sat Mar 27 05:00:55 2004
+++ Src/posix.c	Tue Mar 30 02:47:55 2004
@@ -89,13 +89,15 @@
 
 int plat_findLib(const char* lib, char* buffer, int size)
 {
+	FILE* file;
+
 	if (findLib(lib, "/usr/lib"))
 	{
 		strcpy(buffer, "/usr/lib");
 		return 1;
 	}
 
-	FILE* file = fopen("/etc/ld.so.conf", "rt");
+	file = fopen("/etc/ld.so.conf", "rt");
 	if (file == NULL) return 0;
 
 	while (!feof(file))
