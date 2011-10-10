--- _bsddb.c.orig	2008-05-17 14:46:39.000000000 +0800
+++ _bsddb.c	2011-10-10 10:29:43.469871000 +0800
@@ -167,8 +167,10 @@
 static PyObject* DBRunRecoveryError;    /* DB_RUNRECOVERY */
 static PyObject* DBVerifyBadError;      /* DB_VERIFY_BAD */
 static PyObject* DBNoServerError;       /* DB_NOSERVER */
+#if (DBVER < 52)
 static PyObject* DBNoServerHomeError;   /* DB_NOSERVER_HOME */
 static PyObject* DBNoServerIDError;     /* DB_NOSERVER_ID */
+#endif
 #if (DBVER >= 33)
 static PyObject* DBPageNotFoundError;   /* DB_PAGE_NOTFOUND */
 static PyObject* DBSecondaryBadError;   /* DB_SECONDARY_BAD */
@@ -192,6 +194,9 @@
 #define	DB_BUFFER_SMALL		ENOMEM
 #endif
 
+#if (DBVER < 48)
+#define DB_GID_SIZE             DB_XIDDATASIZE
+#endif
 
 /* --------------------------------------------------------------------- */
 /* Structure definitions */
@@ -581,8 +586,10 @@
         case DB_RUNRECOVERY:        errObj = DBRunRecoveryError;    break;
         case DB_VERIFY_BAD:         errObj = DBVerifyBadError;      break;
         case DB_NOSERVER:           errObj = DBNoServerError;       break;
+#if (DBVER < 52)
         case DB_NOSERVER_HOME:      errObj = DBNoServerHomeError;   break;
         case DB_NOSERVER_ID:        errObj = DBNoServerIDError;     break;
+#endif
 #if (DBVER >= 33)
         case DB_PAGE_NOTFOUND:      errObj = DBPageNotFoundError;   break;
         case DB_SECONDARY_BAD:      errObj = DBSecondaryBadError;   break;
@@ -4737,9 +4744,9 @@
     if (!PyArg_ParseTuple(args, "s#:prepare", &gid, &gid_size))
         return NULL;
 
-    if (gid_size != DB_XIDDATASIZE) {
+    if (gid_size != DB_GID_SIZE) {
         PyErr_SetString(PyExc_TypeError,
-                        "gid must be DB_XIDDATASIZE bytes long");
+                        "gid must be DB_GID_SIZE bytes long");
         return NULL;
     }
 
@@ -5332,6 +5339,7 @@
 static PyObject*
 DBEnv_getattr(DBEnvObject* self, char *name)
 {
+#if (DBVER < 46)
     if (!strcmp(name, "db_home")) {
         CHECK_ENV_NOT_CLOSED(self);
         if (self->db_env->db_home == NULL) {
@@ -5339,6 +5347,7 @@
         }
         return PyString_FromString(self->db_env->db_home);
     }
+#endif
 
     return Py_FindMethod(DBEnv_methods, (PyObject* )self, name);
 }
@@ -5708,13 +5717,17 @@
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
@@ -5936,8 +5949,10 @@
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
@@ -5959,15 +5974,17 @@
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
     ADD_INT(d, DB_SEQ_DEC);
