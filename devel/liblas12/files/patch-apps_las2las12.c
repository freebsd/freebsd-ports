--- apps/las2las12.c.orig	2009-10-02 17:48:41 UTC
+++ apps/las2las12.c
@@ -32,44 +32,44 @@ void repair_header(FILE *file, LASHeaderH header, LASP
 void usage()
 {
     fprintf(stderr,"----------------------------------------------------------\n");
-    fprintf(stderr,"    las2las (version %s) usage:\n", LAS_GetVersion());
+    fprintf(stderr,"    las2las12 (version %s) usage:\n", LAS_GetVersion());
     fprintf(stderr,"----------------------------------------------------------\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Clip las file to a bounding box, throwing out points that have invalid data:\n");
-    fprintf(stderr,"  las2las -i in.las -clip 63000000 483450000 63050000 483500000 -o out.las --skip_invalid\n");
+    fprintf(stderr,"  las2las12 -i in.las -clip 63000000 483450000 63050000 483500000 -o out.las --skip_invalid\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Read from stdin, eliminate intensities below 2000, and write to stdout:\n");
-    fprintf(stderr,"  las2las --eliminate_intensity_below 2000 --stdin --stdout < in.las > out.las \n");
+    fprintf(stderr,"  las2las12 --eliminate_intensity_below 2000 --stdin --stdout < in.las > out.las \n");
     fprintf(stderr,"\n");
     
     fprintf(stderr,"Eliminate return number two:\n");
-    fprintf(stderr,"  las2las -i in.las -eliminate_return 2 -o out.las\n");
+    fprintf(stderr,"  las2las12 -i in.las -eliminate_return 2 -o out.las\n");
     fprintf(stderr,"\n");
     
     fprintf(stderr,"Eliminate scan angles above 15:\n");
-    fprintf(stderr,"  las2las -i in.las -eliminate_scan_angle_above 15 -o out.las\n");
+    fprintf(stderr,"  las2las12 -i in.las -eliminate_scan_angle_above 15 -o out.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Eliminate intensities below 1000:\n");
-    fprintf(stderr,"  las2las -i in.las -eliminate_intensity_below 1000 --stdout > out.las\n");
+    fprintf(stderr,"  las2las12 -i in.las -eliminate_intensity_below 1000 --stdout > out.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Eliminate intensities below 1000 and classifications that equal 2 (ground):\n");
-    fprintf(stderr,"  las2las -i in.las --eliminate_class 2 --out out.las\n");
+    fprintf(stderr,"  las2las12 -i in.las --eliminate_class 2 --out out.las\n");
     fprintf(stderr,"\n");
         
     fprintf(stderr,"Capture only first returns and clip to bounding box:\n");
-    fprintf(stderr,"  las2las -i in.las -first_only -clip 63000000 483450000 63050000 483500000 -o out.las\n");
+    fprintf(stderr,"  las2las12 -i in.las -first_only -clip 63000000 483450000 63050000 483500000 -o out.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Capture only last returns, eliminate intensities below 2000, and write to stdout:\n");
-    fprintf(stderr,"  las2las --input in.las --last_only --eliminate_intensity_below 2000 --stdout > out.las\n");
+    fprintf(stderr,"  las2las12 --input in.las --last_only --eliminate_intensity_below 2000 --stdout > out.las\n");
     fprintf(stderr,"\n");
 
 
-    fprintf(stderr, "\nFor more information, see the full documentation for las2las at:\n"
+    fprintf(stderr, "\nFor more information, see the full documentation for las2las12 at:\n"
                     " http://liblas.org/browser/trunk/doc/las2las.txt\n");
     fprintf(stderr,"----------------------------------------------------------\n");
 
