--- libdb/compat.h.orig	Thu Jun  5 04:36:52 2003
+++ libdb/compat.h	Wed Jun 18 22:02:55 2003
@@ -91,7 +91,7 @@
 #define	bcopy(a, b, n)		memmove(b, a, n)
 #endif
 
-#if defined(BSD) || defined(BSD4_3)
+#if 0
 #define	strchr(a, b)		index(a, b)
 #define	strrchr(a, b)		rindex(a, b)
 #define	memcmp(a, b, n)		bcmp(a, b, n)
