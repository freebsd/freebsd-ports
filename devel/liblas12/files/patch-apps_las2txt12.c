--- apps/las2txt12.c.orig	2009-10-02 17:48:41 UTC
+++ apps/las2txt12.c
@@ -23,20 +23,20 @@ void print_header(FILE *file, LASHeaderH header, const
 void usage()
 {
     fprintf(stderr,"----------------------------------------------------------\n");
-    fprintf(stderr,"    las2txt (version %s) usage:\n", LAS_GetVersion());
+    fprintf(stderr,"    las2txt12 (version %s) usage:\n", LAS_GetVersion());
     fprintf(stderr,"----------------------------------------------------------\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Convert a las file to text on stdout:\n");
-    fprintf(stderr,"  las2txt lidar.las\n");
+    fprintf(stderr,"  las2txt12 lidar.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Convert using stdin and stdout:\n");
-    fprintf(stderr,"  las2txt --stdin --stdout < lidar.las > lidar.txt\n");
+    fprintf(stderr,"  las2txt12 --stdin --stdout < lidar.las > lidar.txt\n");
     fprintf(stderr,"\n");
     
     fprintf(stderr,"Convert to text with a specified format :\n");
-    fprintf(stderr,"  las2txt --parse xyziar lidar.las lidar.txt\n");
+    fprintf(stderr,"  las2txt12 --parse xyziar lidar.las lidar.txt\n");
     fprintf(stderr,"\n");
 
     
@@ -73,7 +73,7 @@ void usage()
     fprintf(stderr," possible are 'percent', 'dollar', 'semicolon', 'komma',\n");
     fprintf(stderr," 'star', 'colon', or 'semicolon' as that special character.\n");
 
-    fprintf(stderr, "\nFor more information, see the full documentation for las2txt at:\n"
+    fprintf(stderr, "\nFor more information, see the full documentation for las2txt12 at:\n"
                     " http://liblas.org/browser/trunk/doc/las2txt.txt\n");
     fprintf(stderr,"----------------------------------------------------------\n");
 
