--- mono/mini/mini-amd64.h.orig	Tue Aug  2 17:52:47 2005
+++ mono/mini/mini-amd64.h	Tue Aug  2 17:53:40 2005
@@ -130,7 +130,7 @@
 	guint64 r15;
 } MonoContext;
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+/*#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 # define SC_EAX sc_eax
 # define SC_EBX sc_ebx
 # define SC_ECX sc_ecx
@@ -140,7 +140,7 @@
 # define SC_ESP sc_esp
 # define SC_EDI sc_edi
 # define SC_ESI sc_esi
-#else
+#else*/
 # define SC_EAX rax
 # define SC_EBX rbx
 # define SC_ECX rcx
@@ -160,7 +160,7 @@
 # define SC_R14 r14
 # define SC_R15 r15
 
-#endif
+//#endif
 
 #define MONO_CONTEXT_SET_IP(ctx,ip) do { (ctx)->rip = (long)(ip); } while (0); 
 #define MONO_CONTEXT_SET_BP(ctx,bp) do { (ctx)->rbp = (long)(bp); } while (0); 
@@ -215,6 +215,29 @@
 
 gboolean
 mono_amd64_is_sse2 (void);
+
+
+#ifdef __FreeBSD__
+
+#define REG_RAX 7
+#define REG_RCX 4
+#define REG_RDX 3
+#define REG_RBX 8
+#define REG_RSP 23
+#define REG_RBP 9
+#define REG_RSI 2
+#define REG_RDI 1
+#define REG_R8  5
+#define REG_R9  6
+#define REG_R10 10
+#define REG_R11 11
+#define REG_R12 12
+#define REG_R13 13
+#define REG_R14 14
+#define REG_R15 15
+#define REG_RIP 20
+
+#endif // __FreeBSD__
 
 #endif /* __MONO_MINI_AMD64_H__ */  
 
