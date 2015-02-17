--- H/remote.h.orig
+++ H/remote.h
@@ -37,7 +37,10 @@
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
