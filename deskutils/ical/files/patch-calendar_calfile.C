--- calendar/calfile.C.orig	1997-05-24 00:23:52 UTC
+++ calendar/calfile.C
@@ -60,7 +60,7 @@ CalFile::CalFile(int ro, const char* nam
     backupName = tmp;
 
     // Get directory name for access checks
-    char* lastSlash = strrchr(name, '/');
+    const char* lastSlash = strrchr(name, '/');
     if (lastSlash == 0) {
 	/* Calendar is in current directory */
 	tmp = new char[3];
