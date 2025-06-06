--- src/manage.c.orig	2025-06-06 18:09:24 UTC
+++ src/manage.c
@@ -403,7 +403,7 @@ void pal_manage(void)
     rl_initialize();     /* Initialise readline so we can fiddle stuff */
     rl_already_prompted = 1;
     rl_redisplay_function = pal_rl_ncurses_hack;
-    rl_pre_input_hook = (Function*) pal_rl_ncurses_hack;
+    rl_pre_input_hook = (rl_hook_func_t *) pal_rl_ncurses_hack;
 
 
     /* initialize curses */
