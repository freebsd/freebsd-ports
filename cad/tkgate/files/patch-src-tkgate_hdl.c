--- src/tkgate/hdl.c.orig	2013-05-14 14:42:23.000000000 +0200
+++ src/tkgate/hdl.c	2013-05-14 14:45:35.000000000 +0200
@@ -90,7 +90,7 @@
 {
   GModuleDef *M;
   int rvalue = 0;
-  char *text;
+  const char *text;
 
   if (name)
     M = env_findModule(name);
@@ -104,7 +104,7 @@
   if (M->m_type != MT_TEXTHDL) return 0;
 
   DoTcl("HdlEditor::dumpText");
-  text = TkGate.tcl->result;
+  text = Tcl_GetStringResult(TkGate.tcl);
 
 #if 0
   printf("hdl_save(%s)\n",M->m_name);
@@ -339,7 +339,7 @@
   int module_count = 0;
   HdlModuleData module_data[MAXMODS];
   GModuleDef *M;
-  char *text;
+  const char *text;
   int rvalue = 0;
 
   if (name)
@@ -358,7 +358,7 @@
   M->m_needScan = 1;
 
   DoTcl("HdlEditor::dumpText");
-  text = TkGate.tcl->result;
+  text = Tcl_GetStringResult(TkGate.tcl);
 
   /*
    * Turn text into a copy.  Use non-ob functions since we only use it here
@@ -368,7 +368,7 @@
   /*
    * Find the partition points for modules
    */
-  module_count = hdl_findPartitions(text,module_data,MAXMODS);
+  module_count = hdl_findPartitions((char *)text,module_data,MAXMODS);
 
   ob_touch(M);
 
@@ -400,10 +400,10 @@
 
     if (!ismatch(M->m_name,module_data[0].name,module_data[0].name_len)) {
       DoTcl("HdlEditor::askRename");
-      if (strcmp(TkGate.tcl->result,"autoedit") == 0) {
+      if (strcmp(Tcl_GetStringResult(TkGate.tcl),"autoedit") == 0) {
 	hdl_replaceName(M,M->m_name);
 	DoTclL("HdlEditor::loadText",M->m_text,NULL);
-      } else if (strcmp(TkGate.tcl->result,"ignore") == 0) {
+      } else if (strcmp(Tcl_GetStringResult(TkGate.tcl),"ignore") == 0) {
 	/* Do nothing */
       } else {	/* cancel */
 	rvalue = -1;
@@ -416,11 +416,11 @@
      * which action they want to take.
      */
     DoTcl("HdlEditor::askSaveOption");
-    if (strcmp(TkGate.tcl->result,"split") == 0) {
+    if (strcmp(Tcl_GetStringResult(TkGate.tcl),"split") == 0) {
       GModuleDef_saveText(M, text);
       hdl_splitModules(M,module_data,module_count);
       DoTclL("HdlEditor::loadText",M->m_text,NULL);
-    } else if (strcmp(TkGate.tcl->result,"ignore") == 0) {
+    } else if (strcmp(Tcl_GetStringResult(TkGate.tcl),"ignore") == 0) {
       GModuleDef_saveText(M, text);
     } else {
       /* "cancel" or unknown value */
