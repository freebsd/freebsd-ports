--- ddd/mainloop.C.orig	2019-07-03 20:06:57 UTC
+++ ddd/mainloop.C
@@ -121,7 +121,7 @@ void ddd_main_loop()
 }
 
 // Return to DDD main loop, using longjmp()
-void goto_main_loop(int sig)
+_X_NORETURN void goto_main_loop(int sig)
 {
     longjmp(main_loop_env, sig);
 }
