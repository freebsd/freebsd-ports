--- native/net/http_headers.cpp.orig	2015-02-23 23:22:58 UTC
+++ native/net/http_headers.cpp
@@ -1,11 +1,5 @@
 #include "net/http_headers.h"
 
-#ifdef _WIN32
-
-#include <winsock2.h>   // for timeval
-
-#endif
-
 #include <stdio.h>
 #include <stdlib.h>
 
@@ -132,11 +126,6 @@ int RequestHeader::ParseHttpHeader(const
 }
 
 void RequestHeader::ParseHeaders(int fd) {
-  // Get the request, with a timeout.
-  struct ::timeval tv;
-  tv.tv_sec = 5;
-  tv.tv_usec = 0;
-
   int line_count = 0;
   // Loop through request headers.
   while (true) {
