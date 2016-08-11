--- software/tulip/src/main.cpp.orig	2016-07-07 20:15:40 UTC
+++ software/tulip/src/main.cpp
@@ -124,7 +124,9 @@ void checkTulipRunning(const QString& pe
 }
 
 int main(int argc, char **argv) {
+#ifndef __FreeBSD__
   CrashHandling::installCrashHandler();
+#endif
 
   QApplication tulip_agent(argc, argv);
   QString name("Tulip ");
