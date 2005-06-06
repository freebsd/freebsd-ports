===================================================================
RCS file: /cvsroot/incrtcl/incrTcl/itcl/generic/itcl.h,v
retrieving revision 1.15
retrieving revision 1.19
diff -u -r1.15 -r1.19
--- generic/itcl.h	2001/05/25 00:12:29	1.15
+++ generic/itcl.h	2002/01/16 22:29:41	1.19
@@ -40,9 +40,9 @@
  *           http://www.tcltk.com/itcl
  *
  *       modified for Stubs 5/20/1999 by 
- *           David Gravereaux <davygrvy@bigfoot.com>
+ *           David Gravereaux <davygrvy@pobox.com>
  *
- *     RCS:  $Id: itcl.h,v 1.15 2001/05/25 00:12:29 davygrvy Exp $
+ *     RCS:  $Id: itcl.h,v 1.19 2002/01/16 22:29:41 andreas_kupries Exp $
  * ========================================================================
  *           Copyright (c) 1993-1998  Lucent Technologies, Inc.
  * ------------------------------------------------------------------------
@@ -54,17 +54,6 @@
 
 #include "tcl.h"
 
-#undef TCL_STORAGE_CLASS
-#ifdef BUILD_itcl
-# define TCL_STORAGE_CLASS DLLEXPORT
-#else
-# ifdef USE_ITCL_STUBS
-#  define TCL_STORAGE_CLASS
-# else
-#  define TCL_STORAGE_CLASS DLLIMPORT
-# endif
-#endif
-
 #define ITCL_VERSION "3.2"
 #define ITCL_PATCH_LEVEL "3.2.1"
 #define ITCL_MAJOR_VERSION 3
@@ -80,6 +69,58 @@
 
 #ifndef RC_INVOKED
 
+#undef TCL_STORAGE_CLASS
+#ifdef BUILD_itcl
+#   define TCL_STORAGE_CLASS DLLEXPORT
+#else
+#   ifdef USE_ITCL_STUBS
+#	define TCL_STORAGE_CLASS
+#   else
+#	define TCL_STORAGE_CLASS DLLIMPORT
+#   endif
+#endif
+
+/*
+ * Fix the Borland bug that's in the EXTERN macro from tcl.h.
+ */
+#ifndef TCL_EXTERN
+#   undef DLLIMPORT
+#   undef DLLEXPORT
+#   if defined(STATIC_BUILD)
+#	define DLLIMPORT
+#	define DLLEXPORT
+#   elif (defined(__WIN32__) && (defined(_MSC_VER) || (__BORLANDC__ >= 0x0550) || (defined(__GNUC__) && defined(__declspec)))) \
+	    || (defined(MAC_TCL) && FUNCTION_DECLSPEC)
+#	define DLLIMPORT __declspec(dllimport)
+#	define DLLEXPORT __declspec(dllexport)
+#   elif defined(__BORLANDC__)
+#	define OLDBORLAND 1
+#	define DLLIMPORT __import
+#	define DLLEXPORT __export
+#   else
+#	define DLLIMPORT
+#	define DLLEXPORT
+#   endif
+
+    /*
+     * Make sure name mangling won't happen when the c++ language extensions
+     * are used.
+     */
+#   ifdef __cplusplus
+#	define TCL_CPP "C"
+#   else
+#	define TCL_CPP
+#   endif
+    /*
+     * Borland requires the attributes be placed after the return type.
+     */
+#   ifdef OLDBORLAND
+#	define TCL_EXTERN(rtnType) extern TCL_CPP rtnType TCL_STORAGE_CLASS
+#   else
+#	define TCL_EXTERN(rtnType) extern TCL_CPP TCL_STORAGE_CLASS rtnType
+#   endif
+#endif
+
 /*
  * Protection levels:
  *
@@ -152,9 +193,7 @@
 
 #ifdef USE_ITCL_STUBS
 
-#ifdef __cplusplus
-extern "C"
-#endif
+extern TCL_CPP
 CONST char *	Itcl_InitStubs _ANSI_ARGS_((Tcl_Interp *interp,
 			    char *version, int exact));
 #else
