--- base/threading/thread_local_storage_unittest.cc.orig	2019-09-10 10:42:27 UTC
+++ base/threading/thread_local_storage_unittest.cc
@@ -86,7 +86,7 @@ class ThreadLocalStorageRunner : public DelegateSimple
 void ThreadLocalStorageCleanup(void *value) {
   int *ptr = reinterpret_cast<int*>(value);
   // Destructors should never be called with a NULL.
-  ASSERT_NE(reinterpret_cast<int*>(NULL), ptr);
+  ASSERT_NE(static_cast<int*>(NULL), ptr);
   if (*ptr == kFinalTlsValue)
     return;  // We've been called enough times.
   ASSERT_LT(kFinalTlsValue, *ptr);
