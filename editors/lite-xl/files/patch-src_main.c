--- src/main.c.orig	2022-11-02 02:38:58 UTC
+++ src/main.c
@@ -7,11 +7,14 @@
 
 #ifdef _WIN32
   #include <windows.h>
-#elif __linux__ || __FreeBSD__
+#elif __linux__
   #include <unistd.h>
   #include <signal.h>
 #elif __APPLE__
   #include <mach-o/dyld.h>
+#elif __FreeBSD__
+  #include <sys/sysctl.h>
+  #include <signal.h>
 #endif
 
 
@@ -43,6 +46,10 @@ static void get_exe_filename(char *buf, int sz) {
   char exepath[size];
   _NSGetExecutablePath(exepath, &size);
   realpath(exepath, buf);
+#elif __FreeBSD__
+  size_t len = sz;
+  const int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+  sysctl(mib, 4, buf, &len, NULL, 0);
 #else
   strcpy(buf, "./lite");
 #endif
@@ -91,6 +98,10 @@ void set_macos_bundle_resources(lua_State *L);
     #define ARCH_PROCESSOR "aarch64"
   #elif __arm__
     #define ARCH_PROCESSOR "arm"
+  #elif __powerpc64__
+    #define ARCH_PROCESSOR "ppc64"
+  #elif __powerpc__
+    #define ARCH_PROCESSOR "ppc"
   #endif
 
   #if _WIN32
