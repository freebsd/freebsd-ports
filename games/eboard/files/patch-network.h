--- network.h.orig	Mon Jan 15 23:59:58 2007
+++ network.h	Wed Jan 17 19:39:10 2007
@@ -235,6 +235,7 @@
   int  pid;
   int  toid; // timeout
   string handshake;
+  int  use_execve;
   double MaxWaitTime; // msecs
 };
 
