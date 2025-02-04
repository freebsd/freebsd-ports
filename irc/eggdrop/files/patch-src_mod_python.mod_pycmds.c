--- src/mod/python.mod/pycmds.c.orig	2025-02-04 15:24:41 UTC
+++ src/mod/python.mod/pycmds.c
@@ -22,7 +22,6 @@
 #define PY_SSIZE_T_CLEAN
 #include <Python.h>
 #include <datetime.h>
-#include <tcl.h>
 #include "src/mod/module.h"
 
 typedef struct {
