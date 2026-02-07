--- indiserver/RemoteDvrInfo.cpp.orig	2025-03-31 09:12:20 UTC
+++ indiserver/RemoteDvrInfo.cpp
@@ -25,6 +25,7 @@
 #include <cstdio>
 #include <netinet/in.h>
 #include <netdb.h>
+#include <sys/socket.h>
 
 using namespace indiserver::constants;
 
