--- ext/readline/extconf.rb.orig	2015-12-16 05:31:54 UTC
+++ ext/readline/extconf.rb
@@ -64,7 +64,7 @@ else
 end
 
 readline.have_func("rl_getc")
-readline.have_func("rl_getc_function")
+#readline.have_func("rl_getc_function")
 readline.have_func("rl_filename_completion_function")
 readline.have_func("rl_username_completion_function")
 readline.have_func("rl_completion_matches")
