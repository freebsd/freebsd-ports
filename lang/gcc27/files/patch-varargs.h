--- ginclude/varargs.h.orig	Sun Aug 13 15:18:55 1995
+++ ginclude/varargs.h	Mon Mar 20 13:29:13 2000
@@ -78,12 +78,22 @@
 
 #ifndef __GNUC_VA_LIST
 #define __GNUC_VA_LIST
+#if defined (__FreeBSD__)
+/* This is the correct way to handle all BSD NET2 and BSD 4.4 systems.  */
+#include <machine/ansi.h>
+#ifdef _BSD_VA_LIST_
+typedef _BSD_VA_LIST_ __gnuc_va_list;
+#else
+typedef _VA_LIST_ __gnuc_va_list;
+#endif
+#else
 #if defined(__svr4__) || defined(_AIX) || defined(_M_UNIX)
 typedef char *__gnuc_va_list;
 #else
 typedef void *__gnuc_va_list;
 #endif
 #endif
+#endif
 
 #define va_start(AP)  AP=(char *) &__builtin_va_alist
 
@@ -185,6 +195,11 @@
 
 /* The next BSD release (if there is one) wants this symbol to be
    undefined instead of _VA_LIST_.  */
+#if 0
+/* BSD 4.4 actually spells the name _BSD_VA_LIST_ and requires it to be
+ * defined and usable in place of va_list when the latter name is not
+ * allowed (e.g., in stdio.h - see ginclude/stdarg.h).  */
 #ifdef _BSD_VA_LIST
 #undef _BSD_VA_LIST
+#endif
 #endif
