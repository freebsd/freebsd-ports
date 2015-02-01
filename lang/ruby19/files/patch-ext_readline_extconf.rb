--- ext/readline/extconf.rb.orig	2012-09-09 06:44:20 UTC
+++ ext/readline/extconf.rb
@@ -62,7 +62,7 @@ else
 end
 
 have_readline_func("rl_getc")
-have_readline_func("rl_getc_function")
+#have_readline_func("rl_getc_function")
 have_readline_func("rl_filename_completion_function")
 have_readline_func("rl_username_completion_function")
 have_readline_func("rl_completion_matches")
