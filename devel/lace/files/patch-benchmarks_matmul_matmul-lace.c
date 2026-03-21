--- benchmarks/matmul/matmul-lace.c.orig	2026-03-06 23:32:42 UTC
+++ benchmarks/matmul/matmul-lace.c
@@ -115,7 +115,7 @@ int main(int argc, char *argv[])
     int workers = 1;
     int dqsize = 100000;
 
-    int c;
+    signed int c;
     while ((c=getopt(argc, argv, "w:q:h")) != -1) {
         switch (c) {
             case 'w':
