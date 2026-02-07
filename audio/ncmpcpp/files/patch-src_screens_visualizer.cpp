--- src/screens/visualizer.cpp.orig	2021-01-19 19:47:11 UTC
+++ src/screens/visualizer.cpp
@@ -33,6 +33,9 @@
 #include <fcntl.h>
 #include <netdb.h>
 #include <cassert>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #include "global.h"
 #include "settings.h"
