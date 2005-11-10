--- mono/mini/exceptions-amd64.c.orig	Tue Aug  2 17:53:06 2005
+++ mono/mini/exceptions-amd64.c	Tue Aug  2 17:53:20 2005
@@ -573,11 +573,27 @@
  * @obj: the exception object
  */
 gboolean
-mono_arch_handle_exception (void *sigctx, gpointer obj, gboolean test_only)
+mono_arch_handle_exception (void *sigctx, gpointer obj,	gboolean test_only)
 {
-	ucontext_t *ctx = (ucontext_t*)sigctx;
-	MonoContext mctx;
+	ucontext_t *ctx	= (ucontext_t*)sigctx;
+	MonoContext	mctx;
 
+#if	defined(__FreeBSD__)
+    guint64 *gregs = (guint64 *) &ctx->uc_mcontext;
+	mctx.rax = gregs [REG_RAX];
+	mctx.rbx = gregs [REG_RBX];
+	mctx.rcx = gregs [REG_RCX];
+	mctx.rdx = gregs [REG_RDX];
+	mctx.rbp = gregs [REG_RBP];
+	mctx.rsp = gregs [REG_RSP];
+	mctx.rsi = gregs [REG_RSI];
+	mctx.rdi = gregs [REG_RDI];
+	mctx.rip = gregs [REG_RIP];
+	mctx.r12 = gregs [REG_R12];
+	mctx.r13 = gregs [REG_R13];
+	mctx.r14 = gregs [REG_R14];
+	mctx.r15 = gregs [REG_R15];
+#else
 	mctx.rax = ctx->uc_mcontext.gregs [REG_RAX];
 	mctx.rbx = ctx->uc_mcontext.gregs [REG_RBX];
 	mctx.rcx = ctx->uc_mcontext.gregs [REG_RCX];
@@ -591,9 +607,25 @@
 	mctx.r13 = ctx->uc_mcontext.gregs [REG_R13];
 	mctx.r14 = ctx->uc_mcontext.gregs [REG_R14];
 	mctx.r15 = ctx->uc_mcontext.gregs [REG_R15];
+#endif
 
 	mono_handle_exception (&mctx, obj, (gpointer)mctx.rip, test_only);
 
+#if	defined(__FreeBSD__)
+	gregs [REG_RAX] = mctx.rax;
+	gregs [REG_RBX] = mctx.rbx;
+	gregs [REG_RCX] = mctx.rcx;
+	gregs [REG_RDX] = mctx.rdx;
+	gregs [REG_RBP] = mctx.rbp;
+	gregs [REG_RSP] = mctx.rsp;
+	gregs [REG_RSI] = mctx.rsi;
+	gregs [REG_RDI] = mctx.rdi;
+	gregs [REG_RIP] = mctx.rip;
+	gregs [REG_R12] = mctx.r12;
+	gregs [REG_R13] = mctx.r13;
+	gregs [REG_R14] = mctx.r14;
+	gregs [REG_R15] = mctx.r15;
+#else
 	ctx->uc_mcontext.gregs [REG_RAX] = mctx.rax;
 	ctx->uc_mcontext.gregs [REG_RBX] = mctx.rbx;
 	ctx->uc_mcontext.gregs [REG_RCX] = mctx.rcx;
@@ -607,14 +639,20 @@
 	ctx->uc_mcontext.gregs [REG_R13] = mctx.r13;
 	ctx->uc_mcontext.gregs [REG_R14] = mctx.r14;
 	ctx->uc_mcontext.gregs [REG_R15] = mctx.r15;
+#endif
 
 	return TRUE;
 }
 
 gpointer
-mono_arch_ip_from_context (void *sigctx)
+mono_arch_ip_from_context (void	*sigctx)
 {
-	ucontext_t *ctx = (ucontext_t*)sigctx;
-	return (gpointer)ctx->uc_mcontext.gregs [REG_RIP];
+	ucontext_t *ctx	= (ucontext_t*)sigctx;
+#if	defined(__FreeBSD__)
+    __register_t *gregs = (__register_t *) &ctx->uc_mcontext;
+	return (gpointer)gregs[REG_RIP];
+#else
+	return (gpointer)ctx->uc_mcontext.gregs	[REG_RIP];
+#endif
 }
 
