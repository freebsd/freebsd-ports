--- assa/Handlers.h.orig	Wed Dec 24 17:02:53 2003
+++ assa/Handlers.h	Wed Dec 24 17:22:41 2003
@@ -256,7 +256,7 @@
 	int handle_signal ( int signum_ ) { 
 		trace_with_mask("SIGPOLLHandler::handle_signal", SIGHAND);
 			
-		return (signum_ == SIGPOLL) ? 0 : -1; 
+		return (signum_ == SIGIO) ? 0 : -1; 
 	}
 };
 
