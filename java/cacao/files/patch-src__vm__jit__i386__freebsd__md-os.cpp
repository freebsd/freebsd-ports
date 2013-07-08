--- src/vm/jit/i386/freebsd/md-os.cpp.orig	2013-06-28 09:22:26.000000000 -0400
+++ src/vm/jit/i386/freebsd/md-os.cpp	2013-07-08 16:02:06.000000000 -0400
@@ -2,6 +2,7 @@
 
    Copyright (C) 1996-2013
    CACAOVM - Verein zur Foerderung der freien virtuellen Maschine CACAO
+   Copyright (C) 2009 Theobroma Systems Ltd.
 
    This file is part of CACAO.
 
@@ -35,218 +36,55 @@
 
 #include "threads/thread.hpp"
 
-#include "vm/jit/builtin.hpp"
 #include "vm/signallocal.hpp"
 
-#include "vm/jit/asmpart.hpp"
 #include "vm/jit/executionstate.hpp"
-#include "vm/jit/stacktrace.hpp"
 #include "vm/jit/trap.hpp"
 
 
-/* md_signal_handler_sigsegv ***************************************************
-
-   Signal handler for hardware exceptions.
-
-*******************************************************************************/
-
+/**
+ * Signal handler for hardware exceptions.
+ */
 void md_signal_handler_sigsegv(int sig, siginfo_t *siginfo, void *_p)
 {
-	ucontext_t     *_uc;
-	mcontext_t     *_mc;
-	u1             *pv;
-	u1             *sp;
-	u1             *ra;
-	u1             *xpc;
-	u1              opc;
-	u1              mod;
-	u1              rm;
-	s4              d;
-	s4              disp;
-	ptrint          val;
-	s4              type;
-	void           *p;
+	ucontext_t* _uc = (ucontext_t *) _p;
+	mcontext_t* _mc = &_uc->uc_mcontext;
 
-	_uc = (ucontext_t *) _p;
-	_mc = &_uc->uc_mcontext;
+	void* xpc = (void*) _mc->mc_eip;
 
-	pv  = NULL;                 /* is resolved during stackframeinfo creation */
-	sp  = (u1 *) _mc->mc_esp;
-	xpc = (u1 *) _mc->mc_eip;
-	ra  = xpc;                              /* return address is equal to XPC */
-
-	/* get exception-throwing instruction */
-
-	opc = M_ALD_MEM_GET_OPC(xpc);
-	mod = M_ALD_MEM_GET_MOD(xpc);
-	rm  = M_ALD_MEM_GET_RM(xpc);
-
-	/* for values see emit_mov_mem_reg and emit_mem */
-
-	if ((opc == 0x8b) && (mod == 0) && (rm == 5)) {
-		/* this was a hardware-exception */
-
-		d    = M_ALD_MEM_GET_REG(xpc);
-		disp = M_ALD_MEM_GET_DISP(xpc);
-
-		/* we use the exception type as load displacement */
-
-		type = disp;
-
-		switch (d) {
-		case EAX:
-			val = _mc->mc_eax;
-			break;
-		case ECX:
-			val = _mc->mc_ecx;
-			break;
-		case EDX:
-			val = _mc->mc_edx;
-			break;
-		case EBX:
-			val = _mc->mc_ebx;
-			break;
-		case ESP:
-			val = _mc->mc_esp;
-			break;
-		case EBP:
-			val = _mc->mc_ebp;
-			break;
-		case ESI:
-			val = _mc->mc_esi;
-			break;
-		case EDI:
-			val = _mc->mc_edi;
-			break;
-		default:
-			vm_abort("md_signal_handler_sigsegv: Unkown register %d", d);
-		}
-
-		if (type == TRAP_COMPILER) {
-			/* The PV from the compiler stub is equal to the XPC. */
-
-			pv = xpc;
-
-			/* We use a framesize of zero here because the call pushed
-			   the return addres onto the stack. */
-
-			ra = md_stacktrace_get_returnaddress(sp, 0);
-
-			/* Skip the RA on the stack. */
-
-			sp = sp + 1 * SIZEOF_VOID_P;
-
-			/* The XPC is the RA minus 2, because the RA points to the
-			   instruction after the call. */
-
-			xpc = ra - 2;
-		}
-	}
-	else {
-		/* this was a normal NPE */
-
-		type = TRAP_NullPointerException;
-		val  = 0;
-	}
-
-	/* Handle the trap. */
-
-	p = trap_handle(type, val, pv, sp, ra, xpc, _p);
-
-	/* Set registers. */
-
-	if (type == TRAP_COMPILER) {
-		if (p == NULL) {
-			_mc->mc_esp = (uintptr_t) sp; // Remove RA from stack.
-		}
-	}
+	// Handle the trap.
+	trap_handle(TRAP_SIGSEGV, xpc, _p);
 }
 
 
-/* md_signal_handler_sigfpe ****************************************************
-
-   ArithmeticException signal handler for hardware divide by zero
-   check.
-
-*******************************************************************************/
-
+/**
+ * Signal handler for hardware divide by zero (ArithmeticException)
+ * check.
+ */
 void md_signal_handler_sigfpe(int sig, siginfo_t *siginfo, void *_p)
 {
-	ucontext_t     *_uc;
-	mcontext_t     *_mc;
-	u1             *pv;
-	u1             *sp;
-	u1             *ra;
-	u1             *xpc;
-	s4              type;
-	ptrint          val;
-
-	_uc = (ucontext_t *) _p;
-	_mc = &_uc->uc_mcontext;
-
-	pv  = NULL;                 /* is resolved during stackframeinfo creation */
-	sp  = (u1 *) _mc->mc_esp;
-	xpc = (u1 *) _mc->mc_eip;
-	ra  = xpc;                          /* return address is equal to xpc     */
-
-	/* This is an ArithmeticException. */
-
-	type = TRAP_ArithmeticException;
-	val  = 0;
+	ucontext_t* _uc = (ucontext_t *) _p;
+	mcontext_t* _mc = &_uc->uc_mcontext;
 
-	/* Handle the trap. */
+	void* xpc = (void*) _mc->mc_eip;
 
-	trap_handle(type, val, pv, sp, ra, xpc, _p);
+	// Handle the trap.
+	trap_handle(TRAP_SIGFPE, xpc, _p);
 }
 
 
