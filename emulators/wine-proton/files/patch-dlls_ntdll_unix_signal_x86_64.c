--- dlls/ntdll/unix/signal_x86_64.c.orig
+++ dlls/ntdll/unix/signal_x86_64.c
@@ -156,6 +156,8 @@
 
 #elif defined(__FreeBSD__) || defined (__FreeBSD_kernel__)
 
+#include <machine/trap.h>
+
 #define RAX_sig(context)     ((context)->uc_mcontext.mc_rax)
 #define RBX_sig(context)     ((context)->uc_mcontext.mc_rbx)
 #define RCX_sig(context)     ((context)->uc_mcontext.mc_rcx)
@@ -260,5 +262,26 @@
 enum i386_trap_code
 {
+#if defined(__FreeBSD__) || defined (__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+    TRAP_x86_DIVIDE     = T_DIVIDE,     /* Division by zero exception */
+    TRAP_x86_TRCTRAP    = T_TRCTRAP,    /* Single-step exception */
+    TRAP_x86_NMI        = T_NMI,        /* NMI interrupt */
+    TRAP_x86_BPTFLT     = T_BPTFLT,     /* Breakpoint exception */
+    TRAP_x86_OFLOW      = T_OFLOW,      /* Overflow exception */
+    TRAP_x86_BOUND      = T_BOUND,      /* Bound range exception */
+    TRAP_x86_PRIVINFLT  = T_PRIVINFLT,  /* Invalid opcode exception */
+    TRAP_x86_DNA        = T_DNA,        /* Device not available exception */
+    TRAP_x86_DOUBLEFLT  = T_DOUBLEFLT,  /* Double fault exception */
+    TRAP_x86_FPOPFLT    = T_FPOPFLT,    /* Coprocessor segment overrun */
+    TRAP_x86_TSSFLT     = T_TSSFLT,     /* Invalid TSS exception */
+    TRAP_x86_SEGNPFLT   = T_SEGNPFLT,   /* Segment not present exception */
+    TRAP_x86_STKFLT     = T_STKFLT,     /* Stack fault */
+    TRAP_x86_PROTFLT    = T_PROTFLT,    /* General protection fault */
+    TRAP_x86_PAGEFLT    = T_PAGEFLT,    /* Page fault */
+    TRAP_x86_ARITHTRAP  = T_ARITHTRAP,  /* Floating point exception */
+    TRAP_x86_ALIGNFLT   = T_ALIGNFLT,   /* Alignment check exception */
+    TRAP_x86_MCHK       = T_MCHK,       /* Machine check exception */
+    TRAP_x86_CACHEFLT   = T_XMMFLT      /* Cache flush exception */
+#else
     TRAP_x86_DIVIDE     = 0,   /* Division by zero exception */
     TRAP_x86_TRCTRAP    = 1,   /* Single-step exception */
     TRAP_x86_NMI        = 2,   /* NMI interrupt */
@@ -278,7 +301,9 @@
     TRAP_x86_ARITHTRAP  = 16,  /* Floating point exception */
     TRAP_x86_ALIGNFLT   = 17,  /* Alignment check exception */
     TRAP_x86_MCHK       = 18,  /* Machine check exception */
-    TRAP_x86_CACHEFLT   = 19   /* Cache flush exception */
+    TRAP_x86_CACHEFLT   = 19   /* SIMD exception (via SIGFPE) if CPU is SSE capable
+                                  otherwise Cache flush exception (via SIGSEV) */
+#endif
 };
 
 static const size_t teb_size = 0x2000;  /* we reserve two pages for the TEB */
