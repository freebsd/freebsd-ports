--- src/wp/ap/unix/ap_UnixApp.cpp.orig	Sat Feb 22 01:21:20 2003
+++ src/wp/ap/unix/ap_UnixApp.cpp	Sat Feb 22 01:21:31 2003
@@ -1241,7 +1241,7 @@
     pMyUnixApp->shutdown();
     delete pMyUnixApp;
     
-    poptFreeContext (Args.poptcon);
+    //poptFreeContext (Args.poptcon);
     return 0;
 }
 
