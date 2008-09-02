--- ./konversation/src/dcccommon.cpp.orig	2008-08-06 19:56:27.000000000 +0400
+++ ./konversation/src/dcccommon.cpp	2008-08-16 21:11:14.000000000 +0400
@@ -15,6 +15,7 @@
 #include "server.h"
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #include <qhostaddress.h>
 
