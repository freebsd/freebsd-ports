--- common/TclGlue.cpp.bak	2002-12-20 15:38:25.000000000 +0100
+++ common/TclGlue.cpp	2013-05-13 14:10:28.000000000 +0200
@@ -452,7 +452,7 @@
 			{
 				EntnodeData* data = entry->GetData();
 				CStr path, fname, value;
-				entry->GetNormalized(path, fname);				
+				entry->GetNormalized(path, fname);
 				const char *res = Tcl_SetVar2(interp, argv[3], "name", fname, 0);
 				if(res == 0L)
 					goto err1;
@@ -1161,17 +1161,18 @@
 	if(bTclFileStarted)
 		gCvsPrefs.SetTclFileRunning(false);
 
-	size_t len = strlen(fInterp->result);
+	const char *res = Tcl_GetStringResult(fInterp);
+	size_t len = strlen(res);
 	if(exitc == TCL_ERROR)
 	{
-		cvs_errstr(fInterp->result, len);
-		if(len != 0 && fInterp->result[len - 1] != '\n')
+		cvs_errstr(res, len);
+		if(len != 0 && res[len - 1] != '\n')
 			cvs_errstr("\n", 1);
 	}
 	else
 	{
-		cvs_outstr(fInterp->result, len);
-		if(len != 0 && fInterp->result[len - 1] != '\n')
+		cvs_outstr(res, len);
+		if(len != 0 && res[len - 1] != '\n')
 			cvs_outstr("\n", 1);
 	}
 	
@@ -1207,17 +1208,18 @@
 		return false;
 	
 	int exitc = Tcl_EvalFile(fInterp, (char *)file);
-	size_t len = strlen(fInterp->result);
+    const char *res = Tcl_GetStringResult(fInterp);
+	size_t len = strlen(res);
 	if(exitc == TCL_ERROR)
 	{
-		cvs_errstr(fInterp->result, len);
-		if(len != 0 && fInterp->result[len - 1] != '\n')
+		cvs_errstr(res, len);
+		if(len != 0 && res[len - 1] != '\n')
 			cvs_errstr("\n", 1);
 	}
 	else
 	{
-		cvs_outstr(fInterp->result, len);
-		if(len != 0 && fInterp->result[len - 1] != '\n')
+		cvs_outstr(res, len);
+		if(len != 0 && res[len - 1] != '\n')
 			cvs_outstr("\n", 1);
 	}
 	
