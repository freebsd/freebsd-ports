--- object.C.orig	1994-05-20 05:22:04.000000000 +0200
+++ object.C	2003-04-28 18:14:32.000000000 +0200
@@ -33,7 +33,7 @@ void Object::init(Tcl_Interp* t, char co
     interp = t;
 
     /* Create TCL Command */
-    Tcl_CreateCommand(interp, name, obj_handle, (ClientData) this, NULL);
+    Tcl_CreateCommand(interp, name, (Tcl_CmdProc *)obj_handle, (ClientData) this, NULL);
 }
 
 Object::~Object() {
@@ -46,7 +46,7 @@ Object::~Object() {
 Object* Object::find(Tcl_Interp* tcl, char const* h) {
     Tcl_CmdInfo i;
 
-    if (Tcl_GetCommandInfo(tcl, (char*)h, &i) && (i.proc == obj_handle))
+    if (Tcl_GetCommandInfo(tcl, (char*)h, &i) && (i.proc == (Tcl_CmdProc *)obj_handle))
 	return ((Object*) i.clientData);
 
     return 0;
