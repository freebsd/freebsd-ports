--- intel2gas.cc.orig	2007-07-31 20:02:50.000000000 +0200
+++ intel2gas.cc	2007-07-31 20:03:20.000000000 +0200
@@ -57,7 +57,7 @@
   int counter = 0;
   char* prev = 0;
   while (l) {
-    if (int(l->name) > 0x10000000) {
+    if (intptr_t(l->name) > 0x10000000) {
       printf("Error %d, prev=%s\n", counter, prev);
       break;
     }
