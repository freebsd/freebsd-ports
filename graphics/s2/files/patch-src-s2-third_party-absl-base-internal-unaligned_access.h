--- src/s2/third_party/absl/base/internal/unaligned_access.h.orig	2020-11-11 19:42:32 UTC
+++ src/s2/third_party/absl/base/internal/unaligned_access.h
@@ -286,8 +286,8 @@ inline uint32_t UnalignedLoad32(const void *p) {
   return t;
 }
 
-inline uint64 UnalignedLoad64(const void *p) {
-  uint64 t;
+inline uint64_t UnalignedLoad64(const void *p) {
+  uint64_t t;
   memcpy(&t, p, sizeof t);
   return t;
 }
@@ -296,7 +296,7 @@ inline void UnalignedStore16(void *p, uint16_t v) { me
 
 inline void UnalignedStore32(void *p, uint32_t v) { memcpy(p, &v, sizeof v); }
 
-inline void UnalignedStore64(void *p, uint64 v) { memcpy(p, &v, sizeof v); }
+inline void UnalignedStore64(void *p, uint64_t v) { memcpy(p, &v, sizeof v); }
 
 }  // namespace base_internal
 }  // namespace absl
