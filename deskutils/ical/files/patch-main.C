--- main.C.tcl84fixes	1996-02-16 02:57:42.000000000 +0100
+++ main.C	2003-04-28 18:14:32.000000000 +0200
@@ -255,14 +255,14 @@ int Ical_Init(Tcl_Interp* tcl) {
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
