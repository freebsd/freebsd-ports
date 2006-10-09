--- generic/mysqltcl.c.orig	Mon Oct  9 14:46:31 2006
+++ generic/mysqltcl.c	Mon Oct  9 14:48:39 2006
@@ -41,12 +41,6 @@
 
 #include <tcl.h>
 #include <mysql.h>
-
-#if (MYSQL_VERSION_ID<40100)
-  #error You need Mysql version 4.1 or higher to compile mysqltcl
-#endif
-
-
 #include <errno.h>
 #include <string.h>
 #include <ctype.h>
@@ -97,6 +91,8 @@
 #define MYSQL_STATUS_MSG  "message"
 #define MYSQL_STATUS_NULLV  "nullvalue"
 
+#define FUNCTION_NOT_AVAILABLE "function not available"
+
 /* C variable corresponding to mysqlstatus(nullvalue) */
 #define MYSQL_NULLV_INIT ""
 
@@ -713,7 +709,11 @@
 static CONST char* MysqlConnectOpt[] =
     {
       "-host", "-user", "-password", "-db", "-port", "-socket","-encoding",
+#if (MYSQL_VERSION_ID >= 40107)
       "-ssl", "-compress", "-noschema","-odbc","-multistatement","-multiresult",
+#else
+      "-ssl", "-compress", "-noschema","-odbc",
+#endif
       "-localfiles","-ignorespace","-foundrows","-interactive","-sslkey","-sslcert",
       "-sslca","-sslcapath","-sslciphers",NULL
     };
@@ -730,7 +730,9 @@
   char *socket = NULL;
   char *encodingname = NULL;
 
+#if (MYSQL_VERSION_ID >= 40107)
   int isSSL = 0;
+#endif
   char *sslkey = NULL;
   char *sslcert = NULL;
   char *sslca = NULL;
@@ -745,7 +747,11 @@
     MYSQL_CONNHOST_OPT, MYSQL_CONNUSER_OPT, MYSQL_CONNPASSWORD_OPT,
     MYSQL_CONNDB_OPT, MYSQL_CONNPORT_OPT, MYSQL_CONNSOCKET_OPT, MYSQL_CONNENCODING_OPT,
     MYSQL_CONNSSL_OPT, MYSQL_CONNCOMPRESS_OPT, MYSQL_CONNNOSCHEMA_OPT, MYSQL_CONNODBC_OPT,
+#if (MYSQL_VERSION_ID >= 40107)
     MYSQL_MULTISTATEMENT_OPT,MYSQL_MULTIRESULT_OPT,MYSQL_LOCALFILES_OPT,MYSQL_IGNORESPACE_OPT,
+#else
+    MYSQL_LOCALFILES_OPT,MYSQL_IGNORESPACE_OPT,
+#endif
     MYSQL_FOUNDROWS_OPT,MYSQL_INTERACTIVE_OPT,MYSQL_SSLKEY_OPT,MYSQL_SSLCERT_OPT,
     MYSQL_SSLCA_OPT,MYSQL_SSLCAPATH_OPT,MYSQL_SSLCIPHERS_OPT
   };
@@ -786,8 +792,15 @@
       encodingname = Tcl_GetStringFromObj(objv[++i],NULL);
       break;
     case MYSQL_CONNSSL_OPT:
+#if (MYSQL_VERSION_ID >= 40107)
       if (Tcl_GetBooleanFromObj(interp,objv[++i],&isSSL) != TCL_OK )
 	return TCL_ERROR;
+#else
+      if (Tcl_GetBooleanFromObj(interp,objv[++i],&booleanflag) != TCL_OK )
+	return TCL_ERROR;
+      if (booleanflag)
+        flags |= CLIENT_SSL;
+#endif
       break;
     case MYSQL_CONNCOMPRESS_OPT:
       if (Tcl_GetBooleanFromObj(interp,objv[++i],&booleanflag) != TCL_OK )
@@ -807,13 +820,12 @@
       if (booleanflag)
 	flags |= CLIENT_ODBC;
       break;
+#if (MYSQL_VERSION_ID >= 40107)
     case MYSQL_MULTISTATEMENT_OPT:
       if (Tcl_GetBooleanFromObj(interp,objv[++i],&booleanflag) != TCL_OK )
 	return TCL_ERROR;
       if (booleanflag)
 	flags |= CLIENT_MULTI_STATEMENTS;
-
-
       break;
     case MYSQL_MULTIRESULT_OPT:
       if (Tcl_GetBooleanFromObj(interp,objv[++i],&booleanflag) != TCL_OK )
@@ -821,7 +833,7 @@
       if (booleanflag)
 	flags |= CLIENT_MULTI_RESULTS;
       break;
-
+#endif
     case MYSQL_LOCALFILES_OPT:
       if (Tcl_GetBooleanFromObj(interp,objv[++i],&booleanflag) != TCL_OK )
 	return TCL_ERROR;
@@ -877,12 +889,12 @@
   handle->connection = mysql_init(NULL);
 
   /* the function below caused in version pre 3.23.50 segmentation fault */
-#if (MYSQL_VERSION_ID>=32350)
   mysql_options(handle->connection,MYSQL_READ_DEFAULT_GROUP,groupname);
