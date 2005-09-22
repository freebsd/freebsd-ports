--- jmorecfg.h.orig	Sun Sep 18 14:53:48 2005
+++ jmorecfg.h	Sun Sep 18 14:54:27 2005
@@ -187,8 +187,11 @@
 /* a function referenced thru EXTERNs: */
 #define GLOBAL(type)		type
 /* a reference to a GLOBAL function: */
+#ifdef __cplusplus
+#define EXTERN(type)		extern "C" type
+#else
 #define EXTERN(type)		extern type
-
+#endif
 
 /* This macro is used to declare a "method", that is, a function pointer.
  * We want to supply prototype parameters if the compiler can cope.
