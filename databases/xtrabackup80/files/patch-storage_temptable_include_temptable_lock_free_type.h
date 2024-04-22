--- storage/temptable/include/temptable/lock_free_type.h.orig	2020-06-16 16:31:03 UTC
+++ storage/temptable/include/temptable/lock_free_type.h
@@ -31,6 +31,14 @@ Lock-free type (selection) implementation. */
 
 #include "storage/temptable/include/temptable/constants.h"
 
+#if defined(__i386__) //&& defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8)
+/* Fix for clang setting __GCC_ATOMIC_LLONG_LOCK_FREE incorrectly for x86
+ * https://llvm.org/bugs/show_bug.cgi?id=19355
+ */
+#undef ATOMIC_LLONG_LOCK_FREE
+#define ATOMIC_LLONG_LOCK_FREE 2
+#endif
+
 namespace temptable {
 
 /** Enum class describing alignment-requirements. */
