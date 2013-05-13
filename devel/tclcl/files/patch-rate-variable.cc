--- rate-variable.cc.orig	2013-05-13 09:26:02.000000000 +0200
+++ rate-variable.cc	2013-05-13 09:26:47.000000000 +0200
@@ -65,7 +65,7 @@
 	(void)new RateVariable;
 }
 
-char* RateVariable::update_rate_var(ClientData clientData, Tcl_Interp* tcl,
+const char* RateVariable::update_rate_var(ClientData clientData, Tcl_Interp* tcl,
 				    CONST84 char* name1, 
 				    CONST84 char* name2, int flags)
 {
@@ -82,7 +82,7 @@
 		flags &= TCL_GLOBAL_ONLY;
 		CONST char* cv = (char *) Tcl_GetVar2(tcl, name1, name2, flags);
 		if (cv == NULL)
-			return (tcl->result);
+			return (Tcl_GetStringResult(tcl));
 		int curval = atoi(cv);
 		double rate = 0.;
 		timeval tv;
