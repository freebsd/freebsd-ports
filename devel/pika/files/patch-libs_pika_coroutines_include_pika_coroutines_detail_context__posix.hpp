--- libs/pika/coroutines/include/pika/coroutines/detail/context_posix.hpp.orig	2022-07-13 00:14:36 UTC
+++ libs/pika/coroutines/include/pika/coroutines/detail/context_posix.hpp
@@ -143,7 +143,7 @@ namespace pika::threads::coroutines::detail::posix::uc
         ctx->uc_stack.ss_size = size;
         ctx->uc_link = exitto;
 
-        using = void (*ctx_main)();
+        using ctx_main = void (*)();
         //makecontext can't fail.
         ::makecontext(ctx, (ctx_main) (startfunc), 1, startarg);
         return 0;
