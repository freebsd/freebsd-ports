Index: qemu/cpu-exec.c
@@ -1158,6 +1158,12 @@
 # define EIP_sig(context)  (*((unsigned long*)&(context)->uc_mcontext->ss.eip))
 # define TRAP_sig(context)    ((context)->uc_mcontext->es.trapno)
 # define ERROR_sig(context)   ((context)->uc_mcontext->es.err)
+#elif defined(__FreeBSD__) 
+# include <sys/ucontext.h>
+
+# define EIP_sig(context)  (*((unsigned long*)&(context)->uc_mcontext.mc_eip))
+# define TRAP_sig(context)    ((context)->uc_mcontext.mc_trapno)
+# define ERROR_sig(context)   ((context)->uc_mcontext.mc_err)
 #else
 # define EIP_sig(context)     ((context)->uc_mcontext.gregs[REG_EIP])
 # define TRAP_sig(context)    ((context)->uc_mcontext.gregs[REG_TRAPNO])
@@ -1168,7 +1174,11 @@
                        void *puc)
 {
     siginfo_t *info = pinfo;
+#ifdef __FreeBSD__
+    ucontext_t *uc = puc;
+#else
     struct ucontext *uc = puc;
+#endif
     unsigned long pc;
     int trapno;
 
@@ -1194,6 +1204,12 @@
 
 #define QEMU_UC_MCONTEXT_GREGS(uc, reg)	(uc)->uc_mcontext.__gregs[(reg)]
 #define QEMU_UC_MACHINE_PC(uc)		_UC_MACHINE_PC(uc)
+#elif defined(__FreeBSD__) 
+# include <sys/ucontext.h>
+
+# define RIP_sig(context)  (*((unsigned long*)&(context)->uc_mcontext.mc_rip))
+# define TRAP_sig(context)    ((context)->uc_mcontext.mc_trapno)
+# define ERROR_sig(context)   ((context)->uc_mcontext.mc_err)
 #else
 #define QEMU_UC_MCONTEXT_GREGS(uc, reg)	(uc)->uc_mcontext.gregs[(reg)]
 #define QEMU_UC_MACHINE_PC(uc)		QEMU_UC_MCONTEXT_GREGS(uc, REG_RIP)
@@ -1204,17 +1220,25 @@
 {
     siginfo_t *info = pinfo;
     unsigned long pc;
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
     ucontext_t *uc = puc;
 #else
     struct ucontext *uc = puc;
 #endif
 
+#ifdef __FreeBSD__
+    pc = RIP_sig(uc);
+    return handle_cpu_signal(pc, (unsigned long)info->si_addr,
+                             TRAP_sig(uc) == 0xe ?
+                             (ERROR_sig(uc) >> 1) & 1 : 0,
+                             &uc->uc_sigmask, puc);
+#else
     pc = QEMU_UC_MACHINE_PC(uc);
     return handle_cpu_signal(pc, (unsigned long)info->si_addr,
                              QEMU_UC_MCONTEXT_GREGS(uc, REG_TRAPNO) == 0xe ?
                              (QEMU_UC_MCONTEXT_GREGS(uc, REG_ERR) >> 1) & 1 : 0,
                              &uc->uc_sigmask, puc);
+#endif
 }
 
 #elif defined(__powerpc__)
