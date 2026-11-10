-- On FreeBSD, pthread_t is a pointer (pthread *), so static_cast to uintptr_t
-- is not allowed. Use reinterpret_cast instead, which works for both pointer
-- and integer pthread_t representations.
--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_ref.h.orig	2026-11-10 12:33:38 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_ref.h
@@ -48,17 +48,10 @@

   bool is_null() const { return id_ == 0; }

-#if PA_BUILDFLAG(IS_APPLE)
   template <typename Hasher>
   size_t hash_value() const {
     return Hasher()(reinterpret_cast<uintptr_t>(id_));
   }
-#else
-  template <typename Hasher>
-  size_t hash_value() const {
-    return Hasher()(static_cast<uintptr_t>(id_));
-  }
-#endif

  private:
   RefType id_ = 0;
