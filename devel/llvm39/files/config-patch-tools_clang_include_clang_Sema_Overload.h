--- tools/clang/include/clang/Sema/Overload.h.orig
+++ tools/clang/include/clang/Sema/Overload.h
@@ -586,7 +586,11 @@
     ovl_fail_enable_if,
 
     /// This candidate was not viable because its address could not be taken.
-    ovl_fail_addr_not_available
+    ovl_fail_addr_not_available,
+
+    /// This inherited constructor is not viable because it would slice the
+    /// argument.
+    ovl_fail_inhctor_slice,
   };
 
   /// OverloadCandidate - A single candidate in an overload set (C++ 13.3).
