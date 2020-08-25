--- src/options.h.orig	2019-08-20 19:01:23 UTC
+++ src/options.h
@@ -321,8 +321,8 @@ struct _ConfOptions
 	GList *disabled_plugins;
 };
 
-ConfOptions *options;
-CommandLine *command_line;
+extern ConfOptions *options;
+extern CommandLine *command_line;
 
 ConfOptions *init_options(ConfOptions *options);
 void setup_default_options(ConfOptions *options);
