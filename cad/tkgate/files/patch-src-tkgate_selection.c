--- src/tkgate/selection.c.orig	2013-05-14 14:48:09.000000000 +0200
+++ src/tkgate/selection.c	2013-05-14 14:49:50.000000000 +0200
@@ -178,7 +178,7 @@
 
   if (TkGate.circuit && TkGate.circuit->es && hdl_isactive) {  /* GModuleDef_getType(TkGate.circuit->es->env) == MT_TEXTHDL*/
     DoTcl("HdlEditor::isselection");
-    sel_ok = (*TkGate.tcl->result == '1');
+    sel_ok = (Tcl_GetStringResult(TkGate.tcl)[0] == '1');
   } else {
     sel_ok = (TkGate.circuit->select != 0) || (TkGate.circuit->mg_selection != 0);
   }
@@ -661,7 +661,7 @@
   if (hdl_isactive) {
     DoTcl("HdlEditor::dumpSelection");
     cbm->m_type = MT_TEXTHDL;
-    GModuleDef_saveText(cbm, TkGate.tcl->result);
+    GModuleDef_saveText(cbm, Tcl_GetStringResult(TkGate.tcl));
   } else {
     GModuleDef_copyInto(cbm, m, 0,0,1,0);
     GCutBuffer_computeBounds(TkGate.circuit->cut_buffer);
@@ -701,8 +701,8 @@
 
   ob_touch(cbm);
   cbm->m_type = MT_TEXTHDL;
-  GModuleDef_allocText(cbm, strlen(cbm->m_text) + strlen(TkGate.tcl->result) + 1);
-  strcat(cbm->m_text, TkGate.tcl->result);
+  GModuleDef_allocText(cbm, strlen(cbm->m_text) + strlen(Tcl_GetStringResult(TkGate.tcl)) + 1);
+  strcat(cbm->m_text, Tcl_GetStringResult(TkGate.tcl));
 
   sel_updateMenuState();
 }
@@ -713,7 +713,7 @@
 
   if (hdl_isactive) {
     DoTcl("HdlEditor::isselection2");
-    if (*TkGate.tcl->result != '1') return;
+    if (Tcl_GetStringResult(TkGate.tcl)[0] != '1') return;
     sel_copy(es);
     DoTcl("HdlEditor::doDelete 0");
   } else {
