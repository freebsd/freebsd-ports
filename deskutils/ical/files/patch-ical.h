--- ical.h.orig	1996-02-10 03:17:36 UTC
+++ ical.h
@@ -4,6 +4,11 @@
 
 #include <tcl.h>
 
+// That was introduced in tcl8.4
+#ifndef CONST84
+#define CONST84
+#endif
+
 // Proc for triggering tcl code based on changes
 // to calendars/items.
 
@@ -25,13 +30,13 @@ extern void trigger(Tcl_Interp*, char const* ttype, ch
 
 #define TCL_Return(tcl,str)			\
     do {					\
-	Tcl_SetResult(tcl, (str), TCL_STATIC);	\
+	Tcl_SetResult(tcl, ((char *)(str)), TCL_STATIC);	\
 	return TCL_OK;				\
     } while (0)
 
 #define TCL_Error(tcl,str)			\
     do {					\
-	Tcl_SetResult(tcl, (str), TCL_STATIC);	\
+	Tcl_SetResult(tcl, ((char *)(str)), TCL_STATIC);	\
 	return TCL_ERROR;			\
     } while (0)
 
