--- ../vigor/vigor.c.orig
+++ ../vigor/vigor.c
@@ -13,7 +13,7 @@
 #include <sys/types.h>
 #include <sys/queue.h>
 #include <sys/time.h>
-#ifdef HAVE_SYS_SELECT_H
+#if 0
 #include <sys/select.h>
 #endif
 
@@ -78,7 +78,7 @@
 	 * to want tk's main window cluttering up the place.  I should
 	 * use a wm_withdraw instead. */
 	if (Tk_Init(vigor_interp) == TCL_ERROR) {
-		fprintf(stderr, "%s\n", vigor_interp->result);		
+		fprintf(stderr, "%s\n", Tcl_GetStringResult(vigor_interp));		
 		return (1);
 	}
 
@@ -87,7 +87,7 @@
 		return (1);
 #endif
 	if (Tcl_Eval(vigor_interp, vigor_tcl) == TCL_ERROR) {
-		fprintf(stderr, "%s\n", vigor_interp->result);
+		fprintf(stderr, "%s\n", Tcl_GetStringResult(vigor_interp));
 		return (1);
 	}
 
@@ -127,7 +127,7 @@
 	init_vigor_phrases();
 
 	if (Tcl_Eval(vigor_interp, "vigor_init") == TCL_ERROR) {
-		fprintf(stderr, "%s\n", vigor_interp->result);
+		fprintf(stderr, "%s\n", Tcl_GetStringResult(vigor_interp));
 	        return (1);
 	}
 
