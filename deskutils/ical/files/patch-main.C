--- main.C.orig	1996-02-16 01:57:42 UTC
+++ main.C
@@ -27,13 +27,13 @@
 /* Include various libraries converted to strings. */
 
 #ifdef STANDALONE
-static char* tcl_lib_str[] = {
+static const char* tcl_lib_str[] = {
 #include "tcl_lib.gen"
 0
 };
 
 // Need to disable "source" command
-static char* tk_lib_str[] = {
+static const char* tk_lib_str[] = {
 "rename source _orig_source",
 "proc source {args} {}",
 #include "tk_lib.gen"
@@ -42,37 +42,37 @@ static char* tk_lib_str[] = {
 0
 };
 
-static char* ical_lib_str[] = {
+static const char* ical_lib_str[] = {
 #include "ical_lib.gen"
 0
 };
 
-static char* tcllib_str[] = {
+static const char* tcllib_str[] = {
 #include "tcllib.gen"
 0
 };
 #endif
 
-static char* ical_startup[] = {
+static const char* ical_startup[] = {
 #include "ical_start.gen"
 0
 };
 
-static char* psheader_str[] = {
+static const char* psheader_str[] = {
 "set ical(psheader) {%!PS-Adobe-",
 #include "psheader.gen"
 "}",
 0
 };
 
-static char* ical_doc_str[] = {
+static const char* ical_doc_str[] = {
 "set ical(doc) {",
 #include "icaldoc.gen"
 "}",
 0
 };
 
-static char* tcl_doc_str[] = {
+static const char* tcl_doc_str[] = {
 "set ical(tcl_interface_doc) {",
 #include "tcldoc.gen"
 "}",
@@ -173,7 +173,7 @@ main(int argc, char* argv[]) {
 
 #ifdef STANDALONE
 extern "C" int MyTcl_Init(Tcl_Interp* tcl) {
-    return (eval_list(tcl, tcl_lib_str));
+    return (eval_list(tcl, (char **)tcl_lib_str));
 }
 #else
 #define MyTcl_Init Tcl_Init
@@ -194,7 +194,7 @@ extern "C" int TkPlatformInit(Tcl_Interp* tcl) {
 
     TkCreateXEventSource();
 
-    return (eval_list(tcl, tk_lib_str));
+    return (eval_list(tcl, (char **)tk_lib_str));
 }
 #endif
 
@@ -245,37 +245,37 @@ int Ical_Init(Tcl_Interp* tcl) {
     }
 
     // Set-up postscript prolog
-    if (eval_list(tcl, psheader_str) != TCL_OK)
+    if (eval_list(tcl, (char **)psheader_str) != TCL_OK)
 	return TCL_ERROR;
 
     // Set-up documentation
-    if (eval_list(tcl, ical_doc_str) != TCL_OK)
+    if (eval_list(tcl, (char **)ical_doc_str) != TCL_OK)
 	return TCL_ERROR;
-    if (eval_list(tcl, tcl_doc_str) != TCL_OK)
+    if (eval_list(tcl, (char **)tcl_doc_str) != TCL_OK)
 	return TCL_ERROR;
 
     // Non-Tk ical commands
-    Tcl_CreateCommand(tcl, "calendar",     Cmd_CreateCalendar,	NULL, NULL);
-    Tcl_CreateCommand(tcl, "notice",       Cmd_CreateNotice,	NULL, NULL);
-    Tcl_CreateCommand(tcl, "appointment",  Cmd_CreateAppt,	NULL, NULL);
-    Tcl_CreateCommand(tcl, "date",         Cmd_Date,		NULL, NULL);
-    Tcl_CreateCommand(tcl, "ical_time",    Cmd_Time,		NULL, NULL);
-    Tcl_CreateCommand(tcl, "de_monthdays", Cmd_MonthDays,	NULL, NULL);
-    Tcl_CreateCommand(tcl, "hilite_loop",  Cmd_HiliteLoop,	NULL, NULL);
-    Tcl_CreateCommand(tcl, "ical_expand_file_name", Cmd_ExpandFileName, 0, 0);
+    Tcl_CreateCommand(tcl, "calendar",     (Tcl_CmdProc *)Cmd_CreateCalendar,	NULL, NULL);
+    Tcl_CreateCommand(tcl, "notice",       (Tcl_CmdProc *)Cmd_CreateNotice,	NULL, NULL);
+    Tcl_CreateCommand(tcl, "appointment",  (Tcl_CmdProc *)Cmd_CreateAppt,	NULL, NULL);
+    Tcl_CreateCommand(tcl, "date",         (Tcl_CmdProc *)Cmd_Date,		NULL, NULL);
+    Tcl_CreateCommand(tcl, "ical_time",    (Tcl_CmdProc *)Cmd_Time,		NULL, NULL);
+    Tcl_CreateCommand(tcl, "de_monthdays", (Tcl_CmdProc *)Cmd_MonthDays,	NULL, NULL);
+    Tcl_CreateCommand(tcl, "hilite_loop",  (Tcl_CmdProc *)Cmd_HiliteLoop,	NULL, NULL);
+    Tcl_CreateCommand(tcl, "ical_expand_file_name", (Tcl_CmdProc *)Cmd_ExpandFileName, 0, 0);
 
 #ifdef STANDALONE
     // Load tcllib files
-    if (eval_list(tcl, tcllib_str) != TCL_OK)
+    if (eval_list(tcl, (char **)tcllib_str) != TCL_OK)
 	return TCL_ERROR;
 
     // Load ical library files
-    if (eval_list(tcl, ical_lib_str) != TCL_OK)
+    if (eval_list(tcl, (char **)ical_lib_str) != TCL_OK)
 	return TCL_ERROR;
 #endif
 
     // Initialize ical stuff
-    if (eval_list(tcl, ical_startup) != TCL_OK)
+    if (eval_list(tcl, (char **)ical_startup) != TCL_OK)
 	return TCL_ERROR;
 
     if (Tcl_Eval(tcl, "ical_init") == TCL_ERROR)
