--- src/vm/jit/x86_64/md.c.orig	Sun Feb  4 15:42:05 2007
+++ src/vm/jit/x86_64/md.c	Sun Feb  4 15:45:32 2007
@@ -91,8 +91,8 @@
 	/* ATTENTION: Don't use CACAO's internal REG_* defines as they are
 	   different to the ones in <ucontext.h>. */
 
-	sp  = (u1 *) _mc->gregs[REG_RSP];
-	xpc = (u1 *) _mc->gregs[REG_RIP];
+	sp  = (u1 *) _mc->mc_rsp;
+	xpc = (u1 *) _mc->mc_rip;
 	ra  = xpc;                          /* return address is equal to xpc     */
 
 #if 0
@@ -101,11 +101,11 @@
 	threads_check_stackoverflow(sp);
 #endif
 
-	_mc->gregs[REG_RAX] =
+	_mc->mc_rax =
 		(ptrint) stacktrace_hardware_nullpointerexception(NULL, sp, ra, xpc);
 
-	_mc->gregs[REG_R10] = (ptrint) xpc;                      /* REG_ITMP2_XPC */
-	_mc->gregs[REG_RIP] = (ptrint) asm_handle_exception;
+	_mc->mc_r10 = (ptrint) xpc;                      /* REG_ITMP2_XPC */
+	_mc->mc_rip = (ptrint) asm_handle_exception;
 }
 
 
@@ -130,15 +130,15 @@
 	/* ATTENTION: Don't use CACAO's internal REG_* defines as they are
 	   different to the ones in <ucontext.h>. */
 
-	sp  = (u1 *) _mc->gregs[REG_RSP];
-	xpc = (u1 *) _mc->gregs[REG_RIP];
+	sp  = (u1 *) _mc->mc_rsp;
+	xpc = (u1 *) _mc->mc_rip;
 	ra  = xpc;                          /* return address is equal to xpc     */
 
-	_mc->gregs[REG_RAX] =
+	_mc->mc_rax =
 		(ptrint) stacktrace_hardware_arithmeticexception(NULL, sp, ra, xpc);
 
-	_mc->gregs[REG_R10] = (ptrint) xpc;                      /* REG_ITMP2_XPC */
-	_mc->gregs[REG_RIP] = (ptrint) asm_handle_exception;
+	_mc->mc_r10 = (ptrint) xpc;                      /* REG_ITMP2_XPC */
+	_mc->mc_rip = (ptrint) asm_handle_exception;
 }
 
 
@@ -164,7 +164,7 @@
 	/* ATTENTION: Don't use CACAO's internal REG_* defines as they are
 	   different to the ones in <ucontext.h>. */
 
-	pc = (u1 *) _mc->gregs[REG_RIP];
+	pc = (u1 *) _mc->mc_rip;
 
 	t->pc = pc;
 }
@@ -179,10 +179,10 @@
 
 	_mc = &_uc->uc_mcontext;
 
-	pc = critical_find_restart_point((void *) _mc->gregs[REG_RIP]);
+	pc = critical_find_restart_point((void *) _mc->mc_rip);
 
 	if (pc != NULL)
-		_mc->gregs[REG_RIP] = (ptrint) pc;
+		_mc->mc_rip = (ptrint) pc;
 }
 #endif
 
