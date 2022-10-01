--- third_party/protobuf/src/google/protobuf/arena_impl.h.orig	2022-09-25 04:12:11 UTC
+++ third_party/protobuf/src/google/protobuf/arena_impl.h
@@ -640,7 +640,7 @@ class PROTOBUF_EXPORT ThreadSafeArena {
 #ifdef _MSC_VER
 #pragma warning(disable : 4324)
 #endif
-  struct alignas(kCacheAlignment) CacheAlignedLifecycleIdGenerator {
+  struct alignas(alignof(std::atomic<LifecycleIdAtomic>)) CacheAlignedLifecycleIdGenerator {
     std::atomic<LifecycleIdAtomic> id;
   };
   static CacheAlignedLifecycleIdGenerator lifecycle_id_generator_;
