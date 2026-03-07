--- benchmarks/pi/pi-lace.c.orig	2026-03-06 23:32:42 UTC
+++ benchmarks/pi/pi-lace.c
@@ -53,7 +53,7 @@ int main(int argc, char **argv)
     int workers = 0;
     int dqsize = 1000000;
 
-    int c;
+    signed int c;
     while ((c=getopt(argc, argv, "w:q:h")) != -1) {
         switch (c) {
             case 'w':
