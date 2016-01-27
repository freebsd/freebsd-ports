--- exp_main_sub.c.orig	2010-08-27 22:01:15 UTC
+++ exp_main_sub.c
@@ -672,6 +672,9 @@ char **argv;
 	char *args;		/* ptr to string-rep of all args */
 	char *debug_init;
 
+	char *native;
+	Tcl_DString ds;
+
 	exp_argv0 = argv[0];
 
 #ifdef TCL_DEBUGGER
@@ -853,18 +856,23 @@ char **argv;
 	expDiagLog("set argc %s\r\n",argc_rep);
 
 	if (exp_cmdfilename) {
-		Tcl_SetVar(interp,"argv0",exp_cmdfilename,0);
+		native = Tcl_ExternalToUtfDString(NULL, exp_cmdfilename, -1, &ds);
+		Tcl_SetVar(interp,"argv0",native,0);
 		expDiagLog("set argv0 \"%s\"\r\n",exp_cmdfilename);
 	} else {
-		Tcl_SetVar(interp,"argv0",exp_argv0,0);
+		native = Tcl_ExternalToUtfDString(NULL, exp_argv0, -1, &ds);
+		Tcl_SetVar(interp,"argv0",native,0);
 		expDiagLog("set argv0 \"%s\"\r\n",exp_argv0);
 	}
+	Tcl_DStringFree(&ds);
 
 	args = Tcl_Merge(argc-optind,argv+optind);
 	expDiagLogU("set argv \"");
 	expDiagLogU(args);
 	expDiagLogU("\"\r\n");
-	Tcl_SetVar(interp,"argv",args,0);
+	native = Tcl_ExternalToUtfDString(NULL, args, -1, &ds);
+	Tcl_SetVar(interp,"argv",native,0);
+	Tcl_DStringFree(&ds);
 	Tcl_Free(args);
 
 	exp_interpret_rcfiles(interp,my_rc,sys_rc);
