--- cal_tcl.C.orig	Sun Nov 28 17:29:13 1999
+++ cal_tcl.C	Sun Nov 28 17:30:24 1999
@@ -214,27 +214,27 @@ static int cal_loopf	(ClientData, Tcl_In
 static int cal_loopb	(ClientData, Tcl_Interp*, int, char*[]);
 
 static Dispatch_Entry calendar_dispatch[] = {
-    { "delete",		0, 0, cal_delete	},
-    { "main",		0, 0, cal_main		},
-    { "include",	1, 1, cal_include	},
-    { "exclude",	1, 1, cal_exclude	},
-    { "forincludes",	2, 2, cal_forincs	},
-    { "add",		1, 2, cal_add		},
-    { "remove",		1, 1, cal_remove	},
-    { "hide",		1, 1, cal_hide		},
-    { "readonly",	0, 1, cal_ronly		},
-    { "dirty",		0, 1, cal_dirty		},
-    { "stale",		0, 1, cal_stale		},
-    { "save",		0, 1, cal_save		},
-    { "reread",		0, 1, cal_reread	},
-    { "query",		5, 7, cal_query		},
-    { "listing",	5, 7, cal_listing	},
-    { "loop",		2, 4, cal_loop		},
-    { "incalendar",	3, 3, cal_incal		},
-    { "option",		1, 4, cal_option	},
-    { "delete_option",	1, 3, cal_doption	},
-    { "loop_forward",	5, 7, cal_loopf		},
-    { "loop_backward",	5, 7, cal_loopb		},
+    { "delete",		0, 0, (Tcl_CmdProc *)cal_delete		},
+    { "main",		0, 0, (Tcl_CmdProc *)cal_main		},
+    { "include",	1, 1, (Tcl_CmdProc *)cal_include	},
+    { "exclude",	1, 1, (Tcl_CmdProc *)cal_exclude	},
+    { "forincludes",	2, 2, (Tcl_CmdProc *)cal_forincs	},
+    { "add",		1, 2, (Tcl_CmdProc *)cal_add		},
+    { "remove",		1, 1, (Tcl_CmdProc *)cal_remove		},
+    { "hide",		1, 1, (Tcl_CmdProc *)cal_hide		},
+    { "readonly",	0, 1, (Tcl_CmdProc *)cal_ronly		},
+    { "dirty",		0, 1, (Tcl_CmdProc *)cal_dirty		},
+    { "stale",		0, 1, (Tcl_CmdProc *)cal_stale		},
+    { "save",		0, 1, (Tcl_CmdProc *)cal_save		},
+    { "reread",		0, 1, (Tcl_CmdProc *)cal_reread		},
+    { "query",		5, 7, (Tcl_CmdProc *)cal_query		},
+    { "listing",	5, 7, (Tcl_CmdProc *)cal_listing	},
+    { "loop",		2, 4, (Tcl_CmdProc *)cal_loop		},
+    { "incalendar",	3, 3, (Tcl_CmdProc *)cal_incal		},
+    { "option",		1, 4, (Tcl_CmdProc *)cal_option		},
+    { "delete_option",	1, 3, (Tcl_CmdProc *)cal_doption	},
+    { "loop_forward",	5, 7, (Tcl_CmdProc *)cal_loopf		},
+    { "loop_backward",	5, 7, (Tcl_CmdProc *)cal_loopb		},
     { 0,		0, 0, 0			}
 };
 
@@ -281,7 +281,7 @@ static int parse_items(Tcl_Interp* tcl, 
 
     if ((argc >= 2) && (strcmp(argv[0], "-items") == 0)) {
 	int count;
-	char** list;
+	CONST84 char** list;
 	if (Tcl_SplitList(tcl, argv[1], &count, &list) != TCL_OK) {
 	    TCL_Error(tcl, "invalid item list");
 	}
@@ -516,7 +516,7 @@
 	TCL_Error(tcl, "no such calendar");
     }
 
-    TCL_Return(tcl, file->GetCalendar()->ReadOnly() ? "1" : "0");
+    TCL_Return(tcl, file->GetCalendar()->ReadOnly() ? (char *)"1" : (char *)"0");
 }
 
 static int cal_dirty(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]){
@@ -527,7 +527,7 @@
 	TCL_Error(tcl, "no such calendar");
     }
 
-    TCL_Return(tcl, (file->IsModified() ? "1" : "0"));
+    TCL_Return(tcl, (file->IsModified() ? (char *)"1" : (char *)"0"));
 }
 
 static int cal_stale(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]){
@@ -538,7 +538,7 @@
 	TCL_Error(tcl, "no such calendar");
     }
 
-    TCL_Return(tcl, (file->FileHasChanged() ? "1" : "0"));
+    TCL_Return(tcl, (file->FileHasChanged() ? (char *)"1" : (char *)"0"));
 }
 
 static int cal_save(ClientData c, Tcl_Interp* tcl, int argc, char* argv[]){
