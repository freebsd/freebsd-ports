--- src/osdep/sigsegv_handler.cpp.orig	2026-06-19 16:11:53 UTC
+++ src/osdep/sigsegv_handler.cpp
@@ -2,7 +2,7 @@
  * sigsegv_linux_arm.cpp - x86_64 Linux SIGSEGV handler
  *
  * Copyright (c) 2014 Jens Heitmann ARAnyM dev team (see AUTHORS)
- * 
+ *
  * Inspired by Bernie Meyer's UAE-JIT and Gwenole Beauchesne's Basilisk II-JIT
  *
  * This file is part of the ARAnyM project which builds a new and powerful
@@ -564,8 +564,8 @@ extern void raise_in_cl_list(blockinfo* bi);
 extern void invalidate_block(blockinfo* bi);
 extern void raise_in_cl_list(blockinfo* bi);
 #endif
-  
 
+
 #define SHOW_DETAILS 2
 
 #define output_log write_log
@@ -583,9 +583,9 @@ enum type_size_t {
 	SIZE_INT
 };
 
-enum style_type_t { 
-  STYLE_SIGNED, 
-  STYLE_UNSIGNED 
+enum style_type_t {
+  STYLE_SIGNED,
+  STYLE_UNSIGNED
 };
 
 #define HANDLE_EXCEPTION_NONE 0
@@ -593,7 +593,7 @@ static int in_handler = 0;
 #define HANDLE_EXCEPTION_A4000RAM 2
 
 static int in_handler = 0;
-static int max_signals = 200;  
+static int max_signals = 200;
 
 void init_max_signals()
 {
@@ -1370,7 +1370,7 @@ static int handle_exception(unsigned long* pregs, long
 			handled = HANDLE_EXCEPTION_A4000RAM;
 			break;
 		}
-  
+
 		// Get memory bank of address
 		auto* ab = &get_mem_bank(amiga_addr);
 		if (ab)
@@ -1525,7 +1525,11 @@ void signal_segv(int signum, siginfo_t* info, void* pt
 #if !defined (CPU_AMD64) && !defined (__x86_64__)
 	mcontext_t* context = &(ucontext->uc_mcontext);
 
-	unsigned long* regs = &context->arm_r0;
+	#if defined(__FreeBSD__) && defined(CPU_arm) && !defined(CPU_AARCH64)
+		unsigned long* regs = (unsigned long*)&context->__gregs[_REG_R0];
+	#else
+		unsigned long* regs = &context->arm_r0;
+	#endif
 	uintptr addr = (uintptr)info->si_addr;
 
 	handled = handle_exception(regs, addr);
@@ -1545,29 +1549,58 @@ void signal_segv(int signum, siginfo_t* info, void* pt
 		output_log(_T("info.si_addr = %p\n"), info->si_addr);
 		if (signum == 4)
 			output_log(_T("       value = 0x%08x\n"), *((uae_u32*)(info->si_addr)));
-		output_log(_T("r0  = 0x%08x\n"), ucontext->uc_mcontext.arm_r0);
-		output_log(_T("r1  = 0x%08x\n"), ucontext->uc_mcontext.arm_r1);
-		output_log(_T("r2  = 0x%08x\n"), ucontext->uc_mcontext.arm_r2);
-		output_log(_T("r3  = 0x%08x\n"), ucontext->uc_mcontext.arm_r3);
-		output_log(_T("r4  = 0x%08x\n"), ucontext->uc_mcontext.arm_r4);
-		output_log(_T("r5  = 0x%08x\n"), ucontext->uc_mcontext.arm_r5);
-		output_log(_T("r6  = 0x%08x\n"), ucontext->uc_mcontext.arm_r6);
-		output_log(_T("r7  = 0x%08x\n"), ucontext->uc_mcontext.arm_r7);
-		output_log(_T("r8  = 0x%08x\n"), ucontext->uc_mcontext.arm_r8);
-		output_log(_T("r9  = 0x%08x\n"), ucontext->uc_mcontext.arm_r9);
-		output_log(_T("r10 = 0x%08x\n"), ucontext->uc_mcontext.arm_r10);
-		output_log(_T("FP  = 0x%08x\n"), ucontext->uc_mcontext.arm_fp);
-		output_log(_T("IP  = 0x%08x\n"), ucontext->uc_mcontext.arm_ip);
-		output_log(_T("SP  = 0x%08x\n"), ucontext->uc_mcontext.arm_sp);
-		output_log(_T("LR  = 0x%08x\n"), ucontext->uc_mcontext.arm_lr);
-		output_log(_T("PC  = 0x%08x\n"), ucontext->uc_mcontext.arm_pc);
-		output_log(_T("CPSR = 0x%08x\n"), ucontext->uc_mcontext.arm_cpsr);
-		output_log(_T("Fault Address = 0x%08x\n"), ucontext->uc_mcontext.fault_address);
-		output_log(_T("Trap no = 0x%08x\n"), ucontext->uc_mcontext.trap_no);
-		output_log(_T("Err Code = 0x%08x\n"), ucontext->uc_mcontext.error_code);
-		output_log(_T("Old Mask = 0x%08x\n"), ucontext->uc_mcontext.oldmask);
+		#if defined(__FreeBSD__) && defined(CPU_arm) && !defined(CPU_AARCH64)
+			output_log(_T("r0  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R0]);
+			output_log(_T("r1  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R1]);
+			output_log(_T("r2  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R2]);
+			output_log(_T("r3  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R3]);
+			output_log(_T("r4  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R4]);
+			output_log(_T("r5  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R5]);
+			output_log(_T("r6  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R6]);
+			output_log(_T("r7  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R7]);
+			output_log(_T("r8  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R8]);
+			output_log(_T("r9  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R9]);
+			output_log(_T("r10 = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R10]);
+			output_log(_T("FP  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_FP]);
+			output_log(_T("IP  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R12]);
+			output_log(_T("SP  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_SP]);
+			output_log(_T("LR  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_LR]);
+			output_log(_T("PC  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_PC]);
+			output_log(_T("CPSR = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_CPSR]);
+			output_log(_T("Fault Address = 0x%08x\n"), (unsigned int)info->si_addr);
+			output_log(_T("Trap no = 0x%08x\n"), info->si_errno);
+			output_log(_T("Err Code = 0x%08x\n"), info->si_code);
+			output_log(_T("Old Mask = 0x%08x\n"), ucontext->uc_sigmask.__bits[0]);
+		#else
+			output_log(_T("r0  = 0x%08x\n"), ucontext->uc_mcontext.arm_r0);
+			output_log(_T("r1  = 0x%08x\n"), ucontext->uc_mcontext.arm_r1);
+			output_log(_T("r2  = 0x%08x\n"), ucontext->uc_mcontext.arm_r2);
+			output_log(_T("r3  = 0x%08x\n"), ucontext->uc_mcontext.arm_r3);
+			output_log(_T("r4  = 0x%08x\n"), ucontext->uc_mcontext.arm_r4);
+			output_log(_T("r5  = 0x%08x\n"), ucontext->uc_mcontext.arm_r5);
+			output_log(_T("r6  = 0x%08x\n"), ucontext->uc_mcontext.arm_r6);
+			output_log(_T("r7  = 0x%08x\n"), ucontext->uc_mcontext.arm_r7);
+			output_log(_T("r8  = 0x%08x\n"), ucontext->uc_mcontext.arm_r8);
+			output_log(_T("r9  = 0x%08x\n"), ucontext->uc_mcontext.arm_r9);
+			output_log(_T("r10 = 0x%08x\n"), ucontext->uc_mcontext.arm_r10);
+			output_log(_T("FP  = 0x%08x\n"), ucontext->uc_mcontext.arm_fp);
+			output_log(_T("IP  = 0x%08x\n"), ucontext->uc_mcontext.arm_ip);
+			output_log(_T("SP  = 0x%08x\n"), ucontext->uc_mcontext.arm_sp);
+			output_log(_T("LR  = 0x%08x\n"), ucontext->uc_mcontext.arm_lr);
+			output_log(_T("PC  = 0x%08x\n"), ucontext->uc_mcontext.arm_pc);
+			output_log(_T("CPSR = 0x%08x\n"), ucontext->uc_mcontext.arm_cpsr);
+			output_log(_T("Fault Address = 0x%08x\n"), ucontext->uc_mcontext.fault_address);
+			output_log(_T("Trap no = 0x%08x\n"), ucontext->uc_mcontext.trap_no);
+			output_log(_T("Err Code = 0x%08x\n"), ucontext->uc_mcontext.error_code);
+			output_log(_T("Old Mask = 0x%08x\n"), ucontext->uc_mcontext.oldmask);
+		#endif
 
-		void* getaddr = (void*)ucontext->uc_mcontext.arm_lr;
+		#if defined(__FreeBSD__) && defined(CPU_arm) && !defined(CPU_AARCH64)
+			void* getaddr = (void*)ucontext->uc_mcontext.__gregs[_REG_LR];
+		#else
+			void* getaddr = (void*)ucontext->uc_mcontext.arm_lr;
+		#endif
+
 		if (dladdr(getaddr, &dlinfo))
 			output_log(_T("LR - 0x%08X: <%s> (%s)\n"), getaddr, dlinfo.dli_sname, dlinfo.dli_fname);
 		else
@@ -1654,7 +1687,11 @@ void signal_buserror(int signum, siginfo_t* info, void
 	mcontext_t* context = &(ucontext->uc_mcontext);
 
 #if !defined (CPU_AMD64) && !defined (__x86_64__)
-	unsigned long* regs = &context->arm_r0;
+	#if defined(__FreeBSD__) && defined(CPU_arm) && !defined(CPU_AARCH64)
+		unsigned long* regs = (unsigned long*)&context->__gregs[_REG_R0];
+	#else
+		unsigned long* regs = &context->arm_r0;
+	#endif
 	uintptr_t addr = (uintptr_t)info->si_addr;
 
 	output_log(_T("info.si_signo = %d\n"), signum);
@@ -1663,29 +1700,57 @@ void signal_buserror(int signum, siginfo_t* info, void
 	output_log(_T("info.si_addr = %p\n"), info->si_addr);
 	if (signum == 4)
 		output_log(_T("       value = 0x%08x\n"), *((uae_u32*)(info->si_addr)));
-	output_log(_T("r0  = 0x%08x\n"), ucontext->uc_mcontext.arm_r0);
-	output_log(_T("r1  = 0x%08x\n"), ucontext->uc_mcontext.arm_r1);
-	output_log(_T("r2  = 0x%08x\n"), ucontext->uc_mcontext.arm_r2);
-	output_log(_T("r3  = 0x%08x\n"), ucontext->uc_mcontext.arm_r3);
-	output_log(_T("r4  = 0x%08x\n"), ucontext->uc_mcontext.arm_r4);
-	output_log(_T("r5  = 0x%08x\n"), ucontext->uc_mcontext.arm_r5);
-	output_log(_T("r6  = 0x%08x\n"), ucontext->uc_mcontext.arm_r6);
-	output_log(_T("r7  = 0x%08x\n"), ucontext->uc_mcontext.arm_r7);
-	output_log(_T("r8  = 0x%08x\n"), ucontext->uc_mcontext.arm_r8);
-	output_log(_T("r9  = 0x%08x\n"), ucontext->uc_mcontext.arm_r9);
-	output_log(_T("r10 = 0x%08x\n"), ucontext->uc_mcontext.arm_r10);
-	output_log(_T("FP  = 0x%08x\n"), ucontext->uc_mcontext.arm_fp);
-	output_log(_T("IP  = 0x%08x\n"), ucontext->uc_mcontext.arm_ip);
-	output_log(_T("SP  = 0x%08x\n"), ucontext->uc_mcontext.arm_sp);
-	output_log(_T("LR  = 0x%08x\n"), ucontext->uc_mcontext.arm_lr);
-	output_log(_T("PC  = 0x%08x\n"), ucontext->uc_mcontext.arm_pc);
-	output_log(_T("CPSR = 0x%08x\n"), ucontext->uc_mcontext.arm_cpsr);
-	output_log(_T("Trap no = 0x%08x\n"), ucontext->uc_mcontext.trap_no);
-	output_log(_T("Err Code = 0x%08x\n"), ucontext->uc_mcontext.error_code);
-	output_log(_T("Old Mask = 0x%08x\n"), ucontext->uc_mcontext.oldmask);
-	output_log(_T("Fault Address = 0x%08x\n"), ucontext->uc_mcontext.fault_address);
+	#if defined(__FreeBSD__) && defined(CPU_arm) && !defined(CPU_AARCH64)
+		output_log(_T("r0  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R0]);
+		output_log(_T("r1  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R1]);
+		output_log(_T("r2  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R2]);
+		output_log(_T("r3  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R3]);
+		output_log(_T("r4  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R4]);
+		output_log(_T("r5  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R5]);
+		output_log(_T("r6  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R6]);
+		output_log(_T("r7  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R7]);
+		output_log(_T("r8  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R8]);
+		output_log(_T("r9  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R9]);
+		output_log(_T("r10 = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R10]);
+		output_log(_T("FP  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_FP]);
+		output_log(_T("IP  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_R12]);
+		output_log(_T("SP  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_SP]);
+		output_log(_T("LR  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_LR]);
+		output_log(_T("PC  = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_PC]);
+		output_log(_T("CPSR = 0x%08x\n"), ucontext->uc_mcontext.__gregs[_REG_CPSR]);
+		output_log(_T("Trap no = 0x%08x\n"), info->si_errno);
+		output_log(_T("Err Code = 0x%08x\n"), info->si_code);
+		output_log(_T("Old Mask = 0x%08x\n"), ucontext->uc_sigmask.__bits[0]);
+		output_log(_T("Fault Address = 0x%08x\n"), (unsigned int)info->si_addr);
+	#else
+		output_log(_T("r0  = 0x%08x\n"), ucontext->uc_mcontext.arm_r0);
+		output_log(_T("r1  = 0x%08x\n"), ucontext->uc_mcontext.arm_r1);
+		output_log(_T("r2  = 0x%08x\n"), ucontext->uc_mcontext.arm_r2);
+		output_log(_T("r3  = 0x%08x\n"), ucontext->uc_mcontext.arm_r3);
+		output_log(_T("r4  = 0x%08x\n"), ucontext->uc_mcontext.arm_r4);
+		output_log(_T("r5  = 0x%08x\n"), ucontext->uc_mcontext.arm_r5);
+		output_log(_T("r6  = 0x%08x\n"), ucontext->uc_mcontext.arm_r6);
+		output_log(_T("r7  = 0x%08x\n"), ucontext->uc_mcontext.arm_r7);
+		output_log(_T("r8  = 0x%08x\n"), ucontext->uc_mcontext.arm_r8);
+		output_log(_T("r9  = 0x%08x\n"), ucontext->uc_mcontext.arm_r9);
+		output_log(_T("r10 = 0x%08x\n"), ucontext->uc_mcontext.arm_r10);
+		output_log(_T("FP  = 0x%08x\n"), ucontext->uc_mcontext.arm_fp);
+		output_log(_T("IP  = 0x%08x\n"), ucontext->uc_mcontext.arm_ip);
+		output_log(_T("SP  = 0x%08x\n"), ucontext->uc_mcontext.arm_sp);
+		output_log(_T("LR  = 0x%08x\n"), ucontext->uc_mcontext.arm_lr);
+		output_log(_T("PC  = 0x%08x\n"), ucontext->uc_mcontext.arm_pc);
+		output_log(_T("CPSR = 0x%08x\n"), ucontext->uc_mcontext.arm_cpsr);
+		output_log(_T("Trap no = 0x%08x\n"), ucontext->uc_mcontext.trap_no);
+		output_log(_T("Err Code = 0x%08x\n"), ucontext->uc_mcontext.error_code);
+		output_log(_T("Old Mask = 0x%08x\n"), ucontext->uc_mcontext.oldmask);
+		output_log(_T("Fault Address = 0x%08x\n"), ucontext->uc_mcontext.fault_address);
+	#endif
 
-	void* getaddr = (void*)ucontext->uc_mcontext.arm_lr;
+	#if defined(__FreeBSD__) && defined(CPU_arm) && !defined(CPU_AARCH64)
+		void* getaddr = (void*)ucontext->uc_mcontext.__gregs[_REG_LR];
+	#else
+		void* getaddr = (void*)ucontext->uc_mcontext.arm_lr;
+	#endif
 	if (dladdr(getaddr, &dlinfo))
 		output_log(_T("LR - 0x%08X: <%s> (%s)\n"), getaddr, dlinfo.dli_sname, dlinfo.dli_fname);
 	else
