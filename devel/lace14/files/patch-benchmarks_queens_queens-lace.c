--- benchmarks/queens/queens-lace.c.orig	2025-05-23 10:53:37 UTC
+++ benchmarks/queens/queens-lace.c
@@ -73,7 +73,7 @@ int main(int argc, char *argv[])
     int workers = 1;
     int dqsize = 100000;
 
-    char c;
+    signed char c;
     while ((c=getopt(argc, argv, "w:q:h")) != -1) {
         switch (c) {
             case 'w':
