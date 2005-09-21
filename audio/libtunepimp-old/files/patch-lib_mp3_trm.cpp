--- lib/mp3_trm.cpp.orig	Sat Aug 14 23:35:41 2004
+++ lib/mp3_trm.cpp	Sat Aug 14 23:35:55 2004
@@ -82,6 +82,7 @@
 #ifdef WIN32
 #include <winsock.h>
 #else
+#include <sys/types.h>
 #include <netinet/in.h>
 #endif
 
