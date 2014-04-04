--- a/bsd-user/mips/target_arch_vmparam.h
+++ b/bsd-user/mips/target_arch_vmparam.h
@@ -35,7 +35,8 @@
 #define TARGET_VM_MINUSER_ADDRESS   (0x00000000)
 #define TARGET_VM_MAXUSER_ADDRESS   (0x80000000)
 
-#define TARGET_USRSTACK (TARGET_VM_MAXUSER_ADDRESS - TARGET_PAGE_SIZE)
+// #define TARGET_USRSTACK (TARGET_VM_MAXUSER_ADDRESS - TARGET_PAGE_SIZE)
+#define TARGET_USRSTACK (TARGET_RESERVED_VA - TARGET_PAGE_SIZE * 0x10)
 
 static inline abi_ulong get_sp_from_cpustate(CPUMIPSState *state)
 {
