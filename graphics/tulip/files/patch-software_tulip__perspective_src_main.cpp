--- software/tulip_perspective/src/main.cpp.orig	2015-04-18 20:15:52 UTC
+++ software/tulip_perspective/src/main.cpp
@@ -134,7 +134,9 @@ void usage(const QString &error) {
 }
 
 int main(int argc,char **argv) {
+#ifndef __FreeBSD__
   start_crash_handler();
+#endif
 
   QString appName("Tulip ");
   QString iconPath;
