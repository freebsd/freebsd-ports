--- src/server/server.c.orig	2025-09-13 12:06:50 UTC
+++ src/server/server.c
@@ -604,7 +604,7 @@ static void sig_handler(int sig)
 	/* store only first signal that hits us */
 	if (shutdown_openocd == CONTINUE_MAIN_LOOP) {
 		shutdown_openocd = SHUTDOWN_WITH_SIGNAL_CODE;
-		assert(sig >= SIG_ATOMIC_MIN && sig <= SIG_ATOMIC_MAX);
+		//assert(sig >= SIG_ATOMIC_MIN && sig <= SIG_ATOMIC_MAX);
 		last_signal = sig;
 		LOG_DEBUG("Terminating on Signal %d", sig);
 	} else
