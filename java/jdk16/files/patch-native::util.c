$FreeBSD$

--- ../../deploy/src/javaws/src/share/native/util.c	22 Oct 2003 23:04:17 -0000	1.1.1.1
+++ ../../deploy/src/javaws/src/share/native/util.c	16 Jan 2004 23:50:11 -0000
@@ -27,7 +27,10 @@
 
     /* Find size of file */
     struct stat statBuf;
-    stat(filename,  &statBuf);
+    if (stat(filename,  &statBuf) == -1) {
+        *buffer = NULL;
+        return 0;
+    }
     size = statBuf.st_size;
     
     /* Allocate memory for contents */
