--- opennurbs_system_runtime.h.orig	2026-06-25 07:56:15 UTC
+++ opennurbs_system_runtime.h
@@ -177,9 +177,16 @@
 /* Attempt to determing runtime pointer size */
 #if (defined(_M_X64) || defined(__LP64__) || defined(__ppc64__))
 #define ON_64BIT_RUNTIME
-#elif (defined(_M_X86) || defined(__LP32__))
+#elif (defined(_M_X86) || defined(__LP32__) || defined(__ILP32__))
 #define ON_32BIT_RUNTIME
 #endif
+#endif
+
+/* Attempt to determine byte order */
+#if defined(__BIG_ENDIAN__)
+#define ON_BIG_ENDIAN
+#elif defined(__LITTLE_ENDIAN__)
+#define ON_LITTLE_ENDIAN
 #endif
 
 #if defined(ON_64BIT_RUNTIME) && defined(ON_32BIT_RUNTIME)
