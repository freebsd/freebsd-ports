--- tools/sfio/sfhdr.h.orig	Thu Apr 26 21:17:42 2001
+++ tools/sfio/sfhdr.h	Wed Nov  7 17:58:52 2001
@@ -230,7 +230,9 @@
 #endif
 
 #if _hdr_values
+#ifndef __STDC__
 #include	<values.h>
+#endif
 #if !defined(SF_MAXDOUBLE) && defined(MAXDOUBLE)
 #define SF_MAXDOUBLE	MAXDOUBLE
 #endif
