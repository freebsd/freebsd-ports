--- H/remote.h.orig	2015-09-29 11:13:27 UTC
+++ H/remote.h
@@ -42,7 +42,10 @@
     #ifdef MACOSX
       #include <net/if.h>
     #endif
-    #ifdef LINUX
+    #ifdef __FreeBSD__
+      #include <net/if.h>
+    #endif
+    #ifdef linux
       #include <linux/if.h>
     #endif
     #include <arpa/inet.h>
