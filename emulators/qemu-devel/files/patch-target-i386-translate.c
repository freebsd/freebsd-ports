Index: qemu/target-i386/translate.c
@@ -3330,8 +3330,12 @@
             op1_offset = offsetof(CPUX86State,xmm_regs[reg]);
             tcg_gen_addi_ptr(cpu_ptr0, cpu_env, op1_offset);
             sse_op2 = sse_op_table3[(s->dflag == 2) * 2 + ((b >> 8) - 2)];
-            tcg_gen_trunc_tl_i32(cpu_tmp2_i32, cpu_T[0]);
-            tcg_gen_helper_0_2(sse_op2, cpu_ptr0, cpu_tmp2_i32);
+            if (ot == OT_LONG) {
+                tcg_gen_trunc_tl_i32(cpu_tmp2_i32, cpu_T[0]);
+                tcg_gen_helper_0_2(sse_op2, cpu_ptr0, cpu_tmp2_i32);
+            } else {
+                tcg_gen_helper_0_2(sse_op2, cpu_ptr0, cpu_T[0]);
+            }
             break;
         case 0x02c: /* cvttps2pi */
         case 0x12c: /* cvttpd2pi */
