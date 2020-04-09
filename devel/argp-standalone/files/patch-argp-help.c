--- argp-help.c.orig	2020-04-09 17:39:48 UTC
+++ argp-help.c
@@ -1704,7 +1704,10 @@ Try `%s --help' or `%s --usage' for more information.\
 void __argp_help (const struct argp *argp, FILE *stream,
 		  unsigned flags, char *name)
 {
-  _help (argp, 0, stream, flags, name);
+  struct argp_state state = {
+    .root_argp = argp,
+  };
+  _help (argp, &state, stream, flags, name);
 }
 #ifdef weak_alias
 weak_alias (__argp_help, argp_help)
