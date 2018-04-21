--- apps/txt2las12.c.orig	2009-10-02 17:48:41 UTC
+++ apps/txt2las12.c
@@ -24,20 +24,20 @@ void usage()
 {
 
     fprintf(stderr,"----------------------------------------------------------\n");
-    fprintf(stderr,"    txt2las (version %s) usage:\n", LAS_GetVersion());
+    fprintf(stderr,"    txt2las12 (version %s) usage:\n", LAS_GetVersion());
     fprintf(stderr,"----------------------------------------------------------\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Parse a text file with a given format:\n");
-    fprintf(stderr,"  txt2las -parse tsxyz lidar.txt\n");
+    fprintf(stderr,"  txt2las12 -parse tsxyz lidar.txt\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Set the scale:\n");
-    fprintf(stderr,"  txt2las --parse xyz --scale 0.02 -i lidar.txt -o lidar.laz\n");
+    fprintf(stderr,"  txt2las12 --parse xyz --scale 0.02 -i lidar.txt -o lidar.laz\n");
     fprintf(stderr,"\n");
     
     fprintf(stderr,"Set the xyz scale:\n");
-    fprintf(stderr,"  txt2las --parse xsysz --verbose --xyz_scale 0.02 0.02 0.01 lidar.txt\n");
+    fprintf(stderr,"  txt2las12 --parse xsysz --verbose --xyz_scale 0.02 0.02 0.01 lidar.txt\n");
     fprintf(stderr,"\n");
     
     fprintf(stderr,"----------------------------------------------------------\n");
@@ -74,7 +74,7 @@ void usage()
     fprintf(stderr," or '-system_identifier \"Airborne One Leica 50,000 Hz\"'\n");
     fprintf(stderr," or '-generating_software \"TerraScan\"' are available too.\n");
 
-    fprintf(stderr, "For more information, see the full documentation for txt2las at:\n"
+    fprintf(stderr, "For more information, see the full documentation for txt2las12 at:\n"
                     " http://liblas.org/browser/trunk/doc/txt2las.txt\n");
     fprintf(stderr,"----------------------------------------------------------\n");
 
