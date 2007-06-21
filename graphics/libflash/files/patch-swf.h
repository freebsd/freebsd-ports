--- lib/swf.h	Fri May 25 15:04:22 2007
+++ lib2/swf.h	Fri May 25 15:08:36 2007
@@ -199,7 +199,9 @@
 #define true 1
 #endif
 
+extern "C" {
 extern int shape_size,shape_nb,shaperecord_size,shaperecord_nb,style_size,style_nb;
+};
 
 typedef void (*ScanLineFunc)(void *id, long y, long start, long end);
 
