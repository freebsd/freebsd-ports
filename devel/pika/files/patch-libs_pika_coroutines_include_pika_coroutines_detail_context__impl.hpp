--- libs/pika/coroutines/include/pika/coroutines/detail/context_impl.hpp.orig	2023-03-08 10:50:55 UTC
+++ libs/pika/coroutines/include/pika/coroutines/detail/context_impl.hpp
@@ -110,7 +110,7 @@ namespace pika { namespace threads { namespace corouti
     using default_context_impl = generic_context::fcontext_context_impl<CoroutineImpl>;
 }}}}    // namespace pika::threads::coroutines::detail
 
-#elif (defined(__linux) || defined(linux) || defined(__linux__)) && !defined(__bgq__) &&           \
+#elif (defined(__linux) || defined(linux) || defined(__linux__) || defined(__FreeBSD__)) && !defined(__bgq__) &&           \
     !defined(__powerpc__) && !defined(__s390x__) && !defined(__arm__) && !defined(arm64) &&        \
     !defined(__arm64) && !defined(__arm64__) && !defined(__aarch64__)
 
