--- manage.c.orig	2008-07-28 16:16:23.000000000 +0000
+++ manage.c
@@ -403,7 +403,7 @@ void pal_manage(void)
     rl_initialize();     /* Initialise readline so we can fiddle stuff */
     rl_already_prompted = 1;
     rl_redisplay_function = pal_rl_ncurses_hack;
-    rl_pre_input_hook = (Function*) pal_rl_ncurses_hack;
+    rl_pre_input_hook = (rl_hook_func_t *) pal_rl_ncurses_hack;
 
 
     /* initialize curses */
