--- jstypes.h.orig	Sat Nov 15 00:11:04 2003
+++ jstypes.h	Sat Jan 14 02:17:40 2006
@@ -203,6 +203,19 @@
 #define JS_BITMASK(n)   (JS_BIT(n) - 1)
 
 /***********************************************************************
+** MACROS:      JS_PTR_TO_INT32
+**              JS_PTR_TO_UINT32
+**              JS_INT32_TO_PTR
+**              JS_UINT32_TO_PTR
+** DESCRIPTION:
+** Integer to pointer and pointer to integer conversion macros.
+***********************************************************************/
+#define JS_PTR_TO_INT32(x)  ((jsint)((char *)(x) - (char *)0))
+#define JS_PTR_TO_UINT32(x) ((jsuint)((char *)(x) - (char *)0))
+#define JS_INT32_TO_PTR(x)  ((void *)((char *)0 + (jsint)(x)))
+#define JS_UINT32_TO_PTR(x) ((void *)((char *)0 + (jsuint)(x)))
+
+/***********************************************************************
 ** MACROS:      JS_HOWMANY
 **              JS_ROUNDUP
 **              JS_MIN
