--- ./gdb/tui/tui-io.c.orig     2013-12-08 04:33:14.000000000 +0000
+++ ./gdb/tui/tui-io.c  2014-03-01 22:20:33.000000000 +0000
@@ -128,10 +128,10 @@
 struct ui_out *tui_old_uiout;
 
 /* Readline previous hooks.  */
-static Function *tui_old_rl_getc_function;
-static VFunction *tui_old_rl_redisplay_function;
-static VFunction *tui_old_rl_prep_terminal;
-static VFunction *tui_old_rl_deprep_terminal;
+static rl_getc_func_t *tui_old_rl_getc_function;
+static rl_voidfunc_t *tui_old_rl_redisplay_function;
+static rl_voidfunc_t *tui_old_rl_prep_terminal;
+static rl_voidfunc_t *tui_old_rl_deprep_terminal;
 static int tui_old_rl_echoing_p;
 
 /* Readline output stream.
