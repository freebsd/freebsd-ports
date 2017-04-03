--- ext/readline/extconf.rb.orig	2015-12-01 18:28:54 UTC
+++ ext/readline/extconf.rb
@@ -63,7 +63,7 @@ else
 end
 
 readline.have_func("rl_getc")
-readline.have_func("rl_getc_function")
+#readline.have_func("rl_getc_function")
 readline.have_func("rl_filename_completion_function")
 readline.have_func("rl_username_completion_function")
 readline.have_func("rl_completion_matches")
