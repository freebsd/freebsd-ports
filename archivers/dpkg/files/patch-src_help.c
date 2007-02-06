--- src/help.c.orig	Sun Jun 18 18:22:03 2006
+++ src/help.c	Mon Nov 13 21:09:32 2006
@@ -73,7 +73,7 @@
 #ifdef WITH_START_STOP_DAEMON
     "start-stop-daemon",
 #endif    
-    "install-info", "update-rc.d", 0
+    "dpkg-install-info", 0
   };
 
   struct stat stab;
