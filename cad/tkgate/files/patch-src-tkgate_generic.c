--- src/tkgate/generic.c.orig	2013-05-14 14:41:47.000000000 +0200
+++ src/tkgate/generic.c	2013-05-14 14:42:07.000000000 +0200
@@ -749,7 +749,7 @@
   y = ctow_y(g->ypos-50);
 
   DoTcl("offsetgeometry . %d %d",x,y);
-  sscanf(TkGate.tcl->result,"+%d+%d",&x,&y);
+  sscanf(Tcl_GetStringResult(TkGate.tcl),"+%d+%d",&x,&y);
 
   if (x < 25) x = 25;
   if (y < 25) y = 25;
