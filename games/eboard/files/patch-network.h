--- network.h.orig	Thu Nov 27 00:48:49 2003
+++ network.h	Wed Feb 22 16:22:04 2006
@@ -229,6 +229,7 @@
   int  pid;
   int  toid; // timeout
   string handshake;
+  int  use_execve;
 };
 
 class FallBackConnection : public NetConnection {
