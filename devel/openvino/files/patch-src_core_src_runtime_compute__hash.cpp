--- src/core/src/runtime/compute_hash.cpp.orig	2026-02-14 21:07:41 UTC
+++ src/core/src/runtime/compute_hash.cpp
@@ -349,7 +349,7 @@ void ComputeHash<isa>::initialize(const Vmm& v_dst) {
     mov(r64_k_ptr, ptr[r64_params + GET_OFF(k_ptr)]);
     mov(r64_work_amount, ptr[r64_params + GET_OFF(work_amount)]);
 
-    uni_vbroadcasti64x2(v_k_2_3, ptr[r64_k_ptr + K_2_3_OFF]);
+    uni_vbroadcasti64x2(v_k_2_3, ptr[r64_k_ptr + static_cast<size_t>(K_2_3_OFF)]);
 
     mov(r64_aux, reinterpret_cast<uintptr_t>(SHUF_MASK));
     uni_vbroadcasti64x2(v_shuf_mask, ptr[r64_aux]);
