--- src/cli/cli.c.orig	2026-09-16 19:47:37 UTC
+++ src/cli/cli.c
@@ -9003,7 +9003,12 @@ static void cbm_agent_installed_binary_path(const char
 
 static void cbm_agent_installed_binary_path(const char *home, char *binary_path,
                                             size_t binary_path_size) {
-#ifdef _WIN32
+#if defined(__FreeBSD__) && defined(CBM_PKG_PREFIX)
+    /* The port/pkg install the binary under ${PREFIX}/bin, not ~/.local/bin, so
+     * agent configs (mcp.json, hooks) must point there. */
+    (void)home;
+    snprintf(binary_path, binary_path_size, CBM_PKG_PREFIX "/bin/codebase-memory-mcp");
+#elif defined(_WIN32)
     snprintf(binary_path, binary_path_size, "%s/.local/bin/codebase-memory-mcp.exe", home);
 #else
     snprintf(binary_path, binary_path_size, "%s/.local/bin/codebase-memory-mcp", home);
@@ -11147,6 +11152,13 @@ int cbm_cmd_install(int argc, char **argv) {
                    manager ? " by " : "", manager ? manager : "", self_path, bin_dir);
         }
         skip_binary = true;
+        /* We are not placing a binary, so agent configs must reference the one
+         * that is actually running, not the ~/.local/bin default that no file
+         * lives at (#pkg: FreeBSD ports install under /usr/local/bin). Retarget
+         * to the OS-reported self path when we have it. */
+        if (self_path_exact && self_path[0]) {
+            snprintf(bin_target, sizeof(bin_target), "%s", self_path);
+        }
     }
 
     /* NOT stat(): on Windows it goes through the ANSI code page, so an
