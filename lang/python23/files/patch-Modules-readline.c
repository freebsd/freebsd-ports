--- Modules/readline.c.orig	Wed Jan 17 18:10:23 2007
+++ Modules/readline.c	Wed Jan 17 18:12:54 2007
@@ -93,7 +93,7 @@
 	return Py_None;
 }
 
-static int history_length = -1; /* do not truncate history by default */
+static int _history_length = -1; /* do not truncate history by default */
 PyDoc_STRVAR(doc_read_history_file,
 "read_history_file([filename]) -> None\n\
 Load a readline history file.\n\
@@ -109,8 +109,8 @@
 	if (!PyArg_ParseTuple(args, "|z:write_history_file", &s))
 		return NULL;
 	errno = write_history(s);
-	if (!errno && history_length >= 0)
-		history_truncate_file(s, history_length);
+	if (!errno && _history_length >= 0)
+		history_truncate_file(s, _history_length);
 	if (errno)
 		return PyErr_SetFromErrno(PyExc_IOError);
 	Py_INCREF(Py_None);
@@ -128,10 +128,10 @@
 static PyObject*
 set_history_length(PyObject *self, PyObject *args)
 {
-	int length = history_length;
+	int length = _history_length;
 	if (!PyArg_ParseTuple(args, "i:set_history_length", &length))
 		return NULL;
-	history_length = length;
+	_history_length = length;
 	Py_INCREF(Py_None);
 	return Py_None;
 }
@@ -148,7 +148,7 @@
 static PyObject*
 get_history_length(PyObject *self, PyObject *noarg)
 {
-	return PyInt_FromLong(history_length);
+	return PyInt_FromLong(_history_length);
 }
 
 PyDoc_STRVAR(get_history_length_doc,
