-- Fix casting of zero-size numpy arrays to aligned Eigen::TensorMap.
-- The alignment check rejects empty arrays whose data pointer may be null or
-- unaligned, causing std::bad_cast in test_eigen_tensor.py::test06_zero_size_tensor.
-- Upstream issue/report: nanobind Eigen tensor support does not yet handle this case.

--- include/nanobind/eigen/tensor.h.orig	2026-09-22 19:28:53 UTC
+++ include/nanobind/eigen/tensor.h
@@ -106,7 +106,8 @@ struct type_caster<
 
         if (!caster.from_python(src, flags, cleanup))
             return false;
-        if(IsAligned && !is_tensor_aligned(caster.value.data()))
+        if(IsAligned && caster.value.size() != 0 &&
+                !is_tensor_aligned(caster.value.data()))
             return false;
 
         return true;
