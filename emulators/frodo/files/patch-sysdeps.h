--- sysdeps.h.orig	Wed Jan  2 22:15:27 2002
+++ sysdeps.h	Fri Sep  5 21:24:44 2003
@@ -25,7 +25,9 @@
 #endif
 
 #ifdef HAVE_VALUES_H
+#if !defined(__FreeBSD__)
 #include <values.h>
+#endif
 #endif
 
 #ifdef HAVE_STRINGS_H
