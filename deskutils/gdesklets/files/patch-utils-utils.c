--- utils/utils.c.orig	Wed Oct 20 16:46:10 2004
+++ utils/utils.c	Mon Nov 15 01:02:06 2004
@@ -12,14 +12,14 @@
 
   if(G_UNLIKELY(PyGObject_Type == NULL))
     {
-      PyObject *module, *modict;
+      PyObject *module, *modict, *moddict;
 
       module = PyImport_ImportModule("gobject");
 
       if(!module)
 	goto err_gobject;
 
-      PyObject *moddict = PyModule_GetDict(module);
+      moddict = PyModule_GetDict(module);
 
       PyGObject_Type = (PyTypeObject *) PyDict_GetItemString(moddict, "GObject");
 
