--- src/daemon/runtime.c.orig	2026-08-15 16:26:11 UTC
+++ src/daemon/runtime.c
@@ -54,6 +54,12 @@ void cbm_daemon_runtime_force_peer_image_mismatch_for_
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <unistd.h>
+#elif defined(__FreeBSD__)
+#include <fcntl.h>
+#include <sys/stat.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <unistd.h>
 #endif
 
 enum {
@@ -155,7 +161,7 @@ typedef struct {
     HANDLE file;
     BY_HANDLE_FILE_INFORMATION information;
     LARGE_INTEGER size;
-#elif defined(__APPLE__) || defined(__linux__)
+#elif defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
     int fd;
     struct stat status;
 #endif
@@ -510,7 +516,7 @@ static uint64_t runtime_current_process_id(void) {
 static uint64_t runtime_current_process_id(void) {
 #ifdef _WIN32
     return (uint64_t)GetCurrentProcessId();
-#elif defined(__APPLE__) || defined(__linux__)
+#elif defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
     return (uint64_t)getpid();
 #else
     return 0;
@@ -524,7 +530,7 @@ static void runtime_process_image_reference_init(runti
     memset(reference, 0, sizeof(*reference));
 #ifdef _WIN32
     reference->file = INVALID_HANDLE_VALUE;
-#elif defined(__APPLE__) || defined(__linux__)
+#elif defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
     reference->fd = -1;
 #endif
 }
@@ -538,7 +544,7 @@ static bool runtime_process_image_reference_release(ru
     if (reference->file != INVALID_HANDLE_VALUE && !CloseHandle(reference->file)) {
         ok = false;
     }
-#elif defined(__APPLE__) || defined(__linux__)
+#elif defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
     if (reference->fd >= 0 && close(reference->fd) != 0) {
         ok = false;
     }
@@ -678,7 +684,7 @@ static bool runtime_mac_process_maps_file_executable(i
     return false;
 }
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
 static bool runtime_linux_stat_same_image(const struct stat *first, const struct stat *second) {
     return first && second && S_ISREG(first->st_mode) && S_ISREG(second->st_mode) &&
@@ -814,6 +820,35 @@ static bool runtime_process_image_reference_acquire(
     } else if (image_fd >= 0) {
         (void)close(image_fd);
     }
+#elif defined(__FreeBSD__)
+    /* FreeBSD mounts no /proc by default, so /proc/<pid>/exe is unavailable.
+     * sysctl KERN_PROC_PATHNAME resolves any pid's executable path directly.
+     * Open that path and hold it as the image reference, mirroring the Linux
+     * branch's stat-bracketing to detect a swap under us. */
+    if (process_id > INT_MAX) {
+        return false;
+    }
+    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, (int)process_id};
+    char image_path[PATH_MAX];
+    size_t image_path_size = sizeof(image_path);
+    bool path_ok = sysctl(mib, 4, image_path, &image_path_size, NULL, 0) == 0 &&
+                   image_path_size > 1 && image_path_size <= sizeof(image_path);
+    int image_fd = path_ok ? open(image_path, O_RDONLY | O_CLOEXEC | O_NOFOLLOW | O_NONBLOCK) : -1;
+    struct stat image_before;
+    struct stat image_after;
+    bool ok = image_fd >= 0 && fstat(image_fd, &image_before) == 0 &&
+              S_ISREG(image_before.st_mode) &&
+              (!fingerprint ||
+               cbm_daemon_build_fingerprint_native_file((uintptr_t)image_fd, fingerprint)) &&
+              fstat(image_fd, &image_after) == 0 &&
+              runtime_linux_stat_same_image(&image_before, &image_after);
+    if (ok) {
+        reference->held = true;
+        reference->fd = image_fd;
+        reference->status = image_after;
+    } else if (image_fd >= 0) {
+        (void)close(image_fd);
+    }
 #else
     (void)process_id;
     bool ok = false;
@@ -854,7 +889,7 @@ static bool runtime_process_image_reference_matches_pr
            runtime_mac_stat_same(&active->status, &peer.status);
     bool released = runtime_process_image_reference_release(&peer);
     return same && released;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     runtime_process_image_reference_t peer;
     runtime_process_image_reference_init(&peer);
     bool same = runtime_process_image_reference_acquire(process_id, &peer, NULL);