-/* md_signal_handler_sigill ****************************************************
-
-   Signal handler for hardware patcher traps (ud2).
-
-*******************************************************************************/
-
+/**
+ * Signal handler for hardware patcher traps (ud2).
+ */
 void md_signal_handler_sigill(int sig, siginfo_t *siginfo, void *_p)
 {
-	ucontext_t        *_uc;
-	mcontext_t        *_mc;
-	u1                *pv;
-	u1                *sp;
-	u1                *ra;
-	u1                *xpc;
-	s4                 type;
-	ptrint             val;
-
-	_uc = (ucontext_t *) _p;
-	_mc = &_uc->uc_mcontext;
-
-	pv  = NULL;                 /* is resolved during stackframeinfo creation */
-	sp  = (u1 *) _mc->mc_esp;
-	xpc = (u1 *) _mc->mc_eip;
-	ra  = xpc;                            /* return address is equal to xpc   */
-
-	// Check if the trap instruction is valid.
-	// TODO Move this into patcher_handler.
-	if (patcher_is_valid_trap_instruction_at(xpc) == false) {
-		// Check if the PC has been patched during our way to this
-		// signal handler (see PR85).
-		if (patcher_is_patched_at(xpc) == true)
-			return;
-
-		// We have a problem...
-		log_println("md_signal_handler_sigill: Unknown illegal instruction at 0x%lx", xpc);
-#if defined(ENABLE_DISASSEMBLER)
-		(void) disassinstr(xpc);
-#endif
-		vm_abort("Aborting...");
-	}
-
-	type = TRAP_PATCHER;
-	val  = 0;
+	ucontext_t* _uc = (ucontext_t *) _p;
+	mcontext_t* _mc = &_uc->uc_mcontext;
 
-	/* Handle the trap. */
+	void* xpc = (void*) _mc->mc_eip;
 
-	trap_handle(type, val, pv, sp, ra, xpc, _p);
+	// Handle the trap.
+	trap_handle(TRAP_SIGILL, xpc, _p);
 }
 
 
@@ -282,17 +120,21 @@
 
 *******************************************************************************/
 
-void md_executionstate_read(executionstate_t* es, void* context)
+void md_executionstate_read(executionstate_t *es, void *context)
 {
-	ucontext_t* _uc = (ucontext_t*) context;
-	mcontext_t* _mc = &_uc->uc_mcontext;
+	ucontext_t *_uc;
+	mcontext_t *_mc;
+	s4          i;
 
-	// Read special registers.
+	_uc = (ucontext_t *) context;
+	_mc = &_uc->uc_mcontext;
+
+	/* read special registers */
 	es->pc = (u1 *) _mc->mc_eip;
 	es->sp = (u1 *) _mc->mc_esp;
 	es->pv = NULL;                   /* pv must be looked up via AVL tree */
 
-	// Read integer registers.
+	/* read integer registers */
 	es->intregs[EAX] = _mc->mc_eax;
 	es->intregs[ECX] = _mc->mc_ecx;
 	es->intregs[EDX] = _mc->mc_edx;
@@ -302,8 +144,8 @@
 	es->intregs[ESI] = _mc->mc_esi;
 	es->intregs[EDI] = _mc->mc_edi;
 
-	// Read float registers.
-	for (int i = 0; i < FLT_REG_CNT; i++)
+	/* read float registers */
+	for (i = 0; i < FLT_REG_CNT; i++)
 		es->fltregs[i] = 0xdeadbeefdeadbeefULL;
 }
 
@@ -314,12 +156,15 @@
 
 *******************************************************************************/
 
-void md_executionstate_write(executionstate_t* es, void* context)
+void md_executionstate_write(executionstate_t *es, void *context)
 {
-	ucontext_t* _uc = (ucontext_t*) context;
-	mcontext_t* _mc = &_uc->uc_mcontext;
+	ucontext_t *_uc;
+	mcontext_t *_mc;
+
+	_uc = (ucontext_t *) context;
+	_mc = &_uc->uc_mcontext;
 
-	// Write integer registers.
+	/* write integer registers */
 	_mc->mc_eax = es->intregs[EAX];
 	_mc->mc_ecx = es->intregs[ECX];
 	_mc->mc_edx = es->intregs[EDX];
@@ -329,9 +174,9 @@
 	_mc->mc_esi = es->intregs[ESI];
 	_mc->mc_edi = es->intregs[EDI];
 
-	// Write special registers.
-	_mc->mc_eip = (uintptr_t) es->pc;
-	_mc->mc_esp = (uintptr_t) es->sp;
+	/* write special registers */
+	_mc->mc_eip = (ptrint) es->pc;
+	_mc->mc_esp = (ptrint) es->sp;
 }
 
 
@@ -341,7 +186,7 @@
  * Emacs will automagically detect them.
  * ---------------------------------------------------------------------
  * Local variables:
- * mode: c
+ * mode: c++
  * indent-tabs-mode: t
  * c-basic-offset: 4
  * tab-width: 4
