--- src/libbsdl/include/BSDL/tools.h.orig   2026-09-08 02:29:49 UTC
+++ src/libbsdl/include/BSDL/tools.h
@@ -10,6 +10,16 @@
 
 #include <tuple>
 
+/*
+ * FreeBSD's <sys/param.h> defines MAX/MIN macros, which collide with
+ * the BSDL template helpers below.
+ */
+#ifdef MAX
+#undef MAX
+#endif
+#ifdef MIN
+#undef MIN
+#endif
 BSDL_ENTER_NAMESPACE
 
 BSDL_INLINE float
