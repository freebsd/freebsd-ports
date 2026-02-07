--- benchmarks/pi/pi-lace.c.orig	2025-05-23 10:54:23 UTC
+++ benchmarks/pi/pi-lace.c
@@ -55,7 +55,7 @@ int main(int argc, char **argv)
     int workers = 0;
     int dqsize = 1000000;
 
-    char c;
+    signed char c;
     while ((c=getopt(argc, argv, "w:q:h")) != -1) {
         switch (c) {
             case 'w':
