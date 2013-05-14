--- src/tkgate/editstate.c.orig	2013-05-14 14:41:05.000000000 +0200
+++ src/tkgate/editstate.c	2013-05-14 14:41:30.000000000 +0200
@@ -513,7 +513,7 @@
 
     sprintf(buf,msgLookup("msg.modoverwt"),dst);	/* Destination module '%s' already exists.  Overwrite? */
     DoTcl("confirmMsg \"%s\" ",buf);
-    if (*TkGate.tcl->result != '1')
+    if (Tcl_GetStringResult(TkGate.tcl)[0] != '1')
       return;
 
     env_removeModule(dst,0);
