--- assa/Socket.cpp.orig	Wed Dec 24 17:28:22 2003
+++ assa/Socket.cpp	Wed Dec 24 17:28:36 2003
@@ -16,6 +16,7 @@
 
 #include <sstream>
 #include <rpc/rpc.h>
+#include <sys/ioctl.h>
 
 #include "assa/Socket.h"
 
