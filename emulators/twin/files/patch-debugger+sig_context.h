$NetBSD: patch-ae,v 1.1.1.1 2001/05/15 09:46:37 agc Exp $

--- debugger/sig_context.h.orig	Sun May 13 03:01:07 2001
+++ debugger/sig_context.h	Sun May 13 03:25:31 2001
@@ -59,6 +59,20 @@
 
 #if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
+enum {
+    REG_GS = 0, REG_FS, REG_ES, REG_DS,
+    REG_EDI, REG_ESI, REG_EBP,
+    REG_EBX, REG_EDX, REG_ECX, REG_EAX,
+    REG_EIP, REG_CS, REG_EFL, REG_ESP,
+    REG_SS, REG_BSD_ONSTACK, REG_BSD_MASK13,
+    REG_TRAPNO, REG_ERR,
+
+    REG_AX = 100, REG_BX, REG_CX, REG_DX,
+    REG_BP, REG_IP, REG_SP,
+    REG_DI, REG_SI,
+    REG_FL
+};
+
 #include <signal.h>
 typedef struct sigcontext SIGCONTEXT;
 
