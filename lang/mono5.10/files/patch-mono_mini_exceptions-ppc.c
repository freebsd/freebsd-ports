--- mono/mini/exceptions-ppc.c.orig	2023-03-18 12:46:51 UTC
+++ mono/mini/exceptions-ppc.c
@@ -809,7 +809,7 @@ mono_arch_setup_async_callback (MonoContext *ctx, void
 {
 	uintptr_t sp = (uintptr_t) MONO_CONTEXT_GET_SP(ctx);
 	sp -= PPC_MINIMAL_STACK_SIZE;
-	*(unsigned long *)sp = MONO_CONTEXT_GET_SP(ctx);
+	*(unsigned long *)sp = (unsigned long)MONO_CONTEXT_GET_SP(ctx);
 	MONO_CONTEXT_SET_BP(ctx, sp);
 	MONO_CONTEXT_SET_IP(ctx, (unsigned long) async_cb);
 }
