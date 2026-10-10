--- src/mongo/util/net/http_client_curl.cpp.orig	2026-09-29 00:00:00 UTC
+++ src/mongo/util/net/http_client_curl.cpp
@@ -62,6 +62,7 @@
 #include <string_view>
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <curl/curl.h>
 #include <curl/easy.h>
 
