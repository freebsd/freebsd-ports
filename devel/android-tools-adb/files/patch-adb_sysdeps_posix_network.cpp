--- adb/sysdeps/posix/network.cpp.orig	2017-06-20 10:50:27 UTC
+++ adb/sysdeps/posix/network.cpp
@@ -17,6 +17,7 @@
 #include "sysdeps/network.h"
 
 #include <errno.h>
+#include <string.h> // strerror
 #include <netinet/in.h>
 #include <sys/socket.h>
 
