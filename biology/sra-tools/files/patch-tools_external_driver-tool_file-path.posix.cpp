--- tools/external/driver-tool/file-path.posix.cpp.orig	2023-07-10 16:23:35 UTC
+++ tools/external/driver-tool/file-path.posix.cpp
@@ -193,7 +193,16 @@ static char const *find_executable_path(char const *co
 FilePath FilePath::fullPathToExecutable(char const *const *const argv, char const *const *const envp, char const *const *const extra)
 {
     char const *path;
-#if LINUX
+// Assume sra-tools is installed by FreeBSD ports.  FreeBSD users
+// don't often install software by other means.  Default prefix
+// is /usr/local, but this can be overridden by the user building
+// the port.  The port can replace /usr/local using sed if that's the
+// case.
+#if BSD
+    char full_path[PATH_MAX];
+    snprintf(full_path, PATH_MAX, "/usr/local/bin/%s", argv[0]);
+    path = full_path;
+#elif LINUX
     path = "/proc/self/exe";
 #elif MAC
     path = find_executable_path(extra, argv[0]);
