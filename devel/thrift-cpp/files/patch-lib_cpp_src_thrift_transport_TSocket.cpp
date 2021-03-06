--- lib/cpp/src/thrift/transport/TSocket.cpp.orig	2021-03-05 22:48:17 UTC
+++ lib/cpp/src/thrift/transport/TSocket.cpp
@@ -460,7 +460,7 @@ void TSocket::local_open() {
 #ifdef _WIN32
       error == WSANO_DATA
 #else
-      error == EAI_NODATA
+      error == EAI_NONAME
 #endif
     ) {
     hints.ai_flags &= ~AI_ADDRCONFIG;
