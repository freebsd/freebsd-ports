--- src/main.c.orig	2021-01-09 16:02:57 UTC
+++ src/main.c
@@ -9,6 +9,8 @@
   #include <unistd.h>
 #elif __APPLE__
   #include <mach-o/dyld.h>
+#elif __FreeBSD__
+  #include <sys/sysctl.h>
 #endif
 
 
@@ -38,6 +40,10 @@ static void get_exe_filename(char *buf, int sz) {
 #elif __APPLE__
   unsigned size = sz;
   _NSGetExecutablePath(buf, &size);
+#elif __FreeBSD__
+  size_t len = sz;
+  const int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+  sysctl(mib, 4, buf, &len, NULL, 0);
 #else
   strcpy(buf, "./lite");
 #endif
@@ -123,8 +129,9 @@ int main(int argc, char **argv) {
     "  SCALE = tonumber(os.getenv(\"LITE_SCALE\")) or SCALE\n"
     "  PATHSEP = package.config:sub(1, 1)\n"
     "  EXEDIR = EXEFILE:match(\"^(.+)[/\\\\].*$\")\n"
-    "  package.path = EXEDIR .. '/data/?.lua;' .. package.path\n"
-    "  package.path = EXEDIR .. '/data/?/init.lua;' .. package.path\n"
+    "  DATADIR = '%%DATADIR%%'\n"
+    "  package.path = DATADIR .. '/?.lua;' .. package.path\n"
+    "  package.path = DATADIR .. '/?/init.lua;' .. package.path\n"
     "  core = require('core')\n"
     "  core.init()\n"
     "  core.run()\n"
