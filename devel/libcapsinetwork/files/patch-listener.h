$FreeBSD$

--- listener.h.orig	Thu Oct 24 14:37:41 2002
+++ listener.h	Thu Oct 24 14:37:55 2002
@@ -19,6 +19,7 @@
 
 #include <string>
 #include <vector>
+#include <sys/types.h>
 
 class ListenPort;
 class Socket;
