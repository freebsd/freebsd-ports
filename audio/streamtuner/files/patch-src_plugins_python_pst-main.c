--- src/plugins/python/pst-main.c.orig	Thu Mar 24 15:52:58 2005
+++ src/plugins/python/pst-main.c	Thu Mar 24 15:53:59 2005
@@ -94,6 +94,7 @@
 {
   gboolean status = FALSE;
   PyObject *module;
+  char *argv[] = { "" };
 
   if (! check_api_version(err))
     return FALSE;
@@ -109,6 +110,7 @@
     }
 
   Py_Initialize();
+  PySys_SetArgv(G_N_ELEMENTS(argv), argv);
   PyEval_InitThreads();
 
   module = PyImport_AddModule("__main__");
