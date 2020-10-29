--- include/microdns/rr.h.orig	2020-10-29 02:44:44 UTC
+++ include/microdns/rr.h
@@ -35,6 +35,8 @@
 # include <ws2tcpip.h>
 #endif
 
+#include <netinet/in.h>
+
 # ifdef __cplusplus
 extern "C" {
 # endif
