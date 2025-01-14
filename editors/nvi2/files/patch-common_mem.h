--- common/mem.h.orig	2023-09-25 08:47:42 UTC
+++ common/mem.h
@@ -212,6 +212,18 @@ p2roundup(size_t n)
 	return (n);
 }
 
+/*
+ * is_aligned --
+ *      Determine whether the program can safely read an object with an
+ *      alignment requirement from ptr.
+ *
+ * See also: https://clang.llvm.org/docs/LanguageExtensions.html#alignment-builtins
+ */
+static __inline int
+is_aligned(void *ptr, size_t alignment) {
+	return ((uintptr_t)ptr % alignment) == 0;
+}
+
 /* Additional TAILQ helper. */
 #define TAILQ_ENTRY_ISVALID(elm, field)					\
 	((elm)->field.tqe_prev != NULL)
