--- src/tkgate/block.c.orig	2013-05-14 14:38:34.000000000 +0200
+++ src/tkgate/block.c	2013-05-14 14:40:01.000000000 +0200
@@ -1100,8 +1100,8 @@
    */
   if (best_w) {
     DoTcl("PortEntry::generateNextNameFrom %s",best_w->name);
-    if (*TkGate.tcl->result)
-      strcpy(buf,TkGate.tcl->result);
+    if (*(Tcl_GetStringResult(TkGate.tcl)))
+      strcpy(buf,Tcl_GetStringResult(TkGate.tcl));
   }
 
   if (!*buf) {
@@ -1164,7 +1164,7 @@
   else
     DoTcl("PortEdit::post [offsetgeometry . %d %d] -ismodule 1 -showsig 0",ctow_x(x+125),ctow_y(y+50));
 
-  if (strcmp(TkGate.tcl->result,"1") == 0) {
+  if (strcmp(Tcl_GetStringResult(TkGate.tcl),"1") == 0) {
     const char *numBits;
     int new_dir;
 
@@ -1543,7 +1543,7 @@
   DoTcl("PortEdit::post [offsetgeometry . %d %d] -ismodule 1 -showsig 0",
 	ctow_x(x+125),ctow_y(y+50));
 
-  if (strcmp(TkGate.tcl->result,"1") == 0) {
+  if (strcmp(Tcl_GetStringResult(TkGate.tcl),"1") == 0) {
     const char *numBits;
     const char *sigName;
     const char *portName;
