--- src/cli.c.orig	2022-08-22 11:18:44 UTC
+++ src/cli.c
@@ -867,6 +867,8 @@ cli_ldflags(int argc, char **argv)
 	cli_kore_load_file("linker", NULL, &p, &len);
 	printf("%.*s ", (int)len, p);
 
+	printf("-I%%OPENSSLINC%% ");
+
 #if defined(__MACH__)
 	printf("-dynamiclib -undefined suppress -flat_namespace ");
 #else
