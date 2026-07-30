--- src/main.c.orig	2026-06-17 17:18:37 UTC
+++ src/main.c
@@ -286,7 +286,9 @@ static void print_help(void) {
     printf("  codebase-memory-mcp cli <tool> [json]  Run a single tool\n");
     printf("  codebase-memory-mcp install [-y|-n] [--force] [--dry-run]\n");
     printf("  codebase-memory-mcp uninstall [-y|-n] [--dry-run]\n");
+#ifndef CBM_PACKAGE_MANAGED
     printf("  codebase-memory-mcp update [-y|-n]\n");
+#endif
     printf("  codebase-memory-mcp config <list|get|set|reset>\n");
     printf("  codebase-memory-mcp --version    Print version\n");
     printf("  codebase-memory-mcp --help       Print this help\n");
@@ -338,7 +340,14 @@ static int handle_subcommand(int argc, char **argv) {
             return cbm_cmd_uninstall(argc - i - SKIP_ONE, argv + i + SKIP_ONE);
         }
         if (strcmp(argv[i], "update") == 0) {
+#ifdef CBM_PACKAGE_MANAGED
+            (void)fprintf(stderr,
+                "codebase-memory-mcp: 'update' is disabled in this build; "
+                "use the system package manager (e.g. pkg(8)) to upgrade.\n");
+            return 1;
+#else
             return cbm_cmd_update(argc - i - SKIP_ONE, argv + i + SKIP_ONE);
+#endif
         }
         if (strcmp(argv[i], "config") == 0) {
             return cbm_cmd_config(argc - i - SKIP_ONE, argv + i + SKIP_ONE);
