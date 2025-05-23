--- benchmarks/strassen/strassen-lace.c.orig	2025-05-23 10:55:02 UTC
+++ benchmarks/strassen/strassen-lace.c
@@ -718,7 +718,7 @@ int main(int argc, char *argv[])
     int dqsize = 100000;
     int verify = 0;
 
-    char c;
+    signed char c;
     while ((c=getopt(argc, argv, "w:q:h:c")) != -1) {
         switch (c) {
             case 'w':
