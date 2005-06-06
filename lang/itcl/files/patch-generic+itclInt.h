===================================================================
RCS file: /cvsroot/incrtcl/incrTcl/itcl/generic/itclInt.h,v
retrieving revision 1.7
retrieving revision 1.11
diff -u -r1.7 -r1.11
--- generic/itclInt.h	2001/04/07 07:20:53	1.7
+++ generic/itclInt.h	2003/12/23 06:58:27	1.11
@@ -39,7 +39,7 @@
  *           mmclennan@lucent.com
  *           http://www.tcltk.com/itcl
  *
- *     RCS:  $Id: itclInt.h,v 1.7 2001/04/07 07:20:53 davygrvy Exp $
+ *     RCS:  $Id: itclInt.h,v 1.11 2003/12/23 06:58:27 davygrvy Exp $
  * ========================================================================
  *           Copyright (c) 1993-1998  Lucent Technologies, Inc.
  * ------------------------------------------------------------------------
@@ -49,14 +49,64 @@
 #ifndef ITCLINT_H
 #define ITCLINT_H
 
-#include "itcl.h"
 #include "tclInt.h"
+#include "itcl.h"
 
 #ifdef BUILD_itcl
 # undef TCL_STORAGE_CLASS
 # define TCL_STORAGE_CLASS DLLEXPORT
 #endif
 
+/*
+ * Fix Tcl bug #803489 the right way.  We need to always use the old Stub
+ * slot positions, not the new broken ones.  I do like that these functions
+ * have moved to the public space, but the slot change is the killer and is
+ * the painful side affect.
+ */
+
+#if defined(USE_TCL_STUBS) && \
+	(TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION >= 5)
+#   undef Tcl_CreateNamespace
+#   define Tcl_CreateNamespace \
+	(tclIntStubsPtr->tcl_CreateNamespace)
+#   undef Tcl_DeleteNamespace
+#   define Tcl_DeleteNamespace \
+	(tclIntStubsPtr->tcl_DeleteNamespace)
+#   undef Tcl_AppendExportList
+#   define Tcl_AppendExportList \
+	(tclIntStubsPtr->tcl_AppendExportList)
+#   undef Tcl_Export
+#   define Tcl_Export \
+	(tclIntStubsPtr->tcl_Export)
+#   undef Tcl_Import
+#   define Tcl_Import \
+	(tclIntStubsPtr->tcl_Import)
+#   undef Tcl_ForgetImport
+#   define Tcl_ForgetImport \
+	(tclIntStubsPtr->tcl_ForgetImport)
+#   undef Tcl_GetCurrentNamespace
+#   define Tcl_GetCurrentNamespace \
+	(tclIntStubsPtr->tcl_GetCurrentNamespace)
+#   undef Tcl_GetGlobalNamespace
+#   define Tcl_GetGlobalNamespace \
+	(tclIntStubsPtr->tcl_GetGlobalNamespace)
+#   undef Tcl_FindNamespace
+#   define Tcl_FindNamespace \
+	(tclIntStubsPtr->tcl_FindNamespace)
+#   undef Tcl_FindCommand
+#   define Tcl_FindCommand \
+	(tclIntStubsPtr->tcl_FindCommand)
+#   undef Tcl_GetCommandFromObj
+#   define Tcl_GetCommandFromObj \
+	(tclIntStubsPtr->tcl_GetCommandFromObj)
+#   undef Tcl_GetCommandFullName
+#   define Tcl_GetCommandFullName \
+	(tclIntStubsPtr->tcl_GetCommandFullName)
+#endif
+
+#define TCL_DOES_STUBS \
+    (TCL_MAJOR_VERSION > 8 || TCL_MAJOR_VERSION == 8 && (TCL_MINOR_VERSION > 1 || \
+    (TCL_MINOR_VERSION == 1 && TCL_RELEASE_LEVEL == TCL_FINAL_RELEASE)))
 
 /*
  *  Common info for managing all known objects.
@@ -255,15 +305,11 @@
  */
 
 #undef  assert
-#ifdef  NDEBUG
+#ifndef  DEBUG
 #define assert(EX) ((void)0)
 #else
-#if defined(__STDC__)
-#define assert(EX) (void)((EX) || (Itcl_Assert(#EX, __FILE__, __LINE__), 0))
-#else
-#define assert(EX) (void)((EX) || (Itcl_Assert("EX", __FILE__, __LINE__), 0))
-#endif  /* __STDC__ */
-#endif  /* NDEBUG */
+#define assert(EX) (void)((EX) || (Itcl_Assert(STRINGIFY(EX), __FILE__, __LINE__), 0))
+#endif  /* DEBUG */
 
 #undef TCL_STORAGE_CLASS
 #define TCL_STORAGE_CLASS DLLIMPORT
