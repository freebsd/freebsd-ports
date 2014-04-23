--- software/tulip_perspective/src/main.cpp.orig	2014-04-18 11:58:12.000000000 +0200
+++ software/tulip_perspective/src/main.cpp	2014-04-18 11:58:27.000000000 +0200
@@ -129,7 +129,9 @@
 }
 
 int main(int argc,char **argv) {
+#ifndef __FreeBSD__
   start_crash_handler();
+#endif
 
   QString appName("Tulip ");
   QString iconPath;
