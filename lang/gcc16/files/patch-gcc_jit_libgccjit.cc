--- gcc/jit/libgccjit.cc.orig	2025-09-19 17:04:52 UTC
+++ gcc/jit/libgccjit.cc
@@ -4405,7 +4405,7 @@ gcc_jit_context_new_rvalue_vector_perm (gcc_jit_contex
     mask_len == elements1_len,
     ctxt, loc,
     "mismatching length for mask:"
-    " elements1 length: %ld mask length: %ld",
+    " elements1 length: %zu mask length: %zu",
     mask_len,
     elements1_len);
 
@@ -4426,7 +4426,7 @@ gcc_jit_context_new_rvalue_vector_perm (gcc_jit_contex
     mask_element_size == elements1_element_size,
     ctxt, loc,
     "mismatching size for mask element type:"
-    " elements1 element type: %ld mask element type: %ld",
+    " elements1 element type: %zu mask element type: %zu",
     mask_element_size,
     elements1_element_size);
 
