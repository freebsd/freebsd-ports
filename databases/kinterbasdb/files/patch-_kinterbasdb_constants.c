--- _kinterbasdb_constants.c.dist	Wed Dec  3 00:07:47 2003
+++ _kinterbasdb_constants.c	Wed Dec  3 00:09:09 2003
@@ -45,8 +45,8 @@
 ** The point of SET_TPB_CONST is to enter into dict d the equivalent of the
 ** Python string '\020', when passed the name and value of isc_some_dumb_const.
  */
-#define SET_TPB_CONST(name, value) \
-  convArray[0] = (char) value; \
+#define SET_TPB_CONST(name, value) \
+  convArray[0] = (char) value; \
   PyDict_SetItemString(d, name, PyString_FromStringAndSize(convArray, 1));
 
   /* 2003.02.20: added isc_tpb_version3: */
@@ -85,7 +85,7 @@
 static void _init_kidb_ibase_header_constants_database_info(PyObject *d) {
 /* SET_INT_CONST is just a shortcut for entering database info constants into
 ** dict d. */
-#define SET_INT_CONST(name, value) \
+#define SET_INT_CONST(name, value) \
   PyDict_SetItemString(d, name, PyInt_FromLong(value));
 
   SET_INT_CONST("isc_info_db_id",                   isc_info_db_id);
