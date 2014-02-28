--- gcl-tk/tkMain.c.orig
+++ gcl-tk/tkMain.c
@@ -206,7 +206,7 @@
 
     if (Tk_ParseArgv(interp, (Tk_Window) NULL, &argc, (const char **)argv, argTable, 0)
 	    != TCL_OK) {
-	fprintf(stderr, "%s\n", interp->result);
+	fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 	exit(1);
     }
     if (name == NULL) {
@@ -290,7 +290,7 @@
      */
 
     if (Tcl_AppInit(interp) != TCL_OK) {
-	fprintf(stderr, "Tcl_AppInit failed: %s\n", interp->result);
+	fprintf(stderr, "Tcl_AppInit failed: %s\n", Tcl_GetStringResult(interp));
     }
 
     /*
@@ -300,7 +300,7 @@
     if (geometry != NULL) {
 	code = Tcl_VarEval(interp, "wm geometry . ", geometry, (char *) NULL);
 	if (code != TCL_OK) {
-	    fprintf(stderr, "%s\n", interp->result);
+	    fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 	}
     }
 
@@ -330,13 +330,13 @@
     
 	    fullName = Tcl_TildeSubst(interp, tcl_RcFileName, &buffer);
 	    if (fullName == NULL) {
-		fprintf(stderr, "%s\n", interp->result);
+		fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 	    } else {
 		f = fopen(fullName, "r");
 		if (f != NULL) {
 		    code = Tcl_EvalFile(interp, fullName);
 		    if (code != TCL_OK) {
-			fprintf(stderr, "%s\n", interp->result);
+			fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 		    }
 		    fclose(f);
 		}
@@ -371,7 +371,7 @@
 error:
     msg = Tcl_GetVar(interp, "errorInfo", TCL_GLOBAL_ONLY);
     if (msg == NULL) {
-	msg = interp->result;
+	msg = Tcl_GetStringResult(interp);
     }
     dfprintf(stderr, "%s\n", msg);
     Tcl_Eval(interp, errorExitCmd);
@@ -502,7 +502,7 @@
 	      bcopy(msg->msg_id,p,3);
 	      /* end header */
 	      if(sock_write_str2(dsfd, m_reply, buf, 4 ,
-				 interp->result, strlen(interp->result))
+				 Tcl_GetStringResult(interp), strlen(Tcl_GetStringResult(interp)))
 		 < 0)
 		{		/* what do we want to do if the write failed */}
 	      
@@ -686,7 +686,7 @@
   code = Tcl_Eval(interp, szCmd);
   if (code != TCL_OK)
     {
-      dfprintf(stderr, "TCL Error int bind : %s\n", interp->result);
+      dfprintf(stderr, "TCL Error int bind : %s\n", Tcl_GetStringResult(interp));
 
     }
   return code;
