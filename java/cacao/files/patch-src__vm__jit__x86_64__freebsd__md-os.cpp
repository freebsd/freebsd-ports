--- src/vm/jit/x86_64/freebsd/md-os.cpp.orig	2013-06-28 09:22:27.000000000 -0400
+++ src/vm/jit/x86_64/freebsd/md-os.cpp	2013-07-08 16:05:56.000000000 -0400
@@ -2,7 +2,6 @@
 
    Copyright (C) 1996-2013
    CACAOVM - Verein zur Foerderung der freien virtuellen Maschine CACAO
-   Copyright (C) 2009 Theobroma Systems Ltd.
 
    This file is part of CACAO.
 
@@ -28,79 +27,65 @@
 
 #include <cassert>
 #include <cstdlib>
+#include <stdint.h>
 #include <ucontext.h>
 
-#include "threads/thread.hpp"
-
-#include "vm/signallocal.hpp"
+#include "vm/types.hpp"
 
-#include "vm/jit/asmpart.hpp"
-#include "vm/jit/stacktrace.hpp"
+#include "vm/jit/x86_64/codegen.hpp"
+#include "vm/jit/x86_64/md.hpp"
 
+#include "threads/thread.hpp"
 
-/* md_signal_handler_sigsegv ***************************************************
+#include "vm/signallocal.hpp"
 
-   NullPointerException signal handler for hardware null pointer
-   check.
+#include "vm/jit/executionstate.hpp"
+#include "vm/jit/trap.hpp"
 
-*******************************************************************************/
 
+/**
+ * Signal handler for hardware exception.
+ */
 void md_signal_handler_sigsegv(int sig, siginfo_t *siginfo, void *_p)
 {
-	ucontext_t *_uc;
-	mcontext_t *_mc;
-	u1         *sp;
-	u1         *ra;
-	u1         *xpc;
+	ucontext_t* _uc = (ucontext_t *) _p;
+	mcontext_t* _mc = &_uc->uc_mcontext;
 
-	_uc = (ucontext_t *) _p;
-	_mc = &_uc->uc_mcontext;
+	void* xpc = (void*) _mc->mc_rip;
 
-	sp  = (u1 *) _mc->mc_rsp;
-	xpc = (u1 *) _mc->mc_rip;
-	ra  = xpc;                          /* return address is equal to xpc     */
+	// Handle the trap.
+	trap_handle(TRAP_SIGSEGV, xpc, _p);
+}
 
-#if 0
-	/* check for StackOverflowException */
 
-	threads_check_stackoverflow(sp);
-#endif
+/**
+ * ArithmeticException signal handler for hardware divide by zero
+ * check.
+ */
+void md_signal_handler_sigfpe(int sig, siginfo_t *siginfo, void *_p)
+{
+	ucontext_t* _uc = (ucontext_t *) _p;
+	mcontext_t* _mc = &_uc->uc_mcontext;
 
-	_mc->mc_rax =
-		(ptrint) stacktrace_hardware_nullpointerexception(NULL, sp, ra, xpc);
+	void* xpc = (void*) _mc->mc_rip;
 
-	_mc->mc_r10 = (ptrint) xpc;                              /* REG_ITMP2_XPC */
-	_mc->mc_rip = (ptrint) asm_handle_exception;
+	// Handle the trap.
+	trap_handle(TRAP_SIGFPE, xpc, _p);
 }
 
 
-/* md_signal_handler_sigfpe ****************************************************
-
-   ArithmeticException signal handler for hardware divide by zero
-   check.
-
-*******************************************************************************/
-
-void md_signal_handler_sigfpe(int sig, siginfo_t *siginfo, void *_p)
+/**
+ * Signal handler for patchers.
+ */
+void md_signal_handler_sigill(int sig, siginfo_t *siginfo, void *_p)
 {
-	ucontext_t  *_uc;
-	mcontext_t  *_mc;
-	u1          *sp;
-	u1          *ra;
-	u1          *xpc;
-
-	_uc = (ucontext_t *) _p;
-	_mc = &_uc->uc_mcontext;
-
-	sp  = (u1 *) _mc->mc_rsp;
-	xpc = (u1 *) _mc->mc_rip;
-	ra  = xpc;                          /* return address is equal to xpc     */
+	ucontext_t* _uc = (ucontext_t *) _p;
+	mcontext_t* _mc = &_uc->uc_mcontext;
 
-	_mc->mc_rax =
-		(ptrint) stacktrace_hardware_arithmeticexception(NULL, sp, ra, xpc);
+	void* xpc = (void*) _mc->mc_rip;
 
-	_mc->mc_r10 = (ptrint) xpc;                              /* REG_ITMP2_XPC */
-	_mc->mc_rip = (ptrint) asm_handle_exception;
+	// Handle the trap.
+	trap_handle(TRAP_SIGILL, xpc, _p);
 }
 
 
