Index: trunk/ext/readline/readline.c
===================================================================
--- ext/readline/readline.c	(revision 24139)
+++ ext/readline/readline.c	(revision 24140)
@@ -253,6 +253,7 @@
     if (status) {
 #if defined HAVE_RL_CLEANUP_AFTER_SIGNAL
         /* restore terminal mode and signal handler*/
+        rl_free_line_state();
         rl_cleanup_after_signal();
 #elif defined HAVE_RL_DEPREP_TERM_FUNCTION
         /* restore terminal mode */
@@ -1450,6 +1451,8 @@
 #elif defined HAVE_RL_EVENT_HOOK
     rl_event_hook = readline_event;
 #endif
+    rl_catch_signals = 0;
+    rl_catch_sigwinch = 0;
 #ifdef HAVE_RL_CLEAR_SIGNALS
     rl_clear_signals();
 #endif
