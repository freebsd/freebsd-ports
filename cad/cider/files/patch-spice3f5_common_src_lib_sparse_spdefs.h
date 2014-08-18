--- spice3f5/common/src/lib/sparse/spdefs.h.orig	1994-01-29 19:08:43 UTC
+++ spice3f5/common/src/lib/sparse/spdefs.h
@@ -132,8 +132,10 @@
 
 /* Macro commands */
 /* Macro functions that return the maximum or minimum independent of type. */
+#if !(defined(BSD) && (BSD >= 199306))
 #define  MAX(a,b)           ((a) > (b) ? (a) : (b))
 #define  MIN(a,b)           ((a) < (b) ? (a) : (b))
+#endif
 
 /* Macro function that returns the absolute value of a floating point number. */
 #define  ABS(a)             ((a) < 0 ? -(a) : (a))
