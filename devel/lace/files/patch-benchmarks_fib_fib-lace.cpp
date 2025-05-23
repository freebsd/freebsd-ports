--- benchmarks/fib/fib-lace.cpp.orig	2025-05-23 10:53:18 UTC
+++ benchmarks/fib/fib-lace.cpp
@@ -35,7 +35,7 @@ int main(int argc, char **argv)
     int workers = 1;
     int dqsize = 100000;
 
-    char c;
+    signed char c;
     while ((c=getopt(argc, argv, "w:q:h")) != -1) {
         switch (c) {
             case 'w':
