--- src/hotspot/os_cpu/bsd_aarch64/atomic_bsd_aarch64.hpp
+++ src/hotspot/os_cpu/bsd_aarch64/atomic_bsd_aarch64.hpp
@@ -184,9 +184,14 @@ inline D Atomic::PlatformAdd<4>::fetch_and_add(D volatile* dest, I add_value,
                                                atomic_memory_order order) const {
   STATIC_ASSERT(4 == sizeof(I));
   STATIC_ASSERT(4 == sizeof(D));
-  D old_value
-    = atomic_fastcall(aarch64_atomic_fetch_add_4_impl, dest, add_value);
-  return old_value;
+  aarch64_atomic_stub_t stub;
+  switch (order) {
+  case memory_order_relaxed:
+    stub = aarch64_atomic_fetch_add_4_relaxed_impl; break;
+  default:
+    stub = aarch64_atomic_fetch_add_4_impl; break;
+  }
+  return atomic_fastcall(stub, dest, add_value);
 }
 
 template<>
@@ -195,9 +200,14 @@ inline D Atomic::PlatformAdd<8>::fetch_and_add(D volatile* dest, I add_value,
                                                atomic_memory_order order) const {
   STATIC_ASSERT(8 == sizeof(I));
   STATIC_ASSERT(8 == sizeof(D));
-  D old_value
-    = atomic_fastcall(aarch64_atomic_fetch_add_8_impl, dest, add_value);
-  return old_value;
+  aarch64_atomic_stub_t stub;
+  switch (order) {
+  case memory_order_relaxed:
+    stub = aarch64_atomic_fetch_add_8_relaxed_impl; break;
+  default:
+    stub = aarch64_atomic_fetch_add_8_impl; break;
+  }
+  return atomic_fastcall(stub, dest, add_value);
 }
 
 template<>
