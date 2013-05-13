--- rate-variable.h.orig	2013-05-13 09:26:59.000000000 +0200
+++ rate-variable.h	2013-05-13 09:27:45.000000000 +0200
@@ -41,7 +41,7 @@
 	RateVariable() : TclCommand("rate_variable") {}
 	static void init();
 protected:
-	static char* update_rate_var(ClientData, Tcl_Interp*, 
+	static const char* update_rate_var(ClientData, Tcl_Interp*, 
 				     CONST84 char* name1,	
 				     CONST84 char* name2, 
 				     int flags);
