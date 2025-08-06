--- benchmarks/dfs/dfs-lace.c.orig	2025-05-23 10:54:05 UTC
+++ benchmarks/dfs/dfs-lace.c
@@ -50,7 +50,7 @@ int main(int argc, char **argv)
     int workers = 1;
     int dqsize = 100000;
 
-    char c;
+    signed char c;
     while ((c=getopt(argc, argv, "w:q:h")) != -1) {
         switch (c) {
             case 'w':
