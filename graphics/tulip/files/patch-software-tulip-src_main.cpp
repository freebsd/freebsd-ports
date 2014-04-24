--- software/tulip/src/main.cpp.orig	2014-04-18 11:56:26.000000000 +0200
+++ software/tulip/src/main.cpp	2014-04-18 11:56:38.000000000 +0200
@@ -119,7 +119,9 @@
 }
 
 int main(int argc, char **argv) {
+#ifndef __FreeBSD__
   start_crash_handler();
+#endif
 
 
 
