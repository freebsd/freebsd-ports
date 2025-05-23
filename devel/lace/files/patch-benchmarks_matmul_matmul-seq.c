--- benchmarks/matmul/matmul-seq.c.orig	2025-05-23 10:55:39 UTC
+++ benchmarks/matmul/matmul-seq.c
@@ -114,7 +114,7 @@ int main(int argc, char *argv[])
 
 int main(int argc, char *argv[])
 {
-    char c;
+    signed char c;
     while ((c=getopt(argc, argv, "w:q:h")) != -1) {
         switch (c) {
             case 'h':
