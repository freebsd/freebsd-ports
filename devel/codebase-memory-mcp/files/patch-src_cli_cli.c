--- src/cli/cli.c.orig	2026-08-14 04:11:37 UTC
+++ src/cli/cli.c
@@ -7963,7 +7963,12 @@ static void cbm_agent_installed_binary_path(const char
 
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
@@ -9472,6 +9477,16 @@ static const char *cli_external_manager_name(const cha
     if (strstr(self_path, "/.cargo/bin/")) {
         return "cargo";
     }
+#if defined(__FreeBSD__) && defined(CBM_PKG_PREFIX)
+    /* FreeBSD ports/pkg install the binary under ${PREFIX}/bin (CBM_PKG_PREFIX
+     * is the port's PREFIX, default /usr/local). pkg owns that file, so install
+     * must not copy it into ~/.local/bin or edit PATH, and update must refuse
+     * and defer to pkg(8). Match only ${PREFIX}/bin/ so a manual --dir install
+     * elsewhere is still treated as ours. */
+    if (strstr(self_path, CBM_PKG_PREFIX "/bin/") == self_path) {
+        return "FreeBSD pkg";
+    }
+#endif
     return NULL;
 }
 
@@ -9890,6 +9905,13 @@ int cbm_cmd_install(int argc, char **argv) {
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
@@ -11939,6 +11961,8 @@ int cbm_cmd_update(int argc, char **argv) {
                 (void)fprintf(stderr, "  update it with: mise upgrade codebase-memory-mcp\n");
             } else if (manager && strcmp(manager, "Homebrew") == 0) {
                 (void)fprintf(stderr, "  update it with: brew upgrade codebase-memory-mcp\n");
+            } else if (manager && strcmp(manager, "FreeBSD pkg") == 0) {
+                (void)fprintf(stderr, "  update it with: pkg upgrade codebase-memory-mcp\n");
             } else {
                 (void)fprintf(stderr, "  update it through whichever tool installed it.\n");
             }
