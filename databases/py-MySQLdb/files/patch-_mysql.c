--- _mysql.c.orig	Sat Jan  1 15:40:13 2005
+++ _mysql.c	Wed Jan  5 18:35:18 2005
@@ -1542,7 +1542,11 @@
 	if (!PyArg_ParseTuple(args, "")) return NULL;
 	check_connection(self);
 	Py_BEGIN_ALLOW_THREADS
+#if MYSQL_VERSION_ID >= 40103
+	r = mysql_shutdown(&(self->connection), SHUTDOWN_DEFAULT);
+#else
 	r = mysql_shutdown(&(self->connection));
+#endif
 	Py_END_ALLOW_THREADS
 	if (r) return _mysql_Exception(self);
 	Py_INCREF(Py_None);
