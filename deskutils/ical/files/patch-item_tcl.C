--- item_tcl.C.orig	2004-03-11 11:26:56 UTC
+++ item_tcl.C
@@ -106,52 +106,52 @@
 static int item_mlweekday	(ClientData, Tcl_Interp*, int, const char*[]);
 
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
+    { "length",			0, 1, (Tcl_CmdProc *)item_length	},
+    { "starttime",		0, 1, (Tcl_CmdProc *)item_startt	},
+    { "alarms",			0, 1, (Tcl_CmdProc *)item_alarms	},
+    { "option",			1, 2, (Tcl_CmdProc *)item_option	},
+    { "delete_option",		1, 1, (Tcl_CmdProc *)item_doption	},
 
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
 
-    { "contains",		1, 1, item_cont		},
-    { "empty",			0, 0, item_empty	},
-    { "repeats",		0, 0, item_repeat	},
-    { "first",			0, 0, item_first	},
-    { "next",			1, 1, item_next		},
-    { "range",			2, 2, item_range	},
-    { "type",			0, 0, item_type		},
-    { "describe_repeat",	0, 0, item_desc		},
+    { "contains",		1, 1, (Tcl_CmdProc *)item_cont		},
+    { "empty",			0, 0, (Tcl_CmdProc *)item_empty		},
+    { "repeats",		0, 0, (Tcl_CmdProc *)item_repeat	},
+    { "first",			0, 0, (Tcl_CmdProc *)item_first		},
+    { "next",			1, 1, (Tcl_CmdProc *)item_next		},
+    { "range",			2, 2, (Tcl_CmdProc *)item_range		},
+    { "type",			0, 0, (Tcl_CmdProc *)item_type		},
+    { "describe_repeat",	0, 0, (Tcl_CmdProc *)item_desc		},
 
-    { "date",			1, 1, item_date		},
-    { "dayrepeat",		2, 2, item_dayr		},
+    { "date",			1, 1, (Tcl_CmdProc *)item_date		},
+    { "dayrepeat",		2, 2, (Tcl_CmdProc *)item_dayr		},
 
-    { "monthrepeat",		2, 2, item_monthr	},
-    { "month_day",		1, 3, item_mday		},
-    { "month_last_day",		1, 3, item_mlday	},
-    { "month_work_day",		1, 3, item_mworkday	},
-    { "month_last_work_day",	1, 3, item_mlworkday	},
-    { "month_week_day",		2, 4, item_mweekday	},
-    { "month_last_week_day",	2, 4, item_mlweekday	},
+    { "monthrepeat",		2, 2, (Tcl_CmdProc *)item_monthr	},
+    { "month_day",		1, 3, (Tcl_CmdProc *)item_mday		},
+    { "month_last_day",		1, 3, (Tcl_CmdProc *)item_mlday		},
+    { "month_work_day",		1, 3, (Tcl_CmdProc *)item_mworkday	},
+    { "month_last_work_day",	1, 3, (Tcl_CmdProc *)item_mlworkday	},
+    { "month_week_day",		2, 4, (Tcl_CmdProc *)item_mweekday	},
+    { "month_last_week_day",	2, 4, (Tcl_CmdProc *)item_mlweekday	},
 
-    { "weekdays",		0, -1, item_wdays	},
-    { "start",			1, 1, item_start	},
-    { "finish",			1, 1, item_finish	},
-    { "deleteon",		1, 1, item_ondel	},
+    { "weekdays",		0, -1, (Tcl_CmdProc *)item_wdays	},
+    { "start",			1, 1, (Tcl_CmdProc *)item_start		},
+    { "finish",			1, 1, (Tcl_CmdProc *)item_finish	},
+    { "deleteon",		1, 1, (Tcl_CmdProc *)item_ondel		},
 
     { 0,			0, 0, 0			}
 };