-#endif
+#if (MYSQL_VERSION_ID >= 40107)
   if (isSSL) {
       mysql_ssl_set(handle->connection,sslkey,sslcert, sslca, sslcapath, sslcipher);
   }
+#endif
 
   if (!mysql_real_connect(handle->connection, hostname, user,
                                 password, db, port, socket, flags)) {
@@ -1513,7 +1525,11 @@
   static CONST char* MysqlDbOpt[] =
     {
       "dbname", "dbname?", "tables", "host", "host?", "databases",
+#if (MYSQL_VERSION_ID >= 40107)
       "info","serverversion","serverversionid","sqlstate","state",NULL
+#else
+      "info","serverversion","state",NULL
+#endif
     };
   enum dboption {
     MYSQL_INFNAME_OPT, MYSQL_INFNAMEQ_OPT, MYSQL_INFTABLES_OPT,
@@ -1547,8 +1563,10 @@
     break;
   case MYSQL_INFO:
   case MYSQL_INF_SERVERVERSION:
+#if (MYSQL_VERSION_ID >= 40107)
   case MYSQL_INFO_SERVERVERSION_ID:
   case MYSQL_INFO_SQLSTATE:
+#endif
   case MYSQL_INFO_STATE:
     break;
 
@@ -1605,12 +1623,14 @@
   case MYSQL_INF_SERVERVERSION:
      Tcl_SetObjResult(interp, Tcl_NewStringObj(mysql_get_server_info(handle->connection),-1));
      break;
+#if (MYSQL_VERSION_ID >= 40107)
   case MYSQL_INFO_SERVERVERSION_ID:
 	 Tcl_SetObjResult(interp, Tcl_NewIntObj(mysql_get_server_version(handle->connection)));
 	 break;
   case MYSQL_INFO_SQLSTATE:
      Tcl_SetObjResult(interp, Tcl_NewStringObj(mysql_sqlstate(handle->connection),-1));
      break;
+#endif
   case MYSQL_INFO_STATE:
      Tcl_SetObjResult(interp, Tcl_NewStringObj(mysql_stat(handle->connection),-1));
      break;
@@ -1637,7 +1657,11 @@
   char **option;
   static CONST char* MysqlInfoOpt[] =
     {
+#if (MYSQL_VERSION_ID >= 40107)
       "connectparameters", "clientversion","clientversionid", NULL
+#else
+      "connectparameters", "clientversion", NULL
+#endif
     };
   enum baseoption {
     MYSQL_BINFO_CONNECT, MYSQL_BINFO_CLIENTVERSION,MYSQL_BINFO_CLIENTVERSIONID
@@ -1667,9 +1691,11 @@
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
@@ -1984,6 +2010,10 @@
 
 static int Mysqltcl_AutoCommit(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int isAutocommit = 0;
 
@@ -1996,6 +2026,7 @@
   	mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2007,6 +2038,10 @@
 
 static int Mysqltcl_Commit(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
 
   if ((handle = mysql_prologue(interp, objc, objv, 2, 2, CL_CONN,
@@ -2016,6 +2051,7 @@
   	mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2027,6 +2063,10 @@
 
 static int Mysqltcl_Rollback(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
 
   if ((handle = mysql_prologue(interp, objc, objv, 2, 2, CL_CONN,
@@ -2036,6 +2076,7 @@
       mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2047,6 +2088,10 @@
 
 static int Mysqltcl_MoreResult(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int boolResult = 0;
 
@@ -2056,6 +2101,7 @@
   boolResult =  mysql_more_results(handle->connection);
   Tcl_SetObjResult(interp,Tcl_NewBooleanObj(boolResult));
   return TCL_OK;
+#endif
 }
 /*
 
@@ -2069,6 +2115,10 @@
 
 static int Mysqltcl_NextResult(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int result = 0;
 
@@ -2095,6 +2145,7 @@
       Tcl_SetObjResult(interp, Tcl_NewIntObj(handle->res_count));
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2106,6 +2157,10 @@
 
 static int Mysqltcl_WarningCount(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
 {
+#if (MYSQL_VERSION_ID < 40107)
+  Tcl_AddErrorInfo(interp, FUNCTION_NOT_AVAILABLE);
+  return TCL_ERROR;
+#else
   MysqlTclHandle *handle;
   int count = 0;
 
@@ -2115,6 +2170,7 @@
   count = mysql_warning_count(handle->connection);
   Tcl_SetObjResult(interp,Tcl_NewIntObj(count));
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2173,13 +2229,19 @@
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
@@ -2210,6 +2272,7 @@
   	mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
+#endif
 }
 /*
  *----------------------------------------------------------------------
@@ -2225,7 +2288,11 @@
   if ((handle = mysql_prologue(interp, objc, objv, 2, 2, CL_CONN,
 			    "handle")) == 0)
     return TCL_ERROR;
+#if (MYSQL_VERSION_ID >= 40107)
   if (mysql_shutdown(handle->connection,SHUTDOWN_DEFAULT)!=0) {
+#else
+  if (mysql_shutdown(handle->connection)!=0) {
+#endif
   	mysql_server_confl(interp,objc,objv,handle->connection);
   }
   return TCL_OK;
