--- src/servers.h.orig	2003-10-01 16:58:27 UTC
+++ src/servers.h
@@ -28,6 +28,12 @@
 
 #include <string>
 #include <sstream>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+#ifdef BSD
+#include <netinet/in.h>
+#endif
 
 #include "aprsd.h"
 #include "mutex.h"
@@ -135,11 +141,17 @@ struct pidList{
 
 
 //Stuff for trusted UDP source IPs
+#ifdef BSD
 struct sTrusted {
+    struct in_addr sin_addr;   //ip address
+    struct in_addr sin_mask;   //subnet mask
+};
+#else
+struct sTrusted {
     in_addr sin_addr;   //ip address
     in_addr sin_mask;   //subnet mask
 };
-
+#endif
 
 struct sLogon{ 
     char *user;
