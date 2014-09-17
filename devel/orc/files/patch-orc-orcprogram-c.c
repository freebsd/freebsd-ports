# This works around a fatal error in qemu-bsd-user dealing with floats in a
# very complex way.  This is arguably a bug in this code too, but for now
# patch around it so that we can get ports building via qemu-bsd-user and
# get more testing.  sbruno 16SEP2014
--- orc/orcprogram-c.c.orig
+++ orc/orcprogram-c.c
@@ -823,7 +823,7 @@ c_rule_loadpX (OrcCompiler *p, void *use
       ORC_ASM_CODE(p,"    %s = (int)0x%08x; /* %d or %gf */\n", dest,
           (unsigned int)p->vars[insn->src_args[0]].value.i,
           (int)p->vars[insn->src_args[0]].value.i,
-          p->vars[insn->src_args[0]].value.f);
+          p->vars[insn->src_args[0]].value.x2f[0]);
     } else {
       ORC_ASM_CODE(p,"    %s = ORC_UINT64_C(0x%08x%08x); /* %gf */\n", dest,
           (orc_uint32)(((orc_uint64)p->vars[insn->src_args[0]].value.i)>>32),
