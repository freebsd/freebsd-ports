--- include/cgen/basic-ops.h.orig	2013-03-07 17:31:21.000000000 +0100
+++ include/cgen/basic-ops.h	2013-03-07 17:31:28.000000000 +0100
@@ -24,11 +24,16 @@
 
 #include <assert.h>
 
-#if defined (__GNUC__) && ! defined (SEMOPS_DEFINE_INLINE)
+#if defined (__GNUC__) && ! defined (SEMOPS_DEFINE_INLINE) && ! defined (__clang__)
 #define SEMOPS_DEFINE_INLINE
 #define SEMOPS_INLINE extern inline
 #else
-#define SEMOPS_INLINE
+# if defined (__clang__) && ! defined (SEMOPS_DEFINE_INLINE)
+#  define SEMOPS_DEFINE_INLINE
+#  define SEMOPS_INLINE static inline
+# else
+#  define SEMOPS_INLINE
+# endif
 #endif
 
 /* These don't really have a mode.  */
@@ -295,11 +300,16 @@
    significant and word number 0 is the most significant word.
    ??? May also wish an endian-dependent version.  Later.  */
 
-QI SUBWORDSIQI (SI, int);
-HI SUBWORDSIHI (SI, int);
-QI SUBWORDDIQI (DI, int);
-HI SUBWORDDIHI (DI, int);
-SI SUBWORDDISI (DI, int);
+#if defined (__clang__) && defined (SEMOPS_DEFINE_INLINE)
+#define SEMOPS_STATIC static
+#else
+#define SEMOPS_STATIC
+#endif
+SEMOPS_STATIC QI SUBWORDSIQI (SI, int);
+SEMOPS_STATIC HI SUBWORDSIHI (SI, int);
+SEMOPS_STATIC QI SUBWORDDIQI (DI, int);
+SEMOPS_STATIC HI SUBWORDDIHI (DI, int);
+SEMOPS_STATIC SI SUBWORDDISI (DI, int);
 
 #ifdef SEMOPS_DEFINE_INLINE
 
