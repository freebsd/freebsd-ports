
$FreeBSD$

--- view3ds/document.cpp	2002/04/24 11:23:51	1.1
+++ view3ds/document.cpp	2002/04/24 11:24:33
@@ -42,7 +42,9 @@
 Document::~Document()
 {
   if (d_file) {
+#if 0
     lib3ds_close(d_file);
+#endif
     d_file=0;
   }
 }
@@ -55,17 +57,21 @@
 Document::open(QString filename)
 {
   if (d_file) {
+#if 0
     lib3ds_close(d_file);
+#endif
     d_file=0;
   }
-  d_file=lib3ds_open((const char*)filename);
+  d_file=lib3ds_file_load((const char*)filename);
   if (!d_file) {
     puts("***ERROR*** Loading 3DS file failed.");
     return(false);
   }
   if (!d_file->cameras) {
     puts("***ERROR*** No Camera found.");
+#if 0
     lib3ds_close(d_file);
+#endif
     d_file=0;
     return(false);
   }
