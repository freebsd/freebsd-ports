--- debughelper.cpp.orig	2014-11-22 19:10:03.000000000 -0430
+++ debughelper.cpp	2014-11-22 19:12:01.000000000 -0430
@@ -107,6 +107,7 @@
 //===========================CRASH HANDLER HEADER==============================
 
 #ifdef OS_IS_UNIX_LIKE
+#include "signal.h"
 #include "unistd.h"
 #include "sys/wait.h"
 #define SAFE_INT volatile sig_atomic_t
@@ -472,11 +473,19 @@
 #include "pthread.h"
 
 #define USE_SIGNAL_HANDLER
-#ifdef CPU_IS_X86_64
+#if (defined(__FreeBSD__) && defined(CPU_IS_X86_64))
+#define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_rip
+#define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_rsp
+#define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_rbp
+#elif (defined(__FreeBSD__) && defined(CPU_IS_X86_32))
+#define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_eip
+#define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_esp
+#define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_ebp
+#elif (!defined(__FreeBSD__) && defined(CPU_IS_X86_64))
 #define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RIP]
 #define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RSP]
 #define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RBP]
-#elif defined(CPU_IS_X86_32)
+#elif (!defined(__FreeBSD__) && defined(CPU_IS_X86_32))
 #define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_EIP]
 #define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_ESP]
 #define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_EBP]
