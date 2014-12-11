--- debughelper.cpp.orig	2014-12-04 18:53:50 UTC
+++ debughelper.cpp
@@ -107,6 +107,7 @@ struct SimulatedCPU {
 //===========================CRASH HANDLER HEADER==============================
 
 #ifdef OS_IS_UNIX_LIKE
+#include "signal.h"
 #include "unistd.h"
 #include "sys/wait.h"
 #define SAFE_INT volatile sig_atomic_t
@@ -473,13 +474,25 @@ void print_backtrace(const QString& mess
 
 #define USE_SIGNAL_HANDLER
 #ifdef CPU_IS_X86_64
-#define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RIP]
-#define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RSP]
-#define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RBP]
+ #if defined(__FreeBSD__) 
+  #define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_rip
+  #define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_rsp
+  #define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_rbp
+ #else
+  #define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RIP]
+  #define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RSP]
+  #define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_RBP]
+ #endif
 #elif defined(CPU_IS_X86_32)
-#define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_EIP]
-#define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_ESP]
-#define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_EBP]
+ #if defined(__FreeBSD__)
+  #define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_eip
+  #define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_esp
+  #define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.mc_ebp
+ #else
+  #define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_EIP]
+  #define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_ESP]
+  #define FRAME_FROM_UCONTEXT(context) (context)->uc_mcontext.gregs[REG_EBP]
+ #endif
 #elif defined(CPU_IS_PPC)
 #define PC_FROM_UCONTEXT(context) (context)->uc_mcontext.gp_regs[32]
 #define STACK_FROM_UCONTEXT(context) (context)->uc_mcontext.gp_regs[1]
