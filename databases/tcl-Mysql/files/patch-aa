This patch  substantially revamps the sql.cc  to make use of  and better
comply  with Tcl-8.x  object-paradigm. The  correct programs  will still
execute the same way, but in some erroneous cases the error messages may
be slightly different. The  patch gets rid of a lot  of sprintf and will
make your scripts faster, especially  when fetching multiple rows of the
same queries.

In modern MySQL mysql_error() returns a const-pointer, so getErrorMsg()
had to be changed. However, since we are using TCL_STATIC anyway, we can
just cast its result back down to plain char*

--- sql.cc	Fri Aug 13 15:28:56 1999
+++ sql.cc	Wed Nov 10 17:40:19 2004
@@ -12,24 +12,11 @@
 
-const char* HANDLE_PREFIX = "sql";
-const char* RESULT_PREFIX = "res";
-
-// -------------------------------------------------------------
-// Convert a tcl style connection to an interger
-// returns -1 on format error,
-int stripPrefix(char *txt, const char* prefix) {
-
-	unsigned int prefixLen = strlen(prefix);
-
-	if (strlen(txt) <= prefixLen ||
-	    strncmp(txt, prefix, prefixLen)!=0) {
-		return -1;
-	}
-	return (atoi(txt+prefixLen));
-}
+#ifndef CONST84
+#	define CONST84
+#endif
 
 // -------------------------------------------------------------
