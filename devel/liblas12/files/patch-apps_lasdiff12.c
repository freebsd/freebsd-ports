--- apps/lasdiff12.c.orig	2009-10-02 17:48:41 UTC
+++ apps/lasdiff12.c
@@ -26,15 +26,15 @@
 void usage()
 {
     fprintf(stderr,"----------------------------------------------------------\n");
-    fprintf(stderr,"    lasdiff (version %s) usage:\n", LAS_GetVersion());
+    fprintf(stderr,"    lasdiff12 (version %s) usage:\n", LAS_GetVersion());
     fprintf(stderr,"----------------------------------------------------------\n");
     fprintf(stderr,"\n");
 
-    fprintf(stderr,"lasdiff lidar1.las lidar2.las\n");
-    fprintf(stderr,"lasdiff lidar1.las lidar1.las.lz\n");
-    fprintf(stderr,"lasdiff -i lidar1.las -i lidar1.laz\n");
-    fprintf(stderr,"lasdiff -h\n");
-    fprintf(stderr, "\nFor more information, see the full documentation for lasdiff at:\n"
+    fprintf(stderr,"lasdiff12 lidar1.las lidar2.las\n");
+    fprintf(stderr,"lasdiff12 lidar1.las lidar1.las.lz\n");
+    fprintf(stderr,"lasdiff12 -i lidar1.las -i lidar1.laz\n");
+    fprintf(stderr,"lasdiff12 -h\n");
+    fprintf(stderr, "\nFor more information, see the full documentation for lasdiff12 at:\n"
                     " http://liblas.org/browser/trunk/doc/lasdiff.txt\n");
     fprintf(stderr,"----------------------------------------------------------\n");
 }
