--- utils/utils.c.orig	Sun Feb  6 22:11:42 2005
+++ utils/utils.c	Mon Feb 28 12:15:54 2005
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
 
