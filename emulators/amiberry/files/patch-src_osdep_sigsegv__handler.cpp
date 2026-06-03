--- src/osdep/sigsegv_handler.cpp.orig	2026-04-26 06:59:39 UTC
+++ src/osdep/sigsegv_handler.cpp
@@ -63,6 +63,9 @@ void init_max_signals()
 #else
 #include <sys/ucontext.h>
 #endif
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+#include <machine/ucontext.h>
+#endif
 #include <csignal>
 #include <dlfcn.h>
 
@@ -154,8 +157,10 @@ static int handle_exception(mcontext_t sigcont, long f
 #endif
 {
 	int handled = HANDLE_EXCEPTION_NONE;
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+	auto fault_pc = static_cast<uintptr>(sigcont->mc_gpregs.gp_elr);
+#elif !defined(__MACH__)
 // Mac OS X struct for this is different
-#ifndef __MACH__
 	auto fault_pc = static_cast<uintptr>(sigcont->pc);
 #else
 	auto fault_pc = static_cast<uintptr>(sigcont->__ss.__pc);
@@ -199,7 +204,9 @@ static int handle_exception(mcontext_t sigcont, long f
 		// Check for stupid RAM detection of kickstart
 		if (a3000lmem_bank.allocated_size > 0 && amiga_addr >= a3000lmem_bank.start - 0x00100000 && amiga_addr < a3000lmem_bank.start - 0x00100000 + 8) {
 			output_log(_T("  Stupid kickstart detection for size of ramsey_low at 0x%08x.\n"), amiga_addr);
-#ifndef __MACH__
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+			sigcont->mc_gpregs.gp_elr += 4;
+#elif !defined(__MACH__)
 			sigcont->pc += 4;
 #else
 			sigcont->__ss.__pc += 4;
@@ -211,7 +218,9 @@ static int handle_exception(mcontext_t sigcont, long f
 		// Check for stupid RAM detection of kickstart
 		if (a3000hmem_bank.allocated_size > 0 && amiga_addr >= a3000hmem_bank.start + a3000hmem_bank.allocated_size && amiga_addr < a3000hmem_bank.start + a3000hmem_bank.allocated_size + 8) {
 			output_log(_T("  Stupid kickstart detection for size of ramsey_high at 0x%08x.\n"), amiga_addr);
-#ifndef __MACH__
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+			sigcont->mc_gpregs.gp_elr += 4;
+#elif !defined(__MACH__)
 			sigcont->pc += 4;
 #else
 			sigcont->__ss.__pc += 4;
@@ -241,43 +250,58 @@ static int handle_exception(mcontext_t sigcont, long f
 		transfer_type_t transfer_type = TYPE_UNKNOWN;
 		int transfer_size = SIZE_UNKNOWN;
 
-			const auto get_reg_w = [&](const int reg) -> uae_u32 {
-				if (reg == 31)
-					return 0;
-#ifndef __MACH__
-				return static_cast<uae_u32>(sigcont->regs[reg]);
+				const auto get_reg_w = [&](const int reg) -> uae_u32 {
+					if (reg == 31)
+						return 0;
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+					if (reg < 30)
+						return static_cast<uae_u32>(sigcont->mc_gpregs.gp_x[reg]);
+					return static_cast<uae_u32>(sigcont->mc_gpregs.gp_lr);
+#elif !defined(__MACH__)
+					return static_cast<uae_u32>(sigcont->regs[reg]);
 #else
-				return static_cast<uae_u32>(sigcont->__ss.__x[reg]);
+					return static_cast<uae_u32>(sigcont->__ss.__x[reg]);
 #endif
-			};
-			const auto get_reg_x = [&](const int reg) -> uae_u64 {
-				if (reg == 31)
-					return 0;
-#ifndef __MACH__
-				return static_cast<uae_u64>(sigcont->regs[reg]);
+				};
+				const auto get_reg_x = [&](const int reg) -> uae_u64 {
+					if (reg == 31)
+						return 0;
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+					if (reg < 30)
+						return static_cast<uae_u64>(sigcont->mc_gpregs.gp_x[reg]);
+					return static_cast<uae_u64>(sigcont->mc_gpregs.gp_lr);
+#elif !defined(__MACH__)
+					return static_cast<uae_u64>(sigcont->regs[reg]);
 #else
-				return static_cast<uae_u64>(sigcont->__ss.__x[reg]);
+					return static_cast<uae_u64>(sigcont->__ss.__x[reg]);
 #endif
-			};
-			const auto get_base_x = [&](const int reg) -> uae_u64 {
-				if (reg == 31) {
-#ifndef __MACH__
-					return static_cast<uae_u64>(sigcont->sp);
+				};
+				const auto get_base_x = [&](const int reg) -> uae_u64 {
+					if (reg == 31) {
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+						return static_cast<uae_u64>(sigcont->mc_gpregs.gp_sp);
+#elif !defined(__MACH__)
+						return static_cast<uae_u64>(sigcont->sp);
 #else
-					return static_cast<uae_u64>(sigcont->__ss.__sp);
+						return static_cast<uae_u64>(sigcont->__ss.__sp);
 #endif
-				}
-				return get_reg_x(reg);
-			};
-			const auto set_reg_w = [&](const int reg, const uae_u32 value) {
-				if (reg == 31)
-					return;
-#ifndef __MACH__
-				sigcont->regs[reg] = value;
+					}
+					return get_reg_x(reg);
+				};
+				const auto set_reg_w = [&](const int reg, const uae_u32 value) {
+					if (reg == 31)
+						return;
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+					if (reg < 30)
+						sigcont->mc_gpregs.gp_x[reg] = value;
+					else
+						sigcont->mc_gpregs.gp_lr = value;
+#elif !defined(__MACH__)
+					sigcont->regs[reg] = value;
 #else
-				sigcont->__ss.__x[reg] = value;
+					sigcont->__ss.__x[reg] = value;
 #endif
-			};
+				};
 
 			// Decode memory operands for additional diagnostics.
 			const int rd = opcode & 0x1f;
@@ -489,7 +513,9 @@ static int handle_exception(mcontext_t sigcont, long f
 				}
 
 				// Go to next instruction
-#ifndef __MACH__
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+				sigcont->mc_gpregs.gp_elr += 4;
+#elif !defined(__MACH__)
 				sigcont->pc += 4;
 #else
 				sigcont->__ss.__pc += 4;
@@ -557,10 +583,14 @@ void signal_segv(int signum, siginfo_t* info, void* pt
 
 #ifndef __MACH__
 	mcontext_t* context = &(ucontext->uc_mcontext);
-	unsigned long long* regs = context->regs;
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+	[[maybe_unused]] unsigned long long* regs = reinterpret_cast<unsigned long long*>(context->mc_gpregs.gp_x);
 #else
+	[[maybe_unused]] unsigned long long* regs = context->regs;
+#endif
+#else
 	mcontext_t context = ucontext->uc_mcontext;
-	unsigned long long* regs = context->__ss.__x;
+	[[maybe_unused]] unsigned long long* regs = context->__ss.__x;
 #endif
 
 	const auto addr = reinterpret_cast<uintptr>(info->si_addr);
@@ -585,13 +615,24 @@ void signal_segv(int signum, siginfo_t* info, void* pt
 			if (signum == 4)
 				output_log(_T("       value = 0x%08x\n"), *static_cast<uae_u32*>(info->si_addr));
 
-		for (int i = 0; i < 31; ++i)
-#ifndef __MACH__
-			output_log(_T("x%02d  = 0x%016llx\n"), i, ucontext->uc_mcontext.regs[i]);
-#else
-			output_log(_T("x%02d  = 0x%016llx\n"), i, context->__ss.__x[i]);
-#endif
-#ifndef __MACH__
+	#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+			for (int i = 0; i < 30; ++i)
+				output_log(_T("x%02d  = 0x%016llx\n"), i, ucontext->uc_mcontext.mc_gpregs.gp_x[i]);
+			output_log(_T("x30  = 0x%016llx\n"), ucontext->uc_mcontext.mc_gpregs.gp_lr);
+	#elif !defined(__MACH__)
+			for (int i = 0; i < 31; ++i)
+				output_log(_T("x%02d  = 0x%016llx\n"), i, ucontext->uc_mcontext.regs[i]);
+	#else
+			for (int i = 0; i < 31; ++i)
+				output_log(_T("x%02d  = 0x%016llx\n"), i, context->__ss.__x[i]);
+	#endif
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+		output_log(_T("SP  = 0x%016llx\n"), ucontext->uc_mcontext.mc_gpregs.gp_sp);
+		output_log(_T("PC  = 0x%016llx\n"), ucontext->uc_mcontext.mc_gpregs.gp_elr);
+		output_log(_T("Fault Address = 0x%016llx\n"), static_cast<unsigned long long>(reinterpret_cast<uintptr_t>(info->si_addr)));
+		output_log(_T("SPSR  = 0x%016llx\n"), static_cast<unsigned long long>(ucontext->uc_mcontext.mc_gpregs.gp_spsr));
+		void* getaddr = reinterpret_cast<void*>(ucontext->uc_mcontext.mc_gpregs.gp_lr);
+#elif !defined(__MACH__)
 		output_log(_T("SP  = 0x%016llx\n"), ucontext->uc_mcontext.sp);
 		output_log(_T("PC  = 0x%016llx\n"), ucontext->uc_mcontext.pc);
 		output_log(_T("Fault Address = 0x%016llx\n"), ucontext->uc_mcontext.fault_address);
@@ -672,10 +713,14 @@ void signal_buserror(int signum, siginfo_t* info, void
 
 #ifndef __MACH__
 	mcontext_t* context = &(ucontext->uc_mcontext);
-	unsigned long long* regs = context->regs;
+#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+	[[maybe_unused]] unsigned long long* regs = reinterpret_cast<unsigned long long*>(context->mc_gpregs.gp_x);
 #else
+	[[maybe_unused]] unsigned long long* regs = context->regs;
+#endif
+#else
 	mcontext_t context = ucontext->uc_mcontext;
-	unsigned long long* regs = context->__ss.__x;
+	[[maybe_unused]] unsigned long long* regs = context->__ss.__x;
 #endif
 
 	auto addr = reinterpret_cast<uintptr_t>(info->si_addr);
@@ -695,8 +740,17 @@ void signal_buserror(int signum, siginfo_t* info, void
 		if (signum == 4)
 			output_log(_T("       value = 0x%08x\n"), *static_cast<uae_u32*>(info->si_addr));
 
+	#if defined(__FreeBSD__) && defined(CPU_AARCH64)
+	for (int i = 0; i < 30; ++i)
+		output_log(_T("x%02d  = 0x%016llx\n"), i, ucontext->uc_mcontext.mc_gpregs.gp_x[i]);
+	output_log(_T("x30  = 0x%016llx\n"), ucontext->uc_mcontext.mc_gpregs.gp_lr);
+	output_log(_T("SP  = 0x%016llx\n"), ucontext->uc_mcontext.mc_gpregs.gp_sp);
+	output_log(_T("PC  = 0x%016llx\n"), ucontext->uc_mcontext.mc_gpregs.gp_elr);
+	output_log(_T("Fault Address = 0x%016llx\n"), static_cast<unsigned long long>(reinterpret_cast<uintptr_t>(info->si_addr)));
+	output_log(_T("SPSR  = 0x%016llx\n"), static_cast<unsigned long long>(ucontext->uc_mcontext.mc_gpregs.gp_spsr));
+	void* getaddr = reinterpret_cast<void*>(ucontext->uc_mcontext.mc_gpregs.gp_lr);
+	#elif !defined(__MACH__)
 	for (int i = 0; i < 31; ++i)
-#ifndef __MACH__
 		output_log(_T("x%02d  = 0x%016llx\n"), i, ucontext->uc_mcontext.regs[i]);
 	output_log(_T("SP  = 0x%016llx\n"), ucontext->uc_mcontext.sp);
 	output_log(_T("PC  = 0x%016llx\n"), ucontext->uc_mcontext.pc);
@@ -704,7 +758,8 @@ void signal_buserror(int signum, siginfo_t* info, void
 	output_log(_T("pstate  = 0x%016llx\n"), ucontext->uc_mcontext.pstate);
 
 	void* getaddr = (void*)ucontext->uc_mcontext.regs[30];
-#else
+	#else
+	for (int i = 0; i < 31; ++i)
 		output_log(_T("x%02d  = 0x%016llx\n"), i, context->__ss.__x[i]);
 	output_log(_T("SP  = 0x%016llx\n"), context->__ss.__sp);
 	output_log(_T("PC  = 0x%016llx\n"), context->__ss.__pc);
