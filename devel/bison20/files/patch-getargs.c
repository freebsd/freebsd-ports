--- src/getargs.c.orig	Wed Jan 23 05:12:17 2002
+++ src/getargs.c	Sat Feb 16 19:47:24 2002
@@ -36,4 +36,5 @@
 int graph_flag = 0;
 int trace_flag = 0;
+int broken_undeftoken_init;
 
 const char *skeleton = NULL;
@@ -50,4 +51,5 @@
 
   /* Parser. */
+  {"broken-undeftoken-init", 0, &broken_undeftoken_init, 1},
   {"skeleton",		required_argument,	0, 'S'},
   {"debug",		no_argument,		0, 't'},
