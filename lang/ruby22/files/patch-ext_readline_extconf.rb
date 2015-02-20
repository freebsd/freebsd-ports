--- ext/readline/extconf.rb.orig	2015-01-16 23:05:12 UTC
+++ ext/readline/extconf.rb
@@ -62,7 +62,7 @@ else
 end
 
 readline.have_func("rl_getc")
-readline.have_func("rl_getc_function")
+#readline.have_func("rl_getc_function")
 readline.have_func("rl_filename_completion_function")
 readline.have_func("rl_username_completion_function")
 readline.have_func("rl_completion_matches")
