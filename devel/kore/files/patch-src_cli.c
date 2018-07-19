--- src/cli.c.orig	2018-07-18 14:25:49 UTC
+++ src/cli.c
@@ -1838,6 +1838,9 @@ cli_build_flags_common(struct buildopt *bopt, struct c
 	else
 		cli_buf_appendf(buf, "-I%s/include ", bopt->kore_source);
 
+
+	cli_buf_appendf(buf, "-I/usr/local/include ");
+	cli_buf_appendf(buf, "-I%s/include/kore ", PREFIX);
 #if defined(__MACH__)
 	/* Add default openssl include path from homebrew / ports under OSX. */
 	cli_buf_appendf(buf, "-I/opt/local/include ");
