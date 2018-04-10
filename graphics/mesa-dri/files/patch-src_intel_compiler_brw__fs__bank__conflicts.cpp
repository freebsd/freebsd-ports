compiler/brw_fs_bank_conflicts.cpp:719:25: error: scalar initializer cannot be empty
      vector_type s_p = {}, s_n = {};
                        ^~
compiler/brw_fs_bank_conflicts.cpp:719:35: error: scalar initializer cannot be empty
      vector_type s_p = {}, s_n = {};
                                  ^~

--- src/intel/compiler/brw_fs_bank_conflicts.cpp.orig	2018-01-23 18:08:50 UTC
+++ src/intel/compiler/brw_fs_bank_conflicts.cpp
@@ -716,7 +716,7 @@ namespace {
                    const weight_vector_type &conflicts)
    {
       const unsigned m = DIV_ROUND_UP(conflicts.size, vector_width);
-      vector_type s_p = {}, s_n = {};
+      vector_type s_p = {0}, s_n = {0};
 
       for (unsigned r = 0; r < m; r++) {
          s_p = adds(s_p, mask(bank_mask_p.v[r], conflicts.v[r]));
