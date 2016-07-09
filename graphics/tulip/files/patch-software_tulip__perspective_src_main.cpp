--- software/tulip_perspective/src/main.cpp.orig	2016-07-07 20:15:39 UTC
+++ software/tulip_perspective/src/main.cpp
@@ -135,7 +135,9 @@ void usage(const QString &error) {
 
 int main(int argc,char **argv) {
 
+#ifndef __FreeBSD__
   CrashHandling::installCrashHandler();
+#endif
 
   QString appName("Tulip ");
   QString iconPath;
