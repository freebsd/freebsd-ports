--- src/python-lz4.c.orig	2014-07-07 13:03:03 UTC
+++ src/python-lz4.c
@@ -202,6 +202,10 @@ void initlz4(void)
         INITERROR;
     }
 
+    PyModule_AddStringConstant(module, "VERSION", VERSION);
+    PyModule_AddStringConstant(module, "__version__", VERSION);
+    PyModule_AddStringConstant(module, "LZ4_VERSION", LZ4_VERSION);
+
 #if PY_MAJOR_VERSION >= 3
     return module;
 #endif
