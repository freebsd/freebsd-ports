--- sunpy/io/src/ana/_pyana.c.orig	2025-07-01 07:29:54 UTC
+++ sunpy/io/src/ana/_pyana.c
@@ -6,11 +6,6 @@ a cleaned up version of the original anarw routines.
 a cleaned up version of the original anarw routines.
 */
 
-// Needed due to https://github.com/numpy/numpy/issues/16970
-struct _typeobject {
-  int foo;
-};
-
 #include <Python.h>				// For python extension
 #define NPY_NO_DEPRECATED_API NPY_2_0_API_VERSION
 #include <numpy/arrayobject.h> 	// For numpy
