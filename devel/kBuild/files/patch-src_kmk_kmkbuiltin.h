--- src/kmk/kmkbuiltin.h.orig	2012-07-17 22:30:15 UTC
+++ src/kmk/kmkbuiltin.h
@@ -50,7 +50,11 @@ extern int kmk_builtin_printf(int argc, 
 extern int kmk_builtin_rm(int argc, char **argv, char **envp);
 extern int kmk_builtin_rmdir(int argc, char **argv, char **envp);
 extern int kmk_builtin_sleep(int argc, char **argv, char **envp);
-extern int kmk_builtin_test(int argc, char **argv, char **envp, char ***ppapszArgvSpawn);
+extern int kmk_builtin_test(int argc, char **argv, char **envp
+#ifndef kmk_builtin_test
+			   , char ***ppapszArgvSpawn
+#endif
+			   );
 extern int kmk_builtin_kDepIDB(int argc, char **argv, char **envp);
 extern int kmk_builtin_kDepObj(int argc, char **argv, char **envp);
 
