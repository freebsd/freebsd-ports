--- src/ime-core/imi_winHandler.cpp.orig	2014-11-14 14:17:48 UTC
+++ src/ime-core/imi_winHandler.cpp
@@ -87,6 +87,7 @@ CIMIWinHandler::throwBackKey(unsigned ke
 void
 CIMIWinHandler::updateStatus(int key, int value)
 {
+#ifdef DEBUG
     switch (key) {
     case STATUS_ID_CN:
         printf("CN status is "); break;
@@ -101,6 +102,7 @@ CIMIWinHandler::updateStatus(int key, in
 
     printf("%d\n", value);
     fflush(stdout);
+#endif
 }
 
 // -*- indent-tabs-mode: nil -*- vim:et:ts=4
