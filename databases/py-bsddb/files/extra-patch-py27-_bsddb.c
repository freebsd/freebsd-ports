--- _bsddb.c.orig	2011-06-11 23:46:26.000000000 +0800
+++ _bsddb.c	2011-10-10 10:29:43.469871000 +0800
@@ -187,8 +187,10 @@
 static PyObject* DBRunRecoveryError;    /* DB_RUNRECOVERY */
 static PyObject* DBVerifyBadError;      /* DB_VERIFY_BAD */
 static PyObject* DBNoServerError;       /* DB_NOSERVER */
+#if (DBVER < 52)
 static PyObject* DBNoServerHomeError;   /* DB_NOSERVER_HOME */
 static PyObject* DBNoServerIDError;     /* DB_NOSERVER_ID */
+#endif
 static PyObject* DBPageNotFoundError;   /* DB_PAGE_NOTFOUND */
 static PyObject* DBSecondaryBadError;   /* DB_SECONDARY_BAD */
 
@@ -696,8 +698,10 @@
         case DB_RUNRECOVERY:        errObj = DBRunRecoveryError;    break;
         case DB_VERIFY_BAD:         errObj = DBVerifyBadError;      break;
         case DB_NOSERVER:           errObj = DBNoServerError;       break;
+#if (DBVER < 52)
         case DB_NOSERVER_HOME:      errObj = DBNoServerHomeError;   break;
         case DB_NOSERVER_ID:        errObj = DBNoServerIDError;     break;
+#endif
         case DB_PAGE_NOTFOUND:      errObj = DBPageNotFoundError;   break;
         case DB_SECONDARY_BAD:      errObj = DBSecondaryBadError;   break;
         case DB_BUFFER_SMALL:       errObj = DBNoMemoryError;       break;
@@ -7608,6 +7612,7 @@
     RETURN_NONE();
 }
 
+#if (DBVER < 52)
 static PyObject*
 DBEnv_repmgr_set_local_site(DBEnvObject* self, PyObject* args, PyObject*
         kwargs)
@@ -7654,6 +7659,7 @@
     RETURN_IF_ERR();
     return NUMBER_FromLong(eidp);
 }
+#endif
 
 static PyObject*
 DBEnv_repmgr_set_ack_policy(DBEnvObject* self, PyObject* args)
@@ -8855,10 +8861,12 @@
 #if (DBVER >= 45)
     {"repmgr_start", (PyCFunction)DBEnv_repmgr_start,
         METH_VARARGS|METH_KEYWORDS},
+#if (DBVER < 52)
     {"repmgr_set_local_site", (PyCFunction)DBEnv_repmgr_set_local_site,
         METH_VARARGS|METH_KEYWORDS},
     {"repmgr_add_remote_site", (PyCFunction)DBEnv_repmgr_add_remote_site,
         METH_VARARGS|METH_KEYWORDS},
+#endif
     {"repmgr_set_ack_policy", (PyCFunction)DBEnv_repmgr_set_ack_policy,
         METH_VARARGS},
     {"repmgr_get_ack_policy", (PyCFunction)DBEnv_repmgr_get_ack_policy,
@@ -9437,7 +9445,7 @@
 #endif
 #endif
 
-#if (DBVER < 48)
+#if (DBVER < 48 || DBVER > 51)
     ADD_INT(d, DB_XA_CREATE);
 #endif
 
@@ -9651,8 +9659,10 @@
     ADD_INT(d, DB_LOCK_DEADLOCK);
     ADD_INT(d, DB_LOCK_NOTGRANTED);
     ADD_INT(d, DB_NOSERVER);
+#if (DBVER < 52)
     ADD_INT(d, DB_NOSERVER_HOME);
     ADD_INT(d, DB_NOSERVER_ID);
+#endif
     ADD_INT(d, DB_NOTFOUND);
     ADD_INT(d, DB_OLD_VERSION);
     ADD_INT(d, DB_RUNRECOVERY);
@@ -9766,7 +9776,9 @@
     ADD_INT(d, DB_REP_PERMANENT);
 
 #if (DBVER >= 44)
+#if (DBVER < 50)
     ADD_INT(d, DB_REP_CONF_NOAUTOINIT);
+#endif
     ADD_INT(d, DB_REP_CONF_DELAYCLIENT);
     ADD_INT(d, DB_REP_CONF_BULK);
     ADD_INT(d, DB_REP_CONF_NOWAIT);
@@ -9912,8 +9924,10 @@
     MAKE_EX(DBRunRecoveryError);
     MAKE_EX(DBVerifyBadError);
     MAKE_EX(DBNoServerError);
+#if (DBVER < 52)
     MAKE_EX(DBNoServerHomeError);
     MAKE_EX(DBNoServerIDError);
+#endif
     MAKE_EX(DBPageNotFoundError);
     MAKE_EX(DBSecondaryBadError);
 
