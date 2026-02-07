--- pixmap.c.orig	2003-03-17 01:32:40.000000000 +0300
+++ pixmap.c	2013-08-28 22:15:03.677227606 +0400
@@ -390,7 +390,7 @@
 		  likes it in the file.  Still need to fix this in autoconf,
                   but for now this will do. */
 #if !defined (WIN32)
-inline int 
+int 
 pixmap_index (int x, int y)
 {
     return y*pixmap_width + x;
