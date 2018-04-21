--- apps/lasinfo12.c.orig	2009-10-02 17:48:41 UTC
+++ apps/lasinfo12.c
@@ -31,40 +31,40 @@ void print_header(FILE *file, LASHeaderH header, const
 void usage()
 {
     fprintf(stderr,"----------------------------------------------------------\n");
-    fprintf(stderr,"    lasinfo (version %s) usage:\n", LAS_GetVersion());
+    fprintf(stderr,"    lasinfo12 (version %s) usage:\n", LAS_GetVersion());
     fprintf(stderr,"----------------------------------------------------------\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Printing simple header info:\n");
-    fprintf(stderr,"  lasinfo lidar.las\n");
+    fprintf(stderr,"  lasinfo12 lidar.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Checking point information:\n");
-    fprintf(stderr,"  lasinfo --input lidar.las --check\n");
+    fprintf(stderr,"  lasinfo12 --input lidar.las --check\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Print header info and point summary and redirect output to a file:\n");
-    fprintf(stderr,"  lasinfo --check --input lidar.las 2> output.txt\n");
+    fprintf(stderr,"  lasinfo12 --check --input lidar.las 2> output.txt\n");
     fprintf(stderr,"\n");
     
     fprintf(stderr,"Read from stdin, scan the points, and skip printing VLR info:\n");
-    fprintf(stderr,"  lasinfo --stdin --check --skip_vlr < lidar.las\n");
+    fprintf(stderr,"  lasinfo12 --stdin --check --skip_vlr < lidar.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Repairing header info to reflect point data:\n");
-    fprintf(stderr,"  lasinfo -i lidar.las --repair\n");
+    fprintf(stderr,"  lasinfo12 -i lidar.las --repair\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Altering header info:\n");
-    fprintf(stderr, "  lasinfo -i lidar.las --system_identifier \"hello world!\" "
+    fprintf(stderr, "  lasinfo12 -i lidar.las --system_identifier \"hello world!\" "
                     "--generating_software \"this is a test (-:\"  --file_creation 8 2007\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Print this output:\n");
-    fprintf(stderr, "  lasinfo --help\n");
+    fprintf(stderr, "  lasinfo12 --help\n");
     fprintf(stderr,"\n");
     
-    fprintf(stderr, "\nFor more information, see the full documentation for lasinfo at:\n"
+    fprintf(stderr, "\nFor more information, see the full documentation for lasinfo12 at:\n"
                     " http://liblas.org/browser/trunk/doc/lasinfo.txt\n");
     fprintf(stderr,"----------------------------------------------------------\n");
 
