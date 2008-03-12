Index: qemu/tcg/tcg-op.h
@@ -1172,7 +1172,7 @@
     tcg_gen_op3i(INDEX_op_qemu_ld8s, ret, addr, mem_index);
 #else
     tcg_gen_op4i(INDEX_op_qemu_ld8s, ret, addr, TCGV_HIGH(addr), mem_index);
-    tcg_gen_ext8s_i32(TCGV_HIGH(ret), ret);
+    tcg_gen_sari_i32(TCGV_HIGH(ret), ret, 31);
 #endif
 }
 
@@ -1192,7 +1192,7 @@
     tcg_gen_op3i(INDEX_op_qemu_ld16s, ret, addr, mem_index);
 #else
     tcg_gen_op4i(INDEX_op_qemu_ld16s, ret, addr, TCGV_HIGH(addr), mem_index);
-    tcg_gen_ext16s_i32(TCGV_HIGH(ret), ret);
+    tcg_gen_sari_i32(TCGV_HIGH(ret), ret, 31);
 #endif
 }
 
