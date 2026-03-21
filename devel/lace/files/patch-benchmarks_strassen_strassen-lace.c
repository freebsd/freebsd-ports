--- benchmarks/strassen/strassen-lace.c.orig	2026-03-06 23:32:42 UTC
+++ benchmarks/strassen/strassen-lace.c
@@ -706,7 +706,7 @@ int main(int argc, char *argv[])
     int verify = 0;
     int n = 4096;
 
-    int c;
+    signed int c;
     while ((c=getopt(argc, argv, "w:q:h:c")) != -1) {
         switch (c) {
             case 'w':
