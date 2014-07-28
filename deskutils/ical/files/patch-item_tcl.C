--- item_tcl.C.orig	Sun Nov 28 17:31:26 1999
+++ item_tcl.C	Sun Nov 28 17:32:25 1999
@@ -106,52 +106,52 @@
 static int item_mlweekday	(ClientData, Tcl_Interp*, int, char*[]);
 
 static Dispatch_Entry item_dispatch[] = {
-    { "delete",			0, 0, item_delete	},
-    { "clone",			0, 0, item_clone	},
+    { "delete",			0, 0, (Tcl_CmdProc *)item_delete	},
+    { "clone",			0, 0, (Tcl_CmdProc *)item_clone		},
 
-    { "length",			0, 1, item_length	},
-    { "starttime",		0, 1, item_startt	},
-    { "alarms",			0, 1, item_alarms	},
-    { "option",			1, 2, item_option	},
-    { "delete_option",		1, 1, item_doption	},
-
-    { "is",			1, 1, item_is		},
-    { "calendar",		0, 0, item_cal		},
-    { "text",			0, 1, item_text		},
-    { "uid",			0, 0, item_uid		},
-    { "earlywarning",		0, 1, item_early	},
-    { "owner",			0, 1, item_owner	},
-    { "owned",			0, 0, item_owned	},
-    { "own",			0, 0, item_own		},
-    { "hilite",			0, 1, item_hilite	},
-    { "todo",			0, 1, item_todo		},
-    { "is_done",		0, 0, item_is_done	},
-    { "done",			1, 1, item_done		},
-
-    { "contains",		1, 1, item_cont		},
-    { "empty",			0, 0, item_empty	},
-    { "repeats",		0, 0, item_repeat	},
-    { "first",			0, 0, item_first	},
-    { "next",			1, 1, item_next		},
-    { "range",			2, 2, item_range	},
-    { "type",			0, 0, item_type		},
-    { "describe_repeat",	0, 0, item_desc		},
-
-    { "date",			1, 1, item_date		},
-    { "dayrepeat",		2, 2, item_dayr		},
-
-    { "monthrepeat",		2, 2, item_monthr	},
-    { "month_day",		1, 3, item_mday		},
-    { "month_last_day",		1, 3, item_mlday	},
-    { "month_work_day",		1, 3, item_mworkday	},
-    { "month_last_work_day",	1, 3, item_mlworkday	},
-    { "month_week_day",		2, 4, item_mweekday	},
-    { "month_last_week_day",	2, 4, item_mlweekday	},
-
-    { "weekdays",		0, -1, item_wdays	},
-    { "start",			1, 1, item_start	},
-    { "finish",			1, 1, item_finish	},
-    { "deleteon",		1, 1, item_ondel	},
+    { "length",			0, 1, (Tcl_CmdProc *)item_length	},
+    { "starttime",		0, 1, (Tcl_CmdProc *)item_startt	},
+    { "alarms",			0, 1, (Tcl_CmdProc *)item_alarms	},
+    { "option",			1, 2, (Tcl_CmdProc *)item_option	},
+    { "delete_option",		1, 1, (Tcl_CmdProc *)item_doption	},
+
+    { "is",			1, 1, (Tcl_CmdProc *)item_is		},
+    { "calendar",		0, 0, (Tcl_CmdProc *)item_cal		},
+    { "text",			0, 1, (Tcl_CmdProc *)item_text		},
+    { "uid",			0, 0, (Tcl_CmdProc *)item_uid		},
+    { "earlywarning",		0, 1, (Tcl_CmdProc *)item_early		},
+    { "owner",			0, 1, (Tcl_CmdProc *)item_owner		},
+    { "owned",			0, 0, (Tcl_CmdProc *)item_owned		},
+    { "own",			0, 0, (Tcl_CmdProc *)item_own		},
+    { "hilite",			0, 1, (Tcl_CmdProc *)item_hilite	},
+    { "todo",			0, 1, (Tcl_CmdProc *)item_todo		},
+    { "is_done",		0, 0, (Tcl_CmdProc *)item_is_done	},
+    { "done",			1, 1, (Tcl_CmdProc *)item_done		},
+
+    { "contains",		1, 1, (Tcl_CmdProc *)item_cont		},
+    { "empty",			0, 0, (Tcl_CmdProc *)item_empty		},
+    { "repeats",		0, 0, (Tcl_CmdProc *)item_repeat	},
+    { "first",			0, 0, (Tcl_CmdProc *)item_first		},
+    { "next",			1, 1, (Tcl_CmdProc *)item_next		},
+    { "range",			2, 2, (Tcl_CmdProc *)item_range		},
+    { "type",			0, 0, (Tcl_CmdProc *)item_type		},
+    { "describe_repeat",	0, 0, (Tcl_CmdProc *)item_desc		},
+
+    { "date",			1, 1, (Tcl_CmdProc *)item_date		},
+    { "dayrepeat",		2, 2, (Tcl_CmdProc *)item_dayr		},
+
+    { "monthrepeat",		2, 2, (Tcl_CmdProc *)item_monthr	},
+    { "month_day",		1, 3, (Tcl_CmdProc *)item_mday		},
+    { "month_last_day",		1, 3, (Tcl_CmdProc *)item_mlday		},
+    { "month_work_day",		1, 3, (Tcl_CmdProc *)item_mworkday	},
+    { "month_last_work_day",	1, 3, (Tcl_CmdProc *)item_mlworkday	},
+    { "month_week_day",		2, 4, (Tcl_CmdProc *)item_mweekday	},
+    { "month_last_week_day",	2, 4, (Tcl_CmdProc *)item_mlweekday	},
+
+    { "weekdays",		0, -1, (Tcl_CmdProc *)item_wdays	},
+    { "start",			1, 1, (Tcl_CmdProc *)item_start		},
+    { "finish",			1, 1, (Tcl_CmdProc *)item_finish	},
+    { "deleteon",		1, 1, (Tcl_CmdProc *)item_ondel		},
 
     { 0,			0, 0, 0			}
 };
