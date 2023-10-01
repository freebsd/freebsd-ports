--- mono/mini/exceptions-ppc.c.orig	2023-09-30 21:55:09 UTC
+++ mono/mini/exceptions-ppc.c
@@ -795,11 +795,11 @@ mono_arch_setup_async_callback (MonoContext *ctx, void
 mono_arch_setup_async_callback (MonoContext *ctx, void (*async_cb)(void *fun), gpointer user_data)
 {
 	uintptr_t sp = (uintptr_t) MONO_CONTEXT_GET_SP(ctx);
-	ctx->regs [PPC_FIRST_ARG_REG] = user_data;
+	ctx->regs [PPC_FIRST_ARG_REG] = (host_mgreg_t)user_data;
 	sp -= PPC_MINIMAL_STACK_SIZE;
-	*(unsigned long *)sp = MONO_CONTEXT_GET_SP(ctx);
+	*(unsigned long *)sp = (uintptr_t)MONO_CONTEXT_GET_SP(ctx);
 	MONO_CONTEXT_SET_BP(ctx, sp);
-	mono_arch_setup_resume_sighandler_ctx(ctx, (unsigned long) async_cb);
+	mono_arch_setup_resume_sighandler_ctx(ctx, (gpointer) async_cb);
 }
 
 void
