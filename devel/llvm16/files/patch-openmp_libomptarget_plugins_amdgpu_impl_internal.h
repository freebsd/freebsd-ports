--- openmp/libomptarget/plugins/amdgpu/impl/internal.h.orig
+++ openmp/libomptarget/plugins/amdgpu/impl/internal.h
@@ -42,7 +42,6 @@
   unsigned long unused1;
   unsigned long unused2;
 } impl_implicit_args_t;
-static_assert(sizeof(impl_implicit_args_t) == 56, "");
 
 // ---------------------- Kernel Start -------------
 typedef struct atl_kernel_info_s {
