--- src/py_callback.cc.orig	2007-11-21 17:53:00.000000000 +0100
+++ src/py_callback.cc	2007-11-21 17:54:03.000000000 +0100
@@ -55,7 +55,7 @@
 // calls the python function without argument
 void py_callback::callback_func0 ()
 {
-    PyObject *py_arg = arguments ? Py_BuildValue ("(O)",arguments) : NULL;
+    PyObject *py_arg = arguments ? Py_BuildValue ((char *)"(O)",arguments) : NULL;
     PyObject* val = make_call (py_arg);
     Py_XDECREF (val);
 }
@@ -65,7 +65,7 @@
 {
     int retval = 1;
     
-    PyObject *py_arg = arguments ? Py_BuildValue ("(O)",arguments) : NULL;
+    PyObject *py_arg = arguments ? Py_BuildValue ((char *)"(O)",arguments) : NULL;
     PyObject* val = make_call (py_arg);
 
     if (val) retval = PyInt_AsLong (val);
@@ -79,8 +79,8 @@
 {
     PyObject *py_arg;
 
-    if (arguments) py_arg = Py_BuildValue ("(i,O)", arg, arguments);
-    else py_arg = Py_BuildValue ("(i)", arg);
+    if (arguments) py_arg = Py_BuildValue ((char *)"(i,O)", arg, arguments);
+    else py_arg = Py_BuildValue ((char *)"(i)", arg);
 
     PyObject * val = make_call (py_arg);
     Py_XDECREF (val);
@@ -93,7 +93,7 @@
     
     // get name of callback function
     if (function) {
-	PyObject *p_name = PyObject_GetAttrString (function, "__name__");
+	PyObject *p_name = PyObject_GetAttrString (function, (char *)"__name__");
     	if (PyString_Check (p_name)) name = PyString_AsString (p_name);
     	else fprintf (stderr, "*** error: py_callback::put_state: Failed to retrieve callback name!");
      
