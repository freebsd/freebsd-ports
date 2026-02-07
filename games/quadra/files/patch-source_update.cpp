--- source/update.cpp.orig	2018-07-07 17:27:09 UTC
+++ source/update.cpp
@@ -80,8 +80,8 @@ void AutoUpdaterImpl::init() {
   }
 
   buf.resize(0);
-  buf.append("GET "UPDATE_PATH" HTTP/1.0\r\n");
-  buf.append("Host: "UPDATE_HOST"\r\n");
+  buf.append("GET " UPDATE_PATH " HTTP/1.0\r\n");
+  buf.append("Host: " UPDATE_HOST "\r\n");
   buf.append("Connection: close\r\n");
   snprintf(st, sizeof(st), "User-Agent: Quadra/%s\r\n", VERSION_STRING);
   buf.append(st);
