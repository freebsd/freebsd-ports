--- network.h.orig	Sat Jul  6 17:05:11 2002
+++ network.h	Wed Aug 14 00:56:14 2002
@@ -47,6 +47,10 @@
 #include "stl.h"
 #include "eboard.h"
 
+#ifndef SOL_TCP
+#define SOL_TCP IPPROTO_TCP
+#endif
+
 class PidIssuer {
  public:
   virtual void farewellPid(int dpid)=0;
