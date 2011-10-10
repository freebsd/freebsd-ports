--- _bsddb.c.orig	2006-10-06 02:49:36.000000000 +0800
+++ _bsddb.c	2011-10-10 10:29:43.469871000 +0800
@@ -162,8 +162,10 @@
 static PyObject* DBRunRecoveryError;    /* DB_RUNRECOVERY */
 static PyObject* DBVerifyBadError;      /* DB_VERIFY_BAD */
 static PyObject* DBNoServerError;       /* DB_NOSERVER */
+#if (DBVER < 50)
 static PyObject* DBNoServerHomeError;   /* DB_NOSERVER_HOME */
 static PyObject* DBNoServerIDError;     /* DB_NOSERVER_ID */
+#endif
 #if (DBVER >= 33)
 static PyObject* DBPageNotFoundError;   /* DB_PAGE_NOTFOUND */
 static PyObject* DBSecondaryBadError;   /* DB_SECONDARY_BAD */
@@ -187,6 +189,9 @@
 #define	DB_BUFFER_SMALL		ENOMEM
 #endif
 
+#if (DBVER < 48)
+#define DB_GID_SIZE             DB_XIDDATASIZE
+#endif
 
 /* --------------------------------------------------------------------- */
 /* Structure definitions */
@@ -544,8 +549,10 @@
         case DB_RUNRECOVERY:        errObj = DBRunRecoveryError;    break;
         case DB_VERIFY_BAD:         errObj = DBVerifyBadError;      break;
         case DB_NOSERVER:           errObj = DBNoServerError;       break;
+#if (DBVER < 50)
         case DB_NOSERVER_HOME:      errObj = DBNoServerHomeError;   break;
         case DB_NOSERVER_ID:        errObj = DBNoServerIDError;     break;
+#endif
 #if (DBVER >= 33)
         case DB_PAGE_NOTFOUND:      errObj = DBPageNotFoundError;   break;
         case DB_SECONDARY_BAD:      errObj = DBSecondaryBadError;   break;
@@ -3831,6 +3838,7 @@
 }
 
 
+#if (DBVER < 45)
 static PyObject*
 DBEnv_set_lk_max(DBEnvObject* self, PyObject* args)
 {
@@ -3846,6 +3854,7 @@
     RETURN_IF_ERR();
     RETURN_NONE();
 }
+#endif
 
 
 #if (DBVER >= 32)
@@ -4317,9 +4326,9 @@
     if (!PyArg_ParseTuple(args, "s#:prepare", &gid, &gid_size))
         return NULL;
 
-    if (gid_size != DB_XIDDATASIZE) {
+    if (gid_size != DB_GID_SIZE) {
         PyErr_SetString(PyExc_TypeError,
-                        "gid must be DB_XIDDATASIZE bytes long");
+                        "gid must be DB_GID_SIZE bytes long");
         return NULL;
     }
 
@@ -4532,7 +4541,9 @@
     {"set_lg_dir",      (PyCFunction)DBEnv_set_lg_dir,       METH_VARARGS},
     {"set_lg_max",      (PyCFunction)DBEnv_set_lg_max,       METH_VARARGS},
     {"set_lk_detect",   (PyCFunction)DBEnv_set_lk_detect,    METH_VARARGS},
+#if (DBVER < 45)
     {"set_lk_max",      (PyCFunction)DBEnv_set_lk_max,       METH_VARARGS},
+#endif
 #if (DBVER >= 32)
     {"set_lk_max_locks", (PyCFunction)DBEnv_set_lk_max_locks, METH_VARARGS},
     {"set_lk_max_lockers", (PyCFunction)DBEnv_set_lk_max_lockers, METH_VARARGS},
@@ -4574,6 +4585,7 @@
 static PyObject*
 DBEnv_getattr(DBEnvObject* self, char *name)
 {
+#if (DBVER < 46)
     if (!strcmp(name, "db_home")) {
         CHECK_ENV_NOT_CLOSED(self);
         if (self->db_env->db_home == NULL) {
@@ -4581,6 +4593,7 @@
         }
         return PyString_FromString(self->db_env->db_home);
     }
+#endif
 
     return Py_FindMethod(DBEnv_methods, (PyObject* )self, name);
 }
@@ -4886,13 +4899,17 @@
     ADD_INT(d, DB_MAX_RECORDS);
 
 #if (DBVER >= 42)
+#if (DBVER < 50)
     ADD_INT(d, DB_RPCCLIENT);
+#endif
 #else
     ADD_INT(d, DB_CLIENT);
     /* allow apps to be written using DB_RPCCLIENT on older BerkeleyDB */
     _addIntToDict(d, "DB_RPCCLIENT", DB_CLIENT);
 #endif
+#if (DBVER < 48 || DBVER > 51)
     ADD_INT(d, DB_XA_CREATE);
+#endif
 
     ADD_INT(d, DB_CREATE);
     ADD_INT(d, DB_NOMMAP);
@@ -5039,7 +5056,9 @@
     ADD_INT(d, DB_AFTER);
     ADD_INT(d, DB_APPEND);
     ADD_INT(d, DB_BEFORE);
+#if (DBVER < 45)
     ADD_INT(d, DB_CACHED_COUNTS);
+#endif
 #if (DBVER >= 41)
     _addIntToDict(d, "DB_CHECKPOINT", 0);
 #else
@@ -5074,7 +5093,9 @@
     ADD_INT(d, DB_POSITION);
     ADD_INT(d, DB_PREV);
     ADD_INT(d, DB_PREV_NODUP);
+#if (DBVER < 45)
     ADD_INT(d, DB_RECORDCOUNT);
+#endif
     ADD_INT(d, DB_SET);
     ADD_INT(d, DB_SET_RANGE);
     ADD_INT(d, DB_SET_RECNO);
@@ -5107,8 +5128,10 @@
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
@@ -5130,15 +5153,17 @@
     ADD_INT(d, DB_TIME_NOTGRANTED);
     ADD_INT(d, DB_TXN_NOT_DURABLE);
     ADD_INT(d, DB_TXN_WRITE_NOSYNC);
+#if (DBVER < 47)
     ADD_INT(d, DB_LOG_AUTOREMOVE);
     ADD_INT(d, DB_DIRECT_LOG);
+#endif
     ADD_INT(d, DB_DIRECT_DB);
     ADD_INT(d, DB_INIT_REP);
     ADD_INT(d, DB_ENCRYPT);
     ADD_INT(d, DB_CHKSUM);
 #endif
 
-#if (DBVER >= 43)
+#if (DBVER >= 43) && (DBVER < 47)
     ADD_INT(d, DB_LOG_INMEMORY);
     ADD_INT(d, DB_BUFFER_SMALL);
 #endif
@@ -5203,8 +5228,10 @@
     MAKE_EX(DBRunRecoveryError);
     MAKE_EX(DBVerifyBadError);
     MAKE_EX(DBNoServerError);
+#if (DBVER < 50)
     MAKE_EX(DBNoServerHomeError);
     MAKE_EX(DBNoServerIDError);
+#endif
 #if (DBVER >= 33)
     MAKE_EX(DBPageNotFoundError);
     MAKE_EX(DBSecondaryBadError);
