--- src/cpu_generic/ppc_cpu.cc.orig	Sun Aug  1 19:42:05 2004
+++ src/cpu_generic/ppc_cpu.cc	Thu May  6 02:48:30 2004
@@ -108,7 +108,7 @@
 			ppc_debug_hook();
 		} else {
 			int ret;
+			if ((ret = ppc_direct_effective_memory_handle_code(gCPU.pc & ~0xfff, (byte *&)gCPU.physical_code_page))) {
-			if ((ret = ppc_direct_effective_memory_handle_code(gCPU.pc & ~0xfff, gCPU.physical_code_page))) {
 				if (ret == PPC_MMU_EXC) {
 					gCPU.pc = gCPU.npc;
 					continue;
