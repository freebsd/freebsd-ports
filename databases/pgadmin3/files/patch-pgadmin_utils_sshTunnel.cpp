--- pgadmin/utils/sshTunnel.cpp.orig	2016-02-08 10:25:13 UTC
+++ pgadmin/utils/sshTunnel.cpp
@@ -19,7 +19,9 @@
 #include "utils/sshTunnel.h"
 #include "frm/frmMain.h"
 
+#ifdef WIN32
 #pragma comment (lib, "Ws2_32.lib")
+#endif
 
 typedef const char *(*inet_ntop_t) (int af, const void *src, char *dst, socklen_t size);
 
