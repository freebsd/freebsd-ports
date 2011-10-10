--- _bsddb.c.orig	2010-05-09 23:15:40.000000000 +0800
+++ _bsddb.c	2011-10-10 10:29:43.469871000 +0800
@@ -186,8 +186,10 @@
 static PyObject* DBRunRecoveryError;    /* DB_RUNRECOVERY */
 static PyObject* DBVerifyBadError;      /* DB_VERIFY_BAD */
 static PyObject* DBNoServerError;       /* DB_NOSERVER */
+#if (DBVER < 52)
 static PyObject* DBNoServerHomeError;   /* DB_NOSERVER_HOME */
 static PyObject* DBNoServerIDError;     /* DB_NOSERVER_ID */
+#endif
 static PyObject* DBPageNotFoundError;   /* DB_PAGE_NOTFOUND */
 static PyObject* DBSecondaryBadError;   /* DB_SECONDARY_BAD */
 
@@ -215,6 +217,9 @@
 #define DB_BUFFER_SMALL         ENOMEM
 #endif
 
+#if (DBVER < 48)
+#define DB_GID_SIZE             DB_XIDDATASIZE
+#endif
 
 /* --------------------------------------------------------------------- */
 /* Structure definitions */
@@ -698,8 +703,10 @@
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
@@ -4522,7 +4529,7 @@
         flags=DB_NEXT;  /* Prepare for next loop pass */
         for (i=0; i<retp; i++) {
             gid=PyBytes_FromStringAndSize((char *)(preplist[i].gid),
-                                DB_XIDDATASIZE);
+                                DB_GID_SIZE);
             if (!gid) {
                 Py_DECREF(list);
                 return NULL;
@@ -5047,6 +5054,7 @@
 }
 
 
+#if (DBVER < 50)
 static PyObject*
 DBEnv_set_rpc_server(DBEnvObject* self, PyObject* args, PyObject* kwargs)
 {
@@ -5068,6 +5076,7 @@
     RETURN_IF_ERR();
     RETURN_NONE();
 }
+#endif
 
 static PyObject*
 DBEnv_set_verbose(DBEnvObject* self, PyObject* args)
@@ -5650,6 +5659,7 @@
     RETURN_NONE();
 }
 
+#if (DBVER < 52)
 static PyObject*
 DBEnv_repmgr_set_local_site(DBEnvObject* self, PyObject* args, PyObject*
         kwargs)
@@ -5696,6 +5706,7 @@
     RETURN_IF_ERR();
     return NUMBER_FromLong(eidp);
 }
+#endif
 
 static PyObject*
 DBEnv_repmgr_set_ack_policy(DBEnvObject* self, PyObject* args)
@@ -5949,9 +5960,9 @@
     if (!PyArg_ParseTuple(args, "s#:prepare", &gid, &gid_size))
         return NULL;
 
-    if (gid_size != DB_XIDDATASIZE) {
+    if (gid_size != DB_GID_SIZE) {
         PyErr_SetString(PyExc_TypeError,
-                        "gid must be DB_XIDDATASIZE bytes long");
+                        "gid must be DB_GID_SIZE bytes long");
         return NULL;
     }
 
@@ -6541,8 +6552,10 @@
 #endif
     {"set_get_returns_none",(PyCFunction)DBEnv_set_get_returns_none, METH_VARARGS},
     {"txn_recover",     (PyCFunction)DBEnv_txn_recover,       METH_NOARGS},
+#if (DBVER < 50)
     {"set_rpc_server",  (PyCFunction)DBEnv_set_rpc_server,
         METH_VARARGS||METH_KEYWORDS},
+#endif
     {"set_verbose",     (PyCFunction)DBEnv_set_verbose,       METH_VARARGS},
 #if (DBVER >= 42)
     {"get_verbose",     (PyCFunction)DBEnv_get_verbose,       METH_VARARGS},
@@ -6584,10 +6597,12 @@
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
@@ -7092,13 +7107,17 @@
     ADD_INT(d, DB_MAX_RECORDS);
 
 #if (DBVER >= 42)
+#if (DBVER < 50)
     ADD_INT(d, DB_RPCCLIENT);
+#endif
 #else
     ADD_INT(d, DB_CLIENT);
     /* allow apps to be written using DB_RPCCLIENT on older Berkeley DB */
     _addIntToDict(d, "DB_RPCCLIENT", DB_CLIENT);
 #endif
+#if (DBVER < 48 || DBVER > 51)
     ADD_INT(d, DB_XA_CREATE);
+#endif
 
     ADD_INT(d, DB_CREATE);
     ADD_INT(d, DB_NOMMAP);
@@ -7115,7 +7134,7 @@
     ADD_INT(d, DB_INIT_TXN);
     ADD_INT(d, DB_JOINENV);
 
-    ADD_INT(d, DB_XIDDATASIZE);
+    ADD_INT(d, DB_GID_SIZE);
 
     ADD_INT(d, DB_RECOVER);
     ADD_INT(d, DB_RECOVER_FATAL);
@@ -7296,8 +7315,10 @@
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
@@ -7512,8 +7533,10 @@
     MAKE_EX(DBRunRecoveryError);
     MAKE_EX(DBVerifyBadError);
     MAKE_EX(DBNoServerError);
+#if (DBVER < 52)
     MAKE_EX(DBNoServerHomeError);
     MAKE_EX(DBNoServerIDError);
+#endif
     MAKE_EX(DBPageNotFoundError);
     MAKE_EX(DBSecondaryBadError);
 
