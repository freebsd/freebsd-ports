
$FreeBSD$

--- libplot/g_write.c.orig	Fri May 19 11:10:01 2000
+++ libplot/g_write.c	Thu Aug  7 11:48:12 2003
@@ -40,7 +40,7 @@
     }
 #ifdef LIBPLOTTER
   else if (data->outstream)
-    data->outstream->write(c, n);
+    data->outstream->write((const char*)c, n);
 #endif
 }
 
