$FreeBSD$

*** /tmp/paxtkinter.c210O-r	Tue Sep 16 18:14:21 2003
--- Pax/paxtkinter.c	Tue Sep 16 18:14:21 2003
***************
*** 1755,1760 ****
--- 1755,1774 ----
  }
  #endif
  
+ /* Yet another sketch specific hack: Starting with Python 2.3 Tkinter
+  * calls the wantobjects method, so we provide one that doesn't do
+  * anything.
+  */
+ static PyObject *
+ Tkapp_WantObjects(PyObject *self, PyObject *args)
+ {
+     int wantobjects;
+     if (!PyArg_ParseTuple(args, "i:wantobjects", &wantobjects))
+ 	return NULL;
+     
+     Py_INCREF(Py_None);
+     return Py_None;
+ }
  
  
  /**** Tkapp Method List ****/
***************
*** 1797,1802 ****
--- 1811,1817 ----
  	{"interpaddr",         Tkapp_InterpAddr, 1},
  	{"utf8_to_latin1",     Tkapp_UTF8_to_Latin1, 1},
  	{"utf8_to_system",     Tkapp_UTF8_to_System, 1},
+ 	{"wantobjects",	       Tkapp_WantObjects, METH_VARARGS},
  	{NULL, 		       NULL}
  };
  
