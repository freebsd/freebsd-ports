--- ext/standard/basic_functions.c.orig	Fri Nov  4 09:30:04 2005
+++ ext/standard/basic_functions.c	Fri Nov  4 09:30:56 2005
@@ -802,8 +802,8 @@
 	PHP_FE(prev,					first_arg_force_ref)
 	PHP_FE(next,					first_arg_force_ref)
 	PHP_FE(reset,					first_arg_force_ref)
-	PHP_FE(current,					NULL)
-	PHP_FE(key,					NULL)
+	PHP_FE(current,					first_arg_force_ref)
+	PHP_FE(key,					first_arg_force_ref)
 	PHP_FE(min,																NULL)
 	PHP_FE(max,																NULL)
 	PHP_FE(in_array,														NULL)
