--- benchmarks/fib/fib-lace.c.orig	2025-05-23 10:55:18 UTC
+++ benchmarks/fib/fib-lace.c
@@ -34,7 +34,7 @@ int main(int argc, char **argv)
     int workers = 1;
     int dqsize = 100000;
 
-    char c;
+    signed char c;
     while ((c=getopt(argc, argv, "w:q:h")) != -1) {
         switch (c) {
             case 'w':
