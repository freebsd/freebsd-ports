--- ginclude/stdarg.h.orig	Tue Sep 12 09:50:36 1995
+++ ginclude/stdarg.h	Mon Mar 20 13:29:13 2000
@@ -43,6 +43,15 @@
 #else
 
 /* Define __gnuc_va_list.  */
+#if defined (__FreeBSD__)
+/* This is the correct way to handle all BSD NET2 and BSD 4.4 systems.  */
+#include <machine/ansi.h>
+#ifdef _BSD_VA_LIST_
+typedef _BSD_VA_LIST_ __gnuc_va_list;
+#else
+typedef _VA_LIST_ __gnuc_va_list;
+#endif
+#else
 
 #ifndef __GNUC_VA_LIST
 #define __GNUC_VA_LIST
@@ -52,6 +61,7 @@
 typedef void *__gnuc_va_list;
 #endif
 #endif
+#endif
 
 /* Define the standard macros for the user,
    if this invocation was from the user program.  */
@@ -116,8 +126,13 @@
 #undef _VA_LIST
 #endif
 
+#if 0
+/* BSD 4.4 actually spells the name _BSD_VA_LIST_ and requires it to be
+ * defined and usable in place of va_list when the latter name is not
+ * allowed (e.g., in stdio.h - see above).  */
 #ifdef _BSD_VA_LIST
 #undef _BSD_VA_LIST
+#endif
 #endif
 
 #ifdef __svr4__
