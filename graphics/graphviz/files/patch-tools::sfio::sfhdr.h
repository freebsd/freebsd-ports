--- tools/sfio/sfhdr.h.orig	Fri Apr 27 04:17:42 2001
+++ tools/sfio/sfhdr.h	Tue Feb 18 19:26:37 2003
@@ -122,6 +122,10 @@
 #include	<errno.h>
 #include	<ctype.h>
 
+#ifndef va_copy
+#define va_copy(to,fr) ((to)=(fr))
+#endif
+
 #if vt_threaded
 
 /* initialization */
@@ -230,7 +234,9 @@
 #endif
 
 #if _hdr_values
+#ifdef HAVE_VALUES_H
 #include	<values.h>
+#endif
 #if !defined(SF_MAXDOUBLE) && defined(MAXDOUBLE)
 #define SF_MAXDOUBLE	MAXDOUBLE
 #endif
