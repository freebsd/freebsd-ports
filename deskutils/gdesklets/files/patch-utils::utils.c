--- utils/utils.c.orig	Thu Dec 16 19:02:08 2004
+++ utils/utils.c	Thu Feb 17 21:28:55 2005
@@ -12,14 +12,14 @@
 
   if(G_UNLIKELY(PyGObject_Type == NULL))
     {
-      PyObject *module;
+      PyObject *module, *moddict;
 
       module = PyImport_ImportModule("gobject");
 
       if(!module)
 	goto err_gobject;
 
-      PyObject *moddict = PyModule_GetDict(module);
+      moddict = PyModule_GetDict(module);
 
       PyGObject_Type = (PyTypeObject *) PyDict_GetItemString(moddict, "GObject");
 
