--- tools/sfio/sfhdr.h.orig	Thu Apr 18 10:28:45 2002
+++ tools/sfio/sfhdr.h	Thu Apr 18 10:29:17 2002
@@ -230,7 +230,9 @@
 #endif
 
 #if _hdr_values
+#ifdef HAVE_VALUES_H
 #include	<values.h>
+#endif
 #if !defined(SF_MAXDOUBLE) && defined(MAXDOUBLE)
 #define SF_MAXDOUBLE	MAXDOUBLE
 #endif
