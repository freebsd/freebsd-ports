--- apps/lasmerge12.c.orig	2009-10-02 17:48:41 UTC
+++ apps/lasmerge12.c
@@ -27,39 +27,39 @@ void usage()
 {
 
     fprintf(stderr,"----------------------------------------------------------\n");
-    fprintf(stderr,"    lasmerge (version %s) usage:\n", LAS_GetVersion());
+    fprintf(stderr,"    lasmerge12 (version %s) usage:\n", LAS_GetVersion());
     fprintf(stderr,"----------------------------------------------------------\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Merge using a list of files:\n");
-    fprintf(stderr,"  lasmerge -i lasfiles.txt -o out.las\n");
+    fprintf(stderr,"  lasmerge12 -i lasfiles.txt -o out.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Manually list files to merge:\n");
-    fprintf(stderr,"  lasmerge -i file1.las -i file2.las -i file3.las -o out.las\n");
+    fprintf(stderr,"  lasmerge12 -i file1.las -i file2.las -i file3.las -o out.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Merge to stdout:\n");
-    fprintf(stderr,"  lasmerge -i file1.las -i file2.las --stdout\n");
+    fprintf(stderr,"  lasmerge12 -i file1.las -i file2.las --stdout\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Merge and set scale:\n");
-    fprintf(stderr, "  lasmerge --input lasfiles.txt --scale 0.01 --output out.las\n");
+    fprintf(stderr, "  lasmerge12 --input lasfiles.txt --scale 0.01 --output out.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Merge and set scale individually:\n");
-    fprintf(stderr, "  lasmerge --input lasfiles.txt --xyz_scale 0.01 0.01 0.1 --output out.las\n");
+    fprintf(stderr, "  lasmerge12 --input lasfiles.txt --xyz_scale 0.01 0.01 0.1 --output out.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Merge and set offset individually:\n");
-    fprintf(stderr, "  lasmerge --input lasfiles.txt --xyz_offset 0.01 0.01 0.1 --output out.las\n");
+    fprintf(stderr, "  lasmerge12 --input lasfiles.txt --xyz_offset 0.01 0.01 0.1 --output out.las\n");
     fprintf(stderr,"\n");
 
     fprintf(stderr,"Print this output:\n");
-    fprintf(stderr, "  lasmerge --help\n");
+    fprintf(stderr, "  lasmerge12 --help\n");
     fprintf(stderr,"\n");
     
-    fprintf(stderr, "For more information, see the full documentation for lasmerge at:\n"
+    fprintf(stderr, "For more information, see the full documentation for lasmerge12 at:\n"
                     " http://liblas.org/browser/trunk/doc/lasmerge.txt\n");
     fprintf(stderr,"----------------------------------------------------------\n");
 
