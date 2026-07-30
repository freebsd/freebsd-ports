--- src/cli/cli.c.orig	2026-07-29 06:28:47 UTC
+++ src/cli/cli.c
@@ -74,6 +74,10 @@ enum {
 #ifdef __APPLE__
 #include <mach-o/dyld.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/sysctl.h> // KERN_PROC_PATHNAME — /proc-free self-path detection
+#include <sys/types.h>
+#endif
 #include "foundation/compat_fs.h"
 
 #ifndef CBM_VERSION
@@ -3651,6 +3655,14 @@ static void cbm_detect_self_path(char *buf, size_t buf
     if (_NSGetExecutablePath(buf, &sp_sz) != 0) {
         buf[0] = '\0';
     }
+#elif defined(__FreeBSD__)
+    /* FreeBSD has no /proc by default; sysctl KERN_PROC_PATHNAME returns the
+     * running executable's path without it. */
+    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+    size_t sp_sz = buf_sz;
+    if (sysctl(mib, 4, buf, &sp_sz, NULL, 0) != 0) {
+        buf[0] = '\0';
+    }
 #else
     ssize_t sp_len = readlink("/proc/self/exe", buf, buf_sz - SKIP_ONE);
     if (sp_len > 0) {
@@ -3821,6 +3833,18 @@ int cbm_cmd_install(int argc, char **argv) {
     snprintf(bin_target, sizeof(bin_target), "%s/.local/bin/codebase-memory-mcp", home);
 #endif
 
+    /* A package manager (FreeBSD ports, Homebrew, distro pkg) already placed the
+     * binary on PATH under its own prefix and owns that file. Install must not
+     * copy it into ~/.local/bin (a duplicate, unmanaged binary in $HOME), and
+     * agent configs must reference the real binary the manager installed, not
+     * the ~/.local/bin path. Point bin_target at the running executable. */
+#ifdef CBM_PACKAGE_MANAGED
+    if (self_path[0]) {
+        snprintf(bin_target, sizeof(bin_target), "%s", self_path);
+    }
+#endif
+
+#ifndef CBM_PACKAGE_MANAGED
     if (!cbm_same_file(self_path, bin_target)) {
         struct stat tgt_st;
         bool target_exists = (stat(bin_target, &tgt_st) == 0);
@@ -3849,6 +3873,7 @@ int cbm_cmd_install(int argc, char **argv) {
             }
         }
     }
+#endif /* !CBM_PACKAGE_MANAGED */
 
     /* Step 1d: macOS ad-hoc signing of the installed binary. A freshly
      * clang-built arm64 binary is linker-signed (flags=0x20002) and gets
@@ -3869,10 +3894,14 @@ int cbm_cmd_install(int argc, char **argv) {
     /* Step 3: Install/refresh all agent configs, pointing at the install target. */
     cbm_install_agent_configs(home, bin_target, force, dry_run);
 
-    /* Step 4: Ensure PATH */
+    /* Step 4: Ensure PATH. Skipped under CBM_PACKAGE_MANAGED: the package
+     * manager owns PATH via its prefix, so install must not append
+     * `export PATH=...` to the user's shell rc. */
+    const char *rc = "";
+#ifndef CBM_PACKAGE_MANAGED
     char bin_dir[CLI_BUF_1K];
     snprintf(bin_dir, sizeof(bin_dir), "%s/.local/bin", home);
-    const char *rc = cbm_detect_shell_rc(home);
+    rc = cbm_detect_shell_rc(home);
     if (rc[0]) {
         int path_rc = cbm_ensure_path(bin_dir, rc, dry_run);
         if (path_rc == 0) {
@@ -3881,9 +3910,12 @@ int cbm_cmd_install(int argc, char **argv) {
             printf("\nPATH already includes %s\n", bin_dir);
         }
     }
+#endif
 
-    printf("\nInstall complete. Restart your shell or run:\n");
-    printf("  source %s\n", rc);
+    printf("\nInstall complete.\n");
+    if (rc[0]) {
+        printf("Restart your shell or run:\n  source %s\n", rc);
+    }
     if (dry_run) {
         printf("\n(dry-run — no files were modified)\n");
     }
