--- src/main.cc.orig	2012-04-23 13:46:49.000000000 +0400
+++ src/main.cc	2013-09-13 22:45:51.418226482 +0400
@@ -34,6 +34,7 @@
 #ifndef WIN32
 #include <syslog.h>
 #include <fcntl.h>
+#include <unistd.h>
 #endif
 
 using std::cerr;
