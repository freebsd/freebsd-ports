--- clutter/cluttermodule.c.orig	2010-02-15 11:16:18.000000000 +0100
+++ clutter/cluttermodule.c	2010-02-15 11:18:06.000000000 +0100
@@ -148,19 +148,19 @@ pycogl_add_gl_constants (PyObject *modul
    * should also be loading PyOpenGL, which exposes all the
    * enumeration values
    */
-  PyModule_AddObject (module, "NEVER", Py_BuildValue ("i", CGL_NEVER));
-  PyModule_AddObject (module, "LESS", Py_BuildValue ("i", CGL_LESS));
-  PyModule_AddObject (module, "LEQUAL", Py_BuildValue ("i", CGL_LEQUAL));
-  PyModule_AddObject (module, "EQUAL", Py_BuildValue ("i", CGL_EQUAL));
-  PyModule_AddObject (module, "NOTEQUAL", Py_BuildValue ("i", CGL_NOTEQUAL));
-  PyModule_AddObject (module, "GEQUAL", Py_BuildValue ("i", CGL_GEQUAL));
-  PyModule_AddObject (module, "GREATER", Py_BuildValue ("i", CGL_GREATER));
-  PyModule_AddObject (module, "ALWAYS", Py_BuildValue ("i", CGL_ALWAYS));
+  PyModule_AddObject (module, "NEVER", Py_BuildValue ("i", GL_NEVER));
+  PyModule_AddObject (module, "LESS", Py_BuildValue ("i", GL_LESS));
+  PyModule_AddObject (module, "LEQUAL", Py_BuildValue ("i", GL_LEQUAL));
+  PyModule_AddObject (module, "EQUAL", Py_BuildValue ("i", GL_EQUAL));
+  PyModule_AddObject (module, "NOTEQUAL", Py_BuildValue ("i", GL_NOTEQUAL));
+  PyModule_AddObject (module, "GEQUAL", Py_BuildValue ("i", GL_GEQUAL));
+  PyModule_AddObject (module, "GREATER", Py_BuildValue ("i", GL_GREATER));
+  PyModule_AddObject (module, "ALWAYS", Py_BuildValue ("i", GL_ALWAYS));
 
-  PyModule_AddObject (module, "SRC_ALPHA", Py_BuildValue ("i", CGL_SRC_ALPHA));
-  PyModule_AddObject (module, "ONE_MINUS_SRC_ALPHA", Py_BuildValue ("i", CGL_ONE_MINUS_SRC_ALPHA));
+  PyModule_AddObject (module, "SRC_ALPHA", Py_BuildValue ("i", GL_SRC_ALPHA));
+  PyModule_AddObject (module, "ONE_MINUS_SRC_ALPHA", Py_BuildValue ("i", GL_ONE_MINUS_SRC_ALPHA));
 
-  PyModule_AddObject (module, "OBJECT_COMPILE_STATUS", Py_BuildValue ("i", CGL_OBJECT_COMPILE_STATUS));
+  PyModule_AddObject (module, "OBJECT_COMPILE_STATUS", Py_BuildValue ("i", GL_OBJECT_COMPILE_STATUS_ARB));
 
   if (PyErr_Occurred ())
     PyErr_Print ();
