--- gramdc/gramdclient.cpp.orig	2012-03-21 00:49:18.000000000 +0000
+++ gramdc/gramdclient.cpp
@@ -7,6 +7,7 @@
 
 #include "gramdclient.h"
 
+#include <sys/select.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <netinet/in.h>
