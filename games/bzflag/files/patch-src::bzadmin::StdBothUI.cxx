--- src/bzadmin/StdBothUI.cxx.orig	Tue Dec  9 16:38:14 2003
+++ src/bzadmin/StdBothUI.cxx	Thu Dec 11 01:25:29 2003
@@ -20,6 +20,7 @@
 #include <ws2tcpip.h>
 #include <wincon.h>
 #else
+#include <sys/types.h>
 #include <sys/select.h>
 #endif
 
