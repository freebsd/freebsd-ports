--- src/io/inkjar.h.orig	2013-10-16 23:34:39.000000000 +0200
+++ src/io/inkjar.h	2013-10-16 23:35:52.000000000 +0200
@@ -27,6 +27,7 @@
 #endif
 
 #include <glib.h>
+#include <stdio.h>
 
 namespace Inkjar {
 
@@ -91,7 +92,7 @@
 class JarFile {
 public:
 
-    JarFile() : fd(-1), _filename(NULL), _last_filename(NULL) {}
+    JarFile() : fd(NULL), _filename(NULL), _last_filename(NULL) {}
     virtual ~JarFile();
     JarFile(gchar const *new_filename);
     
@@ -106,7 +107,7 @@
 
 private:
 
-    int fd;
+    FILE* fd;
     gchar *_filename;
     z_stream _zs;
     gchar *_last_filename;
