--- src/getargs.c.orig	Sun Sep 23 02:08:44 2001
+++ src/getargs.c	Sun Sep 23 02:09:27 2001
@@ -35,6 +35,7 @@
 int statistics_flag = 0;
 int yacc_flag = 0;	/* for -y */
 int graph_flag = 0;
+int broken_undeftoken_init;
 
 const char *skeleton = NULL;
 
@@ -42,6 +43,7 @@
 const char *shortopts = "yvgdhrltknVo:b:p:S:";
 static struct option longopts[] =
 {
+  {"broken-undeftoken-init", 0, &broken_undeftoken_init, 1},
   /* Operation modes. */
   {"help",		no_argument,	0, 'h'},
   {"version",		no_argument, 	0, 'V'},
