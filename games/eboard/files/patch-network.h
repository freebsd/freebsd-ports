--- network.h.orig	2018-07-31 18:02:19 UTC
+++ network.h
@@ -253,6 +253,7 @@ class PipeConnection : public BufferedConnection,
   int  pid;
   int  toid; // timeout
   string handshake;
+  int  use_execve;
   double MaxWaitTime; // msecs
 
 };
