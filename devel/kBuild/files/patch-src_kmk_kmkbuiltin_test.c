--- src/kmk/kmkbuiltin/test.c.orig	2012-07-17 22:30:16 UTC
+++ src/kmk/kmkbuiltin/test.c
@@ -201,7 +201,11 @@ extern void *xmalloc(unsigned int sz)
 }
 #endif
 
-int kmk_builtin_test(int argc, char **argv, char **envp, char ***ppapszArgvSpawn)
+int kmk_builtin_test(int argc, char **argv, char **envp
+#ifndef kmk_builtin_test
+                     , char ***ppapszArgvSpawn
+#endif
+		    )
 {
 	int res;
 	char **argv_spawn;
