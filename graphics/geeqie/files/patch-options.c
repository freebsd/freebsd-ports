--- src/options.c.orig	2019-08-20 19:01:23 UTC
+++ src/options.c
@@ -32,6 +32,9 @@
 #include "ui_fileops.h"
 #include "window.h"
 
+ConfOptions *options;
+CommandLine *command_line;
+
 ConfOptions *init_options(ConfOptions *options)
 {
 	gint i;
