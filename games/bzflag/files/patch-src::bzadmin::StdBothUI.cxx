--- src/bzadmin/StdBothUI.cxx.orig	Tue Jan 18 18:28:44 2005
+++ src/bzadmin/StdBothUI.cxx	Wed Jan 19 00:05:11 2005
@@ -20,6 +20,7 @@
 #include <ws2tcpip.h>
 #include <wincon.h>
 #else
+#include <sys/types.h>
 #include <sys/select.h>
 #endif
 
