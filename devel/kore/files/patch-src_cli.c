--- src/cli.c.orig	2020-08-26 07:20:35 UTC
+++ src/cli.c
@@ -1922,6 +1922,7 @@ cli_build_flags_common(struct buildopt *bopt, struct c
 	else
 		cli_buf_appendf(buf, "-I%s/include ", bopt->kore_source);
 
+	cli_buf_appendf(buf, "-I%%OPENSSLINC%% ");
 #if defined(__MACH__)
 	/* Add default openssl include path from homebrew / ports under OSX. */
 	cli_buf_appendf(buf, "-I/opt/local/include ");
