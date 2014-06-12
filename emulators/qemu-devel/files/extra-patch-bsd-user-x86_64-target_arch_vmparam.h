From nox Mon Sep 17 00:00:00 2001
From: Juergen Lock <nox@jelal.kn-bremen.de>
Date: 12 Jun 2014 19:55:52 +0200
Subject: Fix bsd-user x86_64 target failing with stk mmap: Invalid argument

Signed-off-by: Juergen Lock <nox@jelal.kn-bremen.de>

--- a/bsd-user/x86_64/target_arch_vmparam.h
+++ b/bsd-user/x86_64/target_arch_vmparam.h
@@ -11,7 +11,8 @@
 #define TARGET_MAXSSIZ  (512UL*1024*1024)   /* max stack size */
 #define TARGET_SGROWSIZ (128UL*1024)        /* amount to grow stack */
 
-#define TARGET_VM_MAXUSER_ADDRESS   (0x0000800000000000UL)
+/* #define TARGET_VM_MAXUSER_ADDRESS   (0x0000800000000000UL) */
+#define TARGET_VM_MAXUSER_ADDRESS   (0x00007fffff000000UL)
 
 #define TARGET_USRSTACK (TARGET_VM_MAXUSER_ADDRESS - TARGET_PAGE_SIZE)
 