+++ item_tcl.C	Sun Nov 28 17:32:25 1999
@@ -329,7 +329,7 @@
 
 static int item_owned(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]) {
     Item_Tcl* item = (Item_Tcl*) c;
-    TCL_Return(tcl, (item->value()->IsMine() ? "1" : "0"));
+    TCL_Return(tcl, (item->value()->IsMine() ? (char *)"1" : (char *)"0"));
 }
 
 static int item_own(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]) {
@@ -431,7 +431,7 @@ static int item_alarms(ClientData c, Tcl
     }
 
     int count;
-    char** list;
+    CONST84 char** list;
     if (Tcl_SplitList(tcl, argv[0], &count, &list) != TCL_OK) {
 	TCL_Error(tcl, "invalid alarm list");
     }
@@ -492,12 +492,12 @@
 
 static int item_empty(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]) {
     Item_Tcl* item = (Item_Tcl*) c;
-    TCL_Return(tcl, (item->value()->empty()?"1":"0"));
+    TCL_Return(tcl, (item->value()->empty() ? (char *)"1" : (char *)"0"));
 }
 
 static int item_repeat(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]) {
     Item_Tcl* item = (Item_Tcl*) c;
-    TCL_Return(tcl,(item->value()->repeats()?"1":"0"));
+    TCL_Return(tcl,(item->value()->repeats() ? (char *)"1" : (char *)"0"));
 }
 
 static int item_first(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]) {
@@ -576,7 +576,7 @@
 	TCL_Error(tcl, "invalid date");
     }
     Date date(dateDays);
-    TCL_Return(tcl, (item->value()->contains(date)?"1":"0"));
+    TCL_Return(tcl, (item->value()->contains(date) ? (char *)"1" : (char *)"0"));
 }
 
 static int item_next(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]) {
