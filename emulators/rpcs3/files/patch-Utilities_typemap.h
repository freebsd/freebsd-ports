Workaround for https://bugs.llvm.org/show_bug.cgi?id=39246

--- Utilities/typemap.h.orig	2018-11-09 13:19:59 UTC
+++ Utilities/typemap.h
@@ -196,7 +196,11 @@ namespace utils
 
 	// Type information for each used type
 	template <typename T>
+#if defined(__clang__) && (__clang_major__ > 6 || (__clang_major__ == 6 && __clang_patchlevel__ > 0))
+	const typeinfo<T> g_typeinfo{};
+#else
 	inline const typeinfo<T> g_typeinfo{};
+#endif
 
 	template <typename T, typename B>
 	struct typepoly
