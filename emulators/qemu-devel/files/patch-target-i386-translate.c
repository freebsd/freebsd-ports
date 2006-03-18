# 1.53
Index: qemu/target-i386/translate.c
@@ -5803,14 +5803,24 @@
         op = (modrm >> 3) & 7;
         switch(op) {
         case 0: /* fxsave */
-            if (mod == 3 || !(s->cpuid_features & CPUID_FXSR))
+            if (mod == 3 || !(s->cpuid_features & CPUID_FXSR) || 
+                (s->flags & HF_EM_MASK))
                 goto illegal_op;
+            if (s->flags & HF_TS_MASK) {
+                gen_exception(s, EXCP07_PREX, pc_start - s->cs_base);
+                break;
+            }
             gen_lea_modrm(s, modrm, &reg_addr, &offset_addr);
             gen_op_fxsave_A0((s->dflag == 2));
             break;
         case 1: /* fxrstor */
-            if (mod == 3 || !(s->cpuid_features & CPUID_FXSR))
+            if (mod == 3 || !(s->cpuid_features & CPUID_FXSR) || 
+                (s->flags & HF_EM_MASK))
                 goto illegal_op;
+            if (s->flags & HF_TS_MASK) {
+                gen_exception(s, EXCP07_PREX, pc_start - s->cs_base);
+                break;
+            }
             gen_lea_modrm(s, modrm, &reg_addr, &offset_addr);
             gen_op_fxrstor_A0((s->dflag == 2));
             break;
