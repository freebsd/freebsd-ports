--- ext/readline/extconf.rb.orig	2014-05-01 11:59:37.000000000 +0000
+++ ext/readline/extconf.rb	2015-10-23 04:05:44.000000000 +0000
@@ -62,7 +63,7 @@ else
 end
 
 readline.have_func("rl_getc")
-readline.have_func("rl_getc_function")
+#readline.have_func("rl_getc_function")
 readline.have_func("rl_filename_completion_function")
 readline.have_func("rl_username_completion_function")
 readline.have_func("rl_completion_matches")
