--- ./src/thread.h.orig	2007-06-11 11:16:23.000000000 -0400
+++ ./src/thread.h	2014-08-11 10:14:00.000000000 -0400
@@ -25,6 +25,7 @@
 
 #include "condvar.h"
 #include <stdexcept>
+#include <string>
 #include <stdint.h>
 
 /// base class for threads.
@@ -47,7 +48,7 @@
 	struct SDL_Thread* thread_id;
 	bool thread_abort_request;
 	thread_state_t thread_state;
-	mutex thread_state_mutex;
+	::mutex thread_state_mutex;
 	condvar thread_start_cond;
 	std::string thread_error_message; // to pass exception texts via thread boundaries
 
