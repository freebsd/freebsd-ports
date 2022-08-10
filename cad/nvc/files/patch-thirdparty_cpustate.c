--- thirdparty/cpustate.c.orig	2022-08-10 16:48:11 UTC
+++ thirdparty/cpustate.c
@@ -103,6 +103,13 @@ void fill_cpu_state(struct cpu_state *cpu, ucontext_t 
 
    for (int i = 0; i < 16; i++)
       cpu->regs[i] = uc->uc_mcontext._gregs[i];
+
+#elif defined __FreeBSD__ && defined __powerpc__
+   cpu->pc = uc->uc_mcontext.mc_srr0;
+   cpu->sp = uc->uc_mcontext.mc_gpr[1];
+
+   for (int i = 0; i < 31; i++)
+      cpu->regs[i] = uc->uc_mcontext.mc_gpr[i];
 #elif defined __OpenBSD__ && defined __x86_64__
    cpu->pc = uc->sc_rip;
    cpu->sp = uc->sc_rsp;
