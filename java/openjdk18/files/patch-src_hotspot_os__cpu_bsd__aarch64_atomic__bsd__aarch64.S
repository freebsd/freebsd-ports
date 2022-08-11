--- src/hotspot/os_cpu/bsd_aarch64/atomic_bsd_aarch64.S
+++ src/hotspot/os_cpu/bsd_aarch64/atomic_bsd_aarch64.S
@@ -47,6 +47,28 @@ aarch64_atomic_fetch_add_4_default_impl:
         mov     w0, w2
         ret
 
+        .global aarch64_atomic_fetch_add_8_relaxed_default_impl
+        .align 5
+aarch64_atomic_fetch_add_8_relaxed_default_impl:
+        prfm    pstl1strm, [x0]
+0:      ldxr    x2, [x0]
+        add     x8, x2, x1
+        stxr    w9, x8, [x0]
+        cbnz    w9, 0b
+        mov     x0, x2
+        ret
+
+        .global aarch64_atomic_fetch_add_4_relaxed_default_impl
+        .align 5
+aarch64_atomic_fetch_add_4_relaxed_default_impl:
+        prfm    pstl1strm, [x0]
+0:      ldxr    w2, [x0]
+        add     w8, w2, w1
+        stxr    w9, w8, [x0]
+        cbnz    w9, 0b
+        mov     w0, w2
+        ret
+
         .globl aarch64_atomic_xchg_4_default_impl
         .align 5
 aarch64_atomic_xchg_4_default_impl:
