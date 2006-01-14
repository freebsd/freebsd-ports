--- generic/mysqltcl.c.orig	Wed Jan 11 21:08:48 2006
+++ generic/mysqltcl.c	Wed Jan 11 21:17:10 2006
@@ -95,6 +95,8 @@
 /* C variable corresponding to mysqlstatus(nullvalue) */
 #define MYSQL_NULLV_INIT ""
 
+#define FUNCTION_NOT_AVAILABLE "function not available"
+
 /* Check Level for mysql_prologue */
 enum CONNLEVEL {CL_PLAIN,CL_CONN,CL_DB,CL_RES};
 
@@ -183,7 +185,6 @@
 static int MysqlNullSet(Tcl_Interp *interp, Tcl_Obj *objPtr)
 {
     Tcl_ObjType *oldTypePtr = objPtr->typePtr;
-    Tcl_HashEntry *entryPtr;
 
     if ((oldTypePtr != NULL) && (oldTypePtr->freeIntRepProc != NULL)) {
         oldTypePtr->freeIntRepProc(objPtr);
@@ -803,6 +804,7 @@
       if (booleanflag)
 	flags |= CLIENT_ODBC;
       break;
+#if (MYSQL_VERSION_ID >= 40107)
     case MYSQL_MULTISTATEMENT_OPT:
       if (Tcl_GetBooleanFromObj(interp,objv[++i],&booleanflag) != TCL_OK )
 	return TCL_ERROR;
@@ -817,6 +819,7 @@
       if (booleanflag)
 	flags |= CLIENT_MULTI_RESULTS;
       break;
+#endif
 
     case MYSQL_LOCALFILES_OPT:
       if (Tcl_GetBooleanFromObj(interp,objv[++i],&booleanflag) != TCL_OK )
@@ -876,9 +879,11 @@
 #if (MYSQL_VERSION_ID>=32350)
   mysql_options(handle->connection,MYSQL_READ_DEFAULT_GROUP,groupname);
 #endif
+#if (MYSQL_VERSION_ID >= 40107)
   if (isSSL) {
       mysql_ssl_set(handle->connection,sslkey,sslcert, sslca, sslcapath, sslcipher);
   }
+#endif
 
   if (!mysql_real_connect(handle->connection, hostname, user,
                                 password, db, port, socket, flags)) {
@@ -1388,8 +1393,8 @@
 static int Mysqltcl_Receive(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
   MysqltclState *statePtr = (MysqltclState *)clientData;
-  int code ;
-  int count ;
+  int code = TCL_ERROR;
+  int count = 0;
 
   MysqlTclHandle *handle;
   int idx ;
@@ -1397,7 +1402,6 @@
   Tcl_Obj** listObjv ;
   MYSQL_ROW row ;
   int *val = NULL;
-  int breakLoop = 0;
   unsigned long *lengths;
 
 
@@ -1455,15 +1459,9 @@
       switch(code=Tcl_EvalObjEx(interp, objv[4],0)) {
       case TCL_CONTINUE:
       case TCL_OK:
-	break ;
-      case TCL_BREAK:
-	breakLoop=1;
-	break;
-      default:
-	breakLoop=1;
-	break;
+       continue;
       }
-      if (breakLoop==1) break;
+      break;
     }
   }
   if (val!=NULL) {
@@ -1592,6 +1590,7 @@
       Tcl_SetObjResult(interp, Tcl_NewStringObj(val,-1));
     }
     break;
+#if (MYSQL_VERSION_ID >= 40107)
   case MYSQL_INF_SERVERVERSION:
      Tcl_SetObjResult(interp, Tcl_NewStringObj(mysql_get_server_info(handle->connection),-1));
      break;
@@ -1604,6 +1603,7 @@
   case MYSQL_INFO_STATE:
      Tcl_SetObjResult(interp, Tcl_NewStringObj(mysql_stat(handle->connection),-1));
      break;
+#endif
   default: /* should never happen */
     return mysql_prim_confl(interp,objc,objv,"weirdness in Mysqltcl_Info") ;
   }
@@ -1625,6 +1625,7 @@
   int idx ;
   Tcl_Obj *resList;
   char **option;
+#if (MYSQL_VERSION_ID >= 40107)
   static CONST char* MysqlInfoOpt[] =
     {
       "connectparameters", "clientversion","clientversionid", NULL
@@ -1632,6 +1633,15 @@
   enum baseoption {
     MYSQL_BINFO_CONNECT, MYSQL_BINFO_CLIENTVERSION,MYSQL_BINFO_CLIENTVERSIONID
   };
+#else
+  static CONST char* MysqlInfoOpt[] =
+    {
+      "connectparameters", "clientversion", NULL
+    };
+  enum baseoption {
+    MYSQL_BINFO_CONNECT, MYSQL_BINFO_CLIENTVERSION
+  };
+#endif
 
   if (objc <2) {
       Tcl_WrongNumArgs(interp, 1, objv, "connectparameters | clientversion");
@@ -1657,9 +1667,11 @@
   case MYSQL_BINFO_CLIENTVERSION:
     Tcl_SetObjResult(interp, Tcl_NewStringObj(mysql_get_client_info(),-1));
     break;
+#if (MYSQL_VERSION_ID >= 40107)
   case MYSQL_BINFO_CLIENTVERSIONID:
     Tcl_SetObjResult(interp, Tcl_NewIntObj(mysql_get_client_version()));
     break;
+#endif
   }
   return TCL_OK ;
 }
@@ -1974,6 +1986,10 @@
 
 static int Mysqltcl_AutoCommit(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int isAutocommit = 0;
 
@@ -1986,6 +2002,7 @@
   	mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -1997,6 +2014,10 @@
 
 static int Mysqltcl_Commit(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
 
   if ((handle = mysql_prologue(interp, objc, objv, 2, 2, CL_CONN,
@@ -2006,6 +2027,7 @@
   	mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2017,6 +2039,10 @@
 
 static int Mysqltcl_Rollback(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
 
   if ((handle = mysql_prologue(interp, objc, objv, 2, 2, CL_CONN,
@@ -2026,6 +2052,7 @@
       mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2037,6 +2064,10 @@
 
 static int Mysqltcl_MoreResult(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int boolResult = 0;
 
@@ -2046,6 +2077,7 @@
   boolResult =  mysql_more_results(handle->connection);
   Tcl_SetObjResult(interp,Tcl_NewBooleanObj(boolResult));
   return TCL_OK;
+#endif
 }
 /*
 
@@ -2059,6 +2091,10 @@
 
 static int Mysqltcl_NextResult(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int result = 0;
 
@@ -2085,6 +2121,7 @@
       Tcl_SetObjResult(interp, Tcl_NewIntObj(handle->res_count));
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2096,6 +2133,10 @@
 
 static int Mysqltcl_WarningCount(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int count = 0;
 
@@ -2105,6 +2146,7 @@
   count = mysql_warning_count(handle->connection);
   Tcl_SetObjResult(interp,Tcl_NewIntObj(count));
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2149,7 +2191,6 @@
 
 static int Mysqltcl_NewNull(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
-  Tcl_Obj *objPtr;
   if (objc != 1) {
       Tcl_WrongNumArgs(interp, 1, objv, "");
       return TCL_ERROR;
@@ -2164,13 +2205,19 @@
  *    usage: mysql::setserveroption (-
  *
  */
+#if (MYSQL_VERSION_ID >= 40107)
 static CONST char* MysqlServerOpt[] =
     {
       "-multi_statment_on", "-multi_statment_off",NULL
     };
+#endif
 
 static int Mysqltcl_SetServerOption(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int idx;
   enum enum_mysql_set_option mysqlServerOption;
@@ -2201,6 +2248,7 @@
   	mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2211,6 +2259,10 @@
  */
 static int Mysqltcl_ShutDown(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
 
   if ((handle = mysql_prologue(interp, objc, objv, 2, 2, CL_CONN,
@@ -2220,6 +2272,7 @@
   	mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
