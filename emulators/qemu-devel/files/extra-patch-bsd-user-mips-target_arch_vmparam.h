From nox Mon Sep 17 00:00:00 2001
From: Juergen Lock <nox@jelal.kn-bremen.de>
Date: 04 Apr 2014 02:09:00 +0200
Subject: Lower 32bit mips TARGET_USRSTACK

Lower 32bit mips TARGET_USRSTACK to fix an assert starting mips-bsd-user
processes on 64bit hosts. (like amd64)

Signed-off-by: Juergen Lock <nox@jelal.kn-bremen.de>

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
