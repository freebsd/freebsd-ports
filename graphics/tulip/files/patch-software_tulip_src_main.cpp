--- software/tulip/src/main.cpp.orig	2015-04-22 14:45:04 UTC
+++ software/tulip/src/main.cpp
@@ -124,7 +124,9 @@ void checkTulipRunning(const QString& pe
 }
 
 int main(int argc, char **argv) {
+#ifndef __FreeBSD__
   start_crash_handler();
+#endif
 
   QApplication tulip_agent(argc, argv);
   QString name("Tulip ");
