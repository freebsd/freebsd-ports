--- ./src/ime-core/imi_winHandler.cpp~	2011-02-17 21:39:52.000000000 -0600
+++ ./src/ime-core/imi_winHandler.cpp	2011-11-11 02:29:45.163309361 -0600
@@ -85,6 +85,7 @@ CIMIWinHandler::throwBackKey(unsigned ke
 void
 CIMIWinHandler::updateStatus(int key, int value)
 {
+#ifdef DEBUG
     switch (key) {
     case STATUS_ID_CN:
         printf("CN status is "); break;
@@ -99,4 +100,5 @@ CIMIWinHandler::updateStatus(int key, in
 
     printf("%d\n", value);
     fflush(stdout);
+#endif
 }
