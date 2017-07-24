--- _mysql.c.orig	2014-01-02 19:15:03 UTC
+++ _mysql.c
@@ -124,6 +124,10 @@ static int _mysql_server_init_done = 0;
 #define HAVE_MYSQL_OPT_TIMEOUTS 1
 #endif
 
+#if MYSQL_VERSION_ID >= 50500
+#define HAVE_OPENSSL 1
+#endif
+
 PyObject *
 _mysql_Exception(_mysql_ConnectionObject *c)
 {
@@ -2002,7 +2006,9 @@ _mysql_ConnectionObject_ping(
 	int r, reconnect = -1;
 	if (!PyArg_ParseTuple(args, "|I", &reconnect)) return NULL;
 	check_connection(self);
-	if ( reconnect != -1 ) self->connection.reconnect = reconnect;
+	if (reconnect != -1) {
+		mysql_options(&self->connection, MYSQL_OPT_RECONNECT, &reconnect);
+	}
 	Py_BEGIN_ALLOW_THREADS
 	r = mysql_ping(&(self->connection));
 	Py_END_ALLOW_THREADS
