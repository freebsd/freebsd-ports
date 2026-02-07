This patch works around a bug in the armv7 libc where sprintf(buf, "%g", 1.26e-321);
generates a string with an embedded NUL byte, causing broken source code to be
generated (PR272229).

--- orc/orcprogram-c.c.orig	2023-06-26 19:40:12 UTC
+++ orc/orcprogram-c.c
@@ -825,10 +825,9 @@ c_rule_loadpX (OrcCompiler *p, void *user, OrcInstruct
     }
   } else if (p->vars[insn->src_args[0]].vartype == ORC_VAR_TYPE_CONST) {
     if (p->vars[insn->src_args[0]].size <= 4) {
-      ORC_ASM_CODE(p,"    %s = 0x%08x; /* %d or %gf */\n", dest,
+      ORC_ASM_CODE(p,"    %s = 0x%08x; /* %d */\n", dest,
           (unsigned int)p->vars[insn->src_args[0]].value.i,
-          (int)p->vars[insn->src_args[0]].value.i,
-          p->vars[insn->src_args[0]].value.f);
+          (int)p->vars[insn->src_args[0]].value.i);
     } else {
       ORC_ASM_CODE(p,"    %s = ORC_UINT64_C(0x%08x%08x); /* %gf */\n", dest,
           (orc_uint32)(((orc_uint64)p->vars[insn->src_args[0]].value.i)>>32),