@@ -329,7 +329,7 @@
 
 static int item_owned(ClientData c, Tcl_Interp* tcl, int argc, const char* argv[]) {
     Item_Tcl* item = (Item_Tcl*) c;
-    TCL_Return(tcl, (item->value()->IsMine() ? "1" : "0"));
+    TCL_Return(tcl, (item->value()->IsMine() ? (char *)"1" : (char *)"0"));
 }
 
 static int item_own(ClientData c, Tcl_Interp* tcl, int argc, const char* argv[]) {
@@ -492,12 +492,12 @@
 
 static int item_empty(ClientData c, Tcl_Interp* tcl, int argc, const char* argv[]) {
     Item_Tcl* item = (Item_Tcl*) c;
-    TCL_Return(tcl, (item->value()->empty()?"1":"0"));
+    TCL_Return(tcl, (item->value()->empty() ? (char *) "1" : (char *) "0"));
 }
 
 static int item_repeat(ClientData c, Tcl_Interp* tcl, int argc, const char* argv[]) {
     Item_Tcl* item = (Item_Tcl*) c;
-    TCL_Return(tcl,(item->value()->repeats()?"1":"0"));
+    TCL_Return(tcl,(item->value()->repeats() ? (char *) "1" : (char *) "0"));
 }
 
 static int item_first(ClientData c, Tcl_Interp* tcl, int argc, const char* argv[]) {
@@ -508,7 +508,7 @@
     }
 
     char buffer[100];
-    sprintf(buffer, "%d", d.EpochDays());
+    sprintf(buffer, "%ld", d.EpochDays());
     Tcl_SetResult(tcl, buffer, TCL_VOLATILE);
     return TCL_OK;
 }
@@ -518,43 +518,43 @@
     char* result;
     switch (item->value()->repeat_type()) {
       case DateSet::None:
-	result = "";
+	result = (char *)"";
 	break;
       case DateSet::Daily:
-	result = "Daily";
+	result = (char *)"Daily";
 	break;
       case DateSet::Weekly:
-	result = "Weekly";
+	result = (char *)"Weekly";
 	break;
       case DateSet::BiWeekly:
-	result = "Every Two Weeks";
+	result = (char *)"Every Two Weeks";
 	break;
       case DateSet::ThreeWeekly:
-	result = "Every Three Weeks";
+	result = (char *)"Every Three Weeks";
 	break;
       case DateSet::FourWeekly:
-	result = "Every Four Weeks";
+	result = (char *)"Every Four Weeks";
 	break;
       case DateSet::Monthly:
-	result = "Monthly";
+	result = (char *)"Monthly";
 	break;
       case DateSet::TwoMonthly:
-	result = "Every Two Months";
+	result = (char *)"Every Two Months";
 	break;
       case DateSet::ThreeMonthly:
-	result = "Every Three Months";
+	result = (char *)"Every Three Months";
 	break;
       case DateSet::FourMonthly:
-	result = "Every Four Months";
+	result = (char *)"Every Four Months";
 	break;
       case DateSet::SixMonthly:
-	result = "Every Six Months";
+	result = (char *)"Every Six Months";
 	break;
       case DateSet::Annual:
-	result = "Annual";
+	result = (char *)"Annual";
 	break;
       default:
-	result = "Complex";
+	result = (char *)"Complex";
 	break;
     }
     TCL_Return(tcl, result);
@@ -576,7 +576,7 @@
 	TCL_Error(tcl, "invalid date");
     }
     Date date(dateDays);
-    TCL_Return(tcl, (item->value()->contains(date)?"1":"0"));
+    TCL_Return(tcl, (item->value()->contains(date) ? (char *)"1" : (char *)"0"));
 }
 
 static int item_next(ClientData c, Tcl_Interp* tcl, int argc, const char* argv[]) {
@@ -592,7 +592,7 @@
     }
 
     char buffer[100];
-    sprintf(buffer, "%d", next.EpochDays());
+    sprintf(buffer, "%ld", next.EpochDays());
     Tcl_SetResult(tcl, buffer, TCL_VOLATILE);
     return TCL_OK;
 }
@@ -603,10 +603,10 @@
     Date s, f;
     if (item->value()->range(s, f)) {
 	char buffer[100];
-	sprintf(buffer, "%d", s.EpochDays());
+	sprintf(buffer, "%ld", s.EpochDays());
 	if (Tcl_SetVar(tcl, argv[0], buffer, 0) == NULL)
 	    TCL_Error(tcl, "could not set range start variable");
-	sprintf(buffer, "%d", f.EpochDays());
+	sprintf(buffer, "%ld", f.EpochDays());
 	if (Tcl_SetVar(tcl, argv[1], buffer, 0) == NULL)
 	    TCL_Error(tcl, "could not set range finish variable");
 	TCL_Return(tcl, "1");
@@ -886,7 +886,7 @@
     if (file == 0) return 1;
 
     if (file->GetCalendar()->ReadOnly()) {
-	Tcl_SetResult(tcl, "item is in readonly calendar", TCL_STATIC);
+	Tcl_SetResult(tcl, (char *)"item is in readonly calendar", TCL_STATIC);
 	return 0;
     }
 