-int selectdbCmd(Tcl_Interp *interp, Sql_interface *conn, char *dbname) {
+int selectdbCmd(Tcl_Interp *interp, Sql_interface *conn, Tcl_Obj *const dbname) {
 
-	if (conn->selectdb(dbname)) {
-		Tcl_SetResult(interp, dbname, TCL_VOLATILE);
+	if (conn->selectdb(Tcl_GetString(dbname))) {
+		Tcl_SetObjResult(interp, dbname);
 		return TCL_OK;
@@ -38,3 +25,3 @@
 	// An error occured.
-	Tcl_SetResult(interp, conn->getErrorMsg(), TCL_VOLATILE);
+	Tcl_SetResult(interp, (char *)conn->getErrorMsg(), TCL_STATIC);
 	return TCL_ERROR;
@@ -47,3 +34,3 @@
 	// An error occured.
-	Tcl_SetResult(interp, conn->getErrorMsg(), TCL_VOLATILE);
+	Tcl_SetResult(interp, (char *)conn->getErrorMsg(), TCL_STATIC);
 	return TCL_ERROR;
@@ -60,9 +47,9 @@
 int queryCmd(Tcl_Interp *interp, Sql_interface *conn, char *cmd) {
-	int handle = -1;
+	int handle;
 	if ((handle = conn->query(cmd)) < 0) {
 		// An error occured.
-		Tcl_SetResult(interp, conn->getErrorMsg(), TCL_VOLATILE);
+		Tcl_SetResult(interp, (char *)conn->getErrorMsg(), TCL_STATIC);
 		return TCL_ERROR;
 	}
-	sprintf(interp->result, "%s%d", RESULT_PREFIX, handle);
+	Tcl_SetObjResult(interp, Tcl_NewIntObj(handle));
 	return TCL_OK;
@@ -71,7 +58,3 @@
 // -------------------------------------------------------------
-int endqueryCmd(Tcl_Interp *interp, Sql_interface *conn, char *handle) {
-	int resHandle = 0;
-	if (handle) {
-		resHandle = stripPrefix(handle, RESULT_PREFIX);
-	}
+int endqueryCmd(Tcl_Interp *interp, Sql_interface *conn, int resHandle) {
 	conn->endquery(resHandle);
@@ -81,14 +64,4 @@
 // -------------------------------------------------------------
-int numrowsCmd(Tcl_Interp *interp, Sql_interface *conn, char *handle) {
-	int resHandle = 0;
-	if (handle) {
-		resHandle = stripPrefix(handle, RESULT_PREFIX);
-	}
-	int nrows = conn->numRows(resHandle);
-
-	// Return the result of the command:
-	char retval[20];
-	sprintf(retval, "%d", nrows);
-
-	Tcl_SetResult(interp, retval, TCL_VOLATILE);
+int numrowsCmd(Tcl_Interp *interp, Sql_interface *conn, int resHandle) {
+	Tcl_SetObjResult(interp, Tcl_NewIntObj(conn->numRows(resHandle)));
 	return TCL_OK;
@@ -97,13 +70,3 @@
 // -------------------------------------------------------------
-int fetchrowCmd(Tcl_Interp *interp, Sql_interface *conn, char *handle) {
-
-	int resHandle = 0;
-	if (handle) {
-		resHandle = stripPrefix(handle, RESULT_PREFIX);
-	}
-	if (resHandle < 0) {
-		Tcl_SetResult(interp, "Invalid result handle.", TCL_VOLATILE);
-		return TCL_ERROR;
-	}
-
+int fetchrowCmd(Tcl_Interp *interp, Sql_interface *conn, int resHandle) {
 	Sql_row *row;
@@ -124,6 +87,7 @@
 //
-int SqlCmd(ClientData clientData, Tcl_Interp *interp, int argc, char **argv) 
+int SqlCmd(ClientData clientData, Tcl_Interp *interp,
+	int objc, Tcl_Obj * const objv[]) 
 {
-	if (argc == 1) {
-		Tcl_SetResult(interp, "Usage: sql command ?handle?", TCL_STATIC);
+	if (objc == 1) {
+		Tcl_WrongNumArgs(interp, 1, objv, "command ?handle?");
 		return TCL_ERROR;
@@ -133,58 +97,58 @@
 	Manager_sql *mgr = (Manager_sql *)clientData;
-	int res = TCL_OK;
+	int res;
 
-	int c = -1;
+	int connid;
 
-	// -----------------------------------
-	if (strcmp(argv[1], "connect")==0) {
-		c = mgr->connect(argc-2, argv+2);
-		if (c < 0) {
-			char *basemsg = "Unable to Connect: ";
-			char *errmsg = mgr->getErrorMsg();
-			char *msg = Tcl_Alloc(strlen(errmsg)+strlen(basemsg));
-			strcpy(msg, basemsg);
-			strcat(msg, errmsg);
-			Tcl_SetResult(interp, msg, TCL_DYNAMIC);
+	static CONST84 char * subCmds[] = {
+		"exec", "query", "endquery", "fetchrow",
+		"numrows", "disconnect", "selectdb", "connect",
+		(char *)NULL
+	};
+	enum e_subcommands {
+		Execute, Query, EndQuery, FetchRow,
+		NumRows, Disconnect, SelectDB, Connect
+	} subcommand;
+	if (Tcl_GetIndexFromObj(interp, objv[1], subCmds, "subcommand", 0,
+			(int *) &subcommand) != TCL_OK) return TCL_ERROR;
+	if (subcommand == Connect) {
+		char *argv[objc-2];
+		for (res = 0; res < objc-2; res++) {
+			argv[res] = Tcl_GetString(objv[res+2]);
+		}
+		connid = mgr->connect(objc-2, argv);
+		if (connid < 0) {
+			Tcl_SetResult(interp, (char *)mgr->getErrorMsg(), TCL_STATIC);
 			return TCL_ERROR;
 		}
-		char errormsg[16];
-		sprintf(errormsg, "%s%d", HANDLE_PREFIX, c);
-		Tcl_SetResult(interp,errormsg,TCL_VOLATILE);
-		/* sprintf(interp->result, "%s%d", HANDLE_PREFIX, c); */
+		Tcl_SetObjResult(interp, Tcl_NewIntObj(connid));
 		return TCL_OK;
+	}
 
-	} else {
-
-		// Every other command needs a handle. Get it.
-		int connid = -1;
-		if (argc <= 2) {
-			Tcl_SetResult(interp, "Usage:\nsql command handle", TCL_STATIC);
-			return TCL_ERROR;
-		} else if ((connid = stripPrefix(argv[2], HANDLE_PREFIX)) < 0) {
-			Tcl_AppendResult(interp, "sql: Invalid handle: ", argv[2], NULL);
-			return TCL_ERROR;
-		} else if (!mgr->inUse(connid)) {
-			// This connection is not currently being used
-			Tcl_AppendResult(interp, "sql: not connected on handle ", argv[2], NULL);
-			return TCL_ERROR;
-		}
-		Sql_interface *conn = mgr->connection(connid);
+	// Every other command needs a handle. Get it.
+	if (objc <= 2) {
+		Tcl_WrongNumArgs(interp, 2, objv, "handle");
+		return TCL_ERROR;
+	} else if (Tcl_GetIntFromObj(NULL, objv[2], &connid)
+				!= TCL_OK || connid < 0) {
+		Tcl_SetObjResult(interp, objv[2]);
+		Tcl_AppendResult(interp, ": invalid handle", NULL);
+		return TCL_ERROR;
+	} else if (!mgr->inUse(connid)) {
+		// This connection is not currently being used
+		Tcl_SetObjResult(interp, objv[2]);
+		Tcl_AppendResult(interp, ": not connected on "
+			"this handle", NULL);
+		return TCL_ERROR;
+	}
+	Sql_interface *conn = mgr->connection(connid);
 
-		// take care of the command:
-		if (strcmp(argv[1], "exec") == 0) {
-			res = execCmd(interp, conn, argv[3]);
-		} else if (strcmp(argv[1], "query") == 0) {
-			res = queryCmd(interp, conn, argv[3]);
-		} else if (strcmp(argv[1], "endquery") == 0) {
-			res = endqueryCmd(interp, conn, argv[3]);
-		} else if (strcmp(argv[1], "fetchrow") == 0) {
-			res = fetchrowCmd(interp, conn, argv[3]);
-		} else if (strcmp(argv[1], "numrows") == 0) {
-			res = numrowsCmd(interp, conn, argv[3]);
-		} else if (strcmp(argv[1], "disconnect") == 0) {
-			res = disconnectCmd(interp, mgr, connid);
-		} else if (strcmp(argv[1], "selectdb")==0) {
-			res = selectdbCmd(interp, conn, argv[3]);
-		} else {
-			Tcl_AppendResult(interp, "sql: unknown sql command: ", argv[1], NULL);
+	// take care of the command:
+	if (subcommand < Disconnect && subcommand > Query) {
+		/* get the "result handle" returned previously */
+		if (objc < 4) res = 0; /* oddly, this is how it was -- bug? */
+		else if (Tcl_GetIntFromObj(NULL, objv[3], &res) != TCL_OK ||
+				res < 0) {
+			Tcl_SetObjResult(interp, objv[3]);
+			Tcl_AppendResult(interp, ": invalid result"
+				" handle", NULL);
 			return TCL_ERROR;
@@ -192,16 +156,26 @@
 	}
-	
-	return res;
-
+	switch (subcommand) {
+		case Execute:
+			return execCmd(interp, conn, Tcl_GetString(objv[3]));
+		case Query:
+			return queryCmd(interp, conn, Tcl_GetString(objv[3]));
+		case EndQuery:
+			return endqueryCmd(interp, conn, res);
+		case FetchRow:
+			return fetchrowCmd(interp, conn, res);
+		case NumRows:
+			return numrowsCmd(interp, conn, res);
+		case Disconnect:
+			return disconnectCmd(interp, mgr, connid);
+		case SelectDB:
+			return selectdbCmd(interp, conn, objv[3]);
+		/* default not needed -- handled by Tcl_GetIndexFromObj *\
+		\* if you suspect a programming error -- uncomment:     */
 #if 0
-	// Return the result of the command:
-	char returnValue[10];
-	sprintf(returnValue, "%d", c);
-
-	// The TCL_VOLATILE means the memory for our returnValue was allocated
-	// from the stack. See Tcl_SetResult for details.
-	Tcl_SetResult(interp, returnValue, TCL_VOLATILE);
-
-	return TCL_OK;
+		default:
+			Tcl_SetResult(interp, "this is not reachable",
+				TCL_STATIC);
 #endif
+	}
+	return TCL_ERROR; /* not reachable */
 }
@@ -222,3 +196,4 @@
 //
-int Sql_Init(Tcl_Interp *interp) {
+int
+Sql_Init(Tcl_Interp *interp) {
 
@@ -226,7 +201,7 @@
 
-	Tcl_CreateCommand (interp, "sql", SqlCmd ,(ClientData) s,
-										 (Tcl_CmdDeleteProc*) NULL);
+	Tcl_CreateObjCommand (interp, "sql", SqlCmd, (ClientData)s,
+		 (Tcl_CmdDeleteProc*) NULL);
 
-	// Provide a package called Sample 
-	if (Tcl_PkgProvide(interp, "Sql", "1.0") == TCL_ERROR)
+	// Provide a package called ``sql'' 
+	if (Tcl_PkgProvide(interp, "sql", "1.1") == TCL_ERROR)
 		return TCL_ERROR;
