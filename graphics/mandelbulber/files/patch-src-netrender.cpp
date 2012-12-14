--- src/netrender.cpp.orig	2012-12-02 20:22:54.000000000 +0400
+++ src/netrender.cpp	2012-12-13 01:06:24.748933214 +0400
@@ -7,6 +7,7 @@
 
 #include "netrender.hpp"
 #include <stdio.h>
+#include <netinet/in.h>
 #ifndef WIN32
 #include <arpa/inet.h>
 #endif
