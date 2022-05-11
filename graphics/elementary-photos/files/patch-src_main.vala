--- src/main.vala.orig	2022-02-01 18:38:16 UTC
+++ src/main.vala
@@ -273,7 +273,7 @@ namespace CommandlineOptions {
     bool show_version = false;
     bool debug_enabled = false;
 
-    public const OptionEntry[] APP_OPTIONS = {
+    const OptionEntry[] APP_OPTIONS = {
         { "datadir", 'd', 0, OptionArg.FILENAME, out data_dir, N_("Path to Photos' private data"), N_("DIRECTORY")},
         { "no-runtime-monitoring", 0, 0, OptionArg.NONE, out no_runtime_monitoring, N_("Do not monitor library directory at runtime for changes"), null},
         { "no-startup-progress", 0, 0, OptionArg.NONE, out no_startup_progress, N_("Don't display startup progress meter"), null},
