--- src/tkgate/simulate.c.orig	2013-05-14 14:50:07.000000000 +0200
+++ src/tkgate/simulate.c	2013-05-14 14:50:30.000000000 +0200
@@ -1117,7 +1117,7 @@
 
 
     DoTcl("VPD::isallowed %s",cmdName);
-    if (*TkGate.tcl->result != '1') return -1;
+    if (Tcl_GetStringResult(TkGate.tcl)[0] != '1') return -1;
 
     DoTcl(cmd);
     return 0;
