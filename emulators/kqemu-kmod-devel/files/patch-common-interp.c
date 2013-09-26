--- common/interp.c.orig
+++ common/interp.c
@@ -1870,11 +1870,11 @@ static void helper_wrmsr(struct kqemu_st
 {
 #ifdef __x86_64__
     struct kqemu_cpu_state *env = &s->cpu_state;
-#endif
     uint64_t val;
 
     val = ((uint32_t)s->regs1.eax) | 
         ((uint64_t)((uint32_t)s->regs1.edx) << 32);
+#endif
 
     switch((uint32_t)s->regs1.ecx) {
 #ifdef __x86_64__
