Index: qemu/tcg/i386/tcg-target.c
@@ -360,22 +360,22 @@
     case TCG_COND_LT:
         tcg_out_brcond(s, TCG_COND_LT, args[1], args[3], const_args[3], args[5]);
         tcg_out_jxx(s, JCC_JNE, label_next);
-        tcg_out_brcond(s, TCG_COND_LT, args[0], args[2], const_args[2], args[5]);
+        tcg_out_brcond(s, TCG_COND_LTU, args[0], args[2], const_args[2], args[5]);
         break;
     case TCG_COND_LE:
         tcg_out_brcond(s, TCG_COND_LT, args[1], args[3], const_args[3], args[5]);
         tcg_out_jxx(s, JCC_JNE, label_next);
-        tcg_out_brcond(s, TCG_COND_LE, args[0], args[2], const_args[2], args[5]);
+        tcg_out_brcond(s, TCG_COND_LEU, args[0], args[2], const_args[2], args[5]);
         break;
     case TCG_COND_GT:
         tcg_out_brcond(s, TCG_COND_GT, args[1], args[3], const_args[3], args[5]);
         tcg_out_jxx(s, JCC_JNE, label_next);
-        tcg_out_brcond(s, TCG_COND_GT, args[0], args[2], const_args[2], args[5]);
+        tcg_out_brcond(s, TCG_COND_GTU, args[0], args[2], const_args[2], args[5]);
         break;
     case TCG_COND_GE:
         tcg_out_brcond(s, TCG_COND_GT, args[1], args[3], const_args[3], args[5]);
         tcg_out_jxx(s, JCC_JNE, label_next);
-        tcg_out_brcond(s, TCG_COND_GE, args[0], args[2], const_args[2], args[5]);
+        tcg_out_brcond(s, TCG_COND_GEU, args[0], args[2], const_args[2], args[5]);
         break;
     case TCG_COND_LTU:
         tcg_out_brcond(s, TCG_COND_LTU, args[1], args[3], const_args[3], args[5]);
