Fully define all the registers needed on mips.

Index: js/src/wasm/WasmSignalHandlers.cpp
--- js/src/wasm/WasmSignalHandlers.cpp.orig	2022-03-30 19:25:42 UTC
+++ js/src/wasm/WasmSignalHandlers.cpp
@@ -102,6 +102,8 @@ using mozilla::DebugOnly;
 #  if defined(__mips__)
 #    define EPC_sig(p) ((p)->sc_pc)
 #    define RFP_sig(p) ((p)->sc_regs[30])
+#    define RSP_sig(p) ((p)->sc_regs[29])
+#    define R31_sig(p) ((p)->sc_regs[31])
 #  endif
 #  if defined(__ppc64__) || defined(__PPC64__) || defined(__ppc64le__) || \
       defined(__PPC64LE__)
