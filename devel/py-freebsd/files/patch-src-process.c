--- src/process.c.orig	2005-05-08 06:55:00 UTC
+++ src/process.c
@@ -51,10 +51,19 @@ static char PyFB_setprogname__doc__[] =
 static PyObject *
 PyFB_setprogname(PyObject *self, PyObject *args)
 {
-	char *progname;
+	const char	*progname;
+	static PyObject	*namestr = NULL;
 
 	if (!PyArg_ParseTuple(args, "s:setprogname", &progname))
 		return NULL;
+	/*
+	 * Setprogname(3) does not copy the string, it only stores the
+	 * string pointer. Make sure that the string object does not
+	 * get garbage collected and its memory reused!
+	 */
+	Py_XDECREF(namestr);	/* maybe free old progname */
+	PyArg_ParseTuple(args, "O", &namestr);
+	Py_INCREF(namestr);	/* keep new progname object */
 
 	setprogname(progname);
 	Py_RETURN_NONE;
@@ -64,16 +73,24 @@ PyFB_setprogname(PyObject *self, PyObjec
 static char PyFB_setproctitle__doc__[] =
 "setproctitle(title):\n"
 "The setproctitle() library routine sets the process title that\n"
-"appears on the ps(1) command.";
+"appears on the ps(1) command. The progname and a colon are\n"
+"prepended automatically. This behaviour is suppressed when the\n"
+"title starts with a dash (-) character. Calling with a None\n"
+"argument restores a default process title.";
 
 static PyObject *
 PyFB_setproctitle(PyObject *self, PyObject *args)
 {
-	char *newtitle;
+	const char *newtitle;
 
-	if (!PyArg_ParseTuple(args, "s:setproctitle", &newtitle))
+	if (!PyArg_ParseTuple(args, "z:setproctitle", &newtitle))
 		return NULL;
 
-	setproctitle(newtitle);
+	if (newtitle == NULL)
+		setproctitle(NULL);
+	else if (*newtitle == '-')
+		setproctitle("-%s", newtitle+1);
+	else
+		setproctitle("%s", newtitle);
 	Py_RETURN_NONE;
 }
