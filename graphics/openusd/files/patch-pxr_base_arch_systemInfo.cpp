--- pxr/base/arch/systemInfo.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/systemInfo.cpp
@@ -15,7 +15,7 @@
 #include <functional>
 #include <limits>
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM) || defined(ARCH_OS_FREEBSD)
 
     #include <sys/types.h>
     #include <sys/stat.h>
@@ -96,16 +96,23 @@ ArchGetExecutablePath()
 std::string
 ArchGetExecutablePath()
 {
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 
+#if defined(ARCH_OS_LINUX)
     // On Linux the executable path is retrieved from the /proc/self/exe
     // symlink.
+#define SELF_PATHNAME "/proc/self/exe";
+#else
+    // On FreeBSD the executable path is retrieved from the /proc/curproc/file
+    // symlink.
+#define SELF_PATHNAME "/proc/curproc/file"
+#endif
     return
         _DynamicSizedRead(ARCH_PATH_MAX,
             [](char* buffer, size_t* size) {
-                const ssize_t n = readlink("/proc/self/exe", buffer, *size);
+                const ssize_t n = readlink(SELF_PATHNAME, buffer, *size);
                 if (n == -1) {
-                    ARCH_WARNING("Unable to read /proc/self/exe to obtain "
+                    ARCH_WARNING("Unable to read " SELF_PATHNAME " to obtain "
                                  "executable path");
                     *size = std::numeric_limits<size_t>::max();
                     return false;
@@ -113,7 +120,7 @@ ArchGetExecutablePath()
                 else if (static_cast<size_t>(n) >= *size) {
                     // Find out how much space we need.
                     struct stat sb;
-                    if (lstat("/proc/self/exe", &sb) == 0) {
+                    if (lstat(SELF_PATHNAME, &sb) == 0) {
                         *size = sb.st_size + 1;
                     }
                     else {
@@ -127,6 +134,7 @@ ArchGetExecutablePath()
                     return true;
                 }
             });
+#undef SELF_PATHNAME
 
 #elif defined(ARCH_OS_DARWIN)
 
@@ -177,7 +185,7 @@ ArchGetPageSize()
 ArchGetPageSize()
 {
 #if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || \
-    defined(ARCH_OS_WASM_VM)
+    defined(ARCH_OS_WASM_VM) || defined(ARCH_OS_FREEBSD)
     return sysconf(_SC_PAGE_SIZE);
 #elif defined(ARCH_OS_WINDOWS)
     SYSTEM_INFO info;