@@ -130,6 +115,88 @@
 #endif
 
 
+/* md_executionstate_read ******************************************************
+
+   Read the given context into an executionstate.
+
+*******************************************************************************/
+
+void md_executionstate_read(executionstate_t *es, void *context)
+{
+	ucontext_t *_uc;
+	mcontext_t *_mc;
+	s4          i;
+
+	_uc = (ucontext_t *) context;
+	_mc = &_uc->uc_mcontext;
+
+	/* read special registers */
+	es->pc = (u1 *) _mc->mc_rip;
+	es->sp = (u1 *) _mc->mc_rsp;
+	es->pv = NULL;
+
+	/* read integer registers */
+	es->intregs[RAX] = _mc->mc_rax;
+	es->intregs[RCX] = _mc->mc_rcx;
+	es->intregs[RDX] = _mc->mc_rdx;
+	es->intregs[RBX] = _mc->mc_rbx;
+	es->intregs[RSP] = _mc->mc_rsp;
+	es->intregs[RBP] = _mc->mc_rbp;
+	es->intregs[RSI] = _mc->mc_rsi;
+	es->intregs[RDI] = _mc->mc_rdi;
+	es->intregs[R8] = _mc->mc_r8;
+	es->intregs[R9] = _mc->mc_r9;
+	es->intregs[R10] = _mc->mc_r10;
+	es->intregs[R11] = _mc->mc_r11;
+	es->intregs[R12] = _mc->mc_r12;
+	es->intregs[R13] = _mc->mc_r13;
+	es->intregs[R14] = _mc->mc_r14;
+	es->intregs[R15] = _mc->mc_r15;
+
+	/* read float registers */
+	for (i = 0; i < FLT_REG_CNT; i++)
+		es->fltregs[i] = 0xdeadbeefdeadbeefL;
+}
+
+
+/* md_executionstate_write *****************************************************
+
+   Write the given executionstate back to the context.
+
+*******************************************************************************/
+
+void md_executionstate_write(executionstate_t *es, void *context)
+{
+	ucontext_t *_uc;
+	mcontext_t *_mc;
+
+	_uc = (ucontext_t *) context;
+	_mc = &_uc->uc_mcontext;
+
+	/* write integer registers */
+	_mc->mc_rax = es->intregs[RAX];
+	_mc->mc_rcx = es->intregs[RCX];
+	_mc->mc_rdx = es->intregs[RDX];
+	_mc->mc_rbx = es->intregs[RBX];
+	_mc->mc_rsp = es->intregs[RSP];
+	_mc->mc_rbp = es->intregs[RBP];
+	_mc->mc_rsi = es->intregs[RSI];
+	_mc->mc_rdi = es->intregs[RDI];
+	_mc->mc_r8 = es->intregs[R8];
+	_mc->mc_r9 = es->intregs[R9];
+	_mc->mc_r10 = es->intregs[R10];
+	_mc->mc_r11 = es->intregs[R11];
+	_mc->mc_r12 = es->intregs[R12];
+	_mc->mc_r13 = es->intregs[R13];
+	_mc->mc_r14 = es->intregs[R14];
+	_mc->mc_r15 = es->intregs[R15];
+
+	/* write special registers */
+	_mc->mc_rip = (ptrint) es->pc;
+	_mc->mc_rsp = (ptrint) es->sp;
+}
+
+
 /*
  * These are local overrides for various environment variables in Emacs.
  * Please do not remove this and leave it at the end of the file, where
