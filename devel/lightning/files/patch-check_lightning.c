--- check/lightning.c.orig	2022-11-08 16:00:32 UTC
+++ check/lightning.c
@@ -4333,7 +4333,7 @@ main(int argc, char *argv[])
 #else
 #  define cc "gcc"
 #endif
-    opt_short = snprintf(cmdline, sizeof(cmdline), cc " -E -x c %s", argv[opt_index]);
+    opt_short = snprintf(cmdline, sizeof(cmdline), "%%CC%% -E -x c %s", argv[opt_index]);
     opt_short += snprintf(cmdline + opt_short,
 			  sizeof(cmdline) - opt_short,
 			  " -D__WORDSIZE=%d", __WORDSIZE);
