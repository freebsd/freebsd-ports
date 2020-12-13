- Add DragonFly support
- Respect CC/CFLAGS/LD/LDFLAGS
- Prefer system compiler over GCC on BSDs/Solaris
- OpenBSD uses Clang by default, so do not pass GCC RPATH

--- src/luarocks/core/cfg.lua.orig	2020-01-28 15:54:42 UTC
+++ src/luarocks/core/cfg.lua
@@ -36,6 +36,7 @@ local platform_order = {
    "netbsd",
    "openbsd",
    "freebsd",
+   "dragonfly",
    "linux",
    "macosx",
    "cygwin",
@@ -157,6 +158,7 @@ end
 
 local platform_sets = {
    freebsd = { unix = true, bsd = true, freebsd = true },
+   dragonfly = { unix = true, bsd = true, dragonfly = true },
    openbsd = { unix = true, bsd = true, openbsd = true },
    solaris = { unix = true, solaris = true },
    windows = { windows = true, win32 = true },
@@ -365,12 +367,13 @@ local function make_defaults(lua_version, target_cpu, 
       defaults.external_lib_extension = "so"
       defaults.obj_extension = "o"
       defaults.external_deps_dirs = { "/usr/local", "/usr", "/" }
-      defaults.variables.CFLAGS = "-O2"
+      defaults.variables.CFLAGS = os.getenv("CFLAGS") or "-O2"
       defaults.cmake_generator = "Unix Makefiles"
-      defaults.variables.CC = "gcc"
-      defaults.variables.LD = "gcc"
+      -- Assume "cc" is a modern GCC-compatible compiler
+      defaults.variables.CC = os.getenv("CC") or defaults.variables.CC
+      defaults.variables.LD = os.getenv("CC") or defaults.variables.CC
       defaults.gcc_rpath = true
-      defaults.variables.LIBFLAG = "-shared"
+      defaults.variables.LIBFLAG = (os.getenv("LDFLAGS") or "").." -shared"
       defaults.variables.TEST = "test"
 
       defaults.external_deps_patterns = {
@@ -457,12 +460,15 @@ local function make_defaults(lua_version, target_cpu, 
    if platforms.freebsd then
       defaults.arch = "freebsd-"..target_cpu
       defaults.gcc_rpath = false
-      defaults.variables.CC = "cc"
-      defaults.variables.LD = "cc"
    end
 
+   if platforms.dragonfly then
+     defaults.arch = "dragonfly-"..target_cpu
+   end
+
    if platforms.openbsd then
       defaults.arch = "openbsd-"..target_cpu
+      defaults.gcc_rpath = false
    end
 
    if platforms.netbsd then
