Fix tiff2ps error regarding "Inconsistent value of es" by allowing es to be zero. 

--- tools/tiff2ps.c.orig	2018-11-03 19:25:46 UTC
+++ tools/tiff2ps.c
@@ -2444,9 +2444,9 @@ PSDataColorContig(FILE* fd, TIFF* tif, u
 	unsigned char *cp, c;
 
 	(void) w;
-        if( es <= 0 )
+        if( es < 0 )
         {
-            TIFFError(filename, "Inconsistent value of es: %d", es);
+            TIFFError(filename, "Inconsistent value of es: %d (samplesperpixel=%u, nc=%d)", es, samplesperpixel, nc);
             return;
         }
 	tf_buf = (unsigned char *) _TIFFmalloc(tf_bytesperrow);
