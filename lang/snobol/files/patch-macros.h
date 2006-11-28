--- include/macros.h.orig	Fri Jul 25 14:52:56 1997
+++ include/macros.h	Tue Nov 28 00:26:54 2006
@@ -4,6 +4,8 @@
  * macros for data access and implementation of SIL ops
  */
 
+#include <strings.h>
+
 /* descriptor at address x */
 #define D(x)	(*(struct descr *)(x))
 
@@ -32,7 +34,7 @@
 #endif /* DCMP_BYTES not defined */
 
 /* clear B+1 descriptor block */
-#define ZERBLK(A,B) bzero(A, (B)+DESCR)
+#define ZERBLK(A,B) bzero((void *)A, (B)+DESCR)
 
 /*
  * copy descriptor block
@@ -40,7 +42,7 @@
  * NOTE: may overlap!!
  * (bcopy deals with this but some memcpy's do not)!!!
  */
-#define MOVBLK(A,B,C) bcopy( (B)+DESCR, (A)+DESCR, (C) )
+#define MOVBLK(A,B,C) bcopy( ((char *)B)+DESCR, ((char *)A)+DESCR, (C) )
 
 /****************
  * string specifiers (qualifiers)
