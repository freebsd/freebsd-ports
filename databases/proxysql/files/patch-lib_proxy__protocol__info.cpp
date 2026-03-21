--- lib/proxy_protocol_info.cpp.orig	2025-11-08 01:35:22 UTC
+++ lib/proxy_protocol_info.cpp
@@ -3,6 +3,9 @@
 #include <stdio.h>
 #include <assert.h>
 #include <iostream>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 static bool DEBUG_ProxyProtocolInfo = false;
 
