--- lib/log_utils.cpp.orig	2026-03-20 19:38:59 UTC
+++ lib/log_utils.cpp
@@ -112,7 +112,7 @@ LogBufferThreadContext::LogBufferThreadContext() : dis
 	std::seed_seq seed{
 		rd(),
 		static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count()),
-		static_cast<unsigned>(pthread_self())
+		static_cast<unsigned>(reinterpret_cast<uintptr_t>(pthread_self()))
 	};
 	rng.seed(seed);
 }
