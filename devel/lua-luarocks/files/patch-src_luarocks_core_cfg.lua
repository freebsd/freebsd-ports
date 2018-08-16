- Add DragonFly support
- Respect CC/CFLAGS/LD/LDFLAGS
- Prefer system compiler over GCC on BSDs/Solaris
- OpenBSD uses Clang by default, so don't pass GCC RPATH

--- src/luarocks/core/cfg.lua.orig	2018-08-14 16:30:42 UTC
+++ src/luarocks/core/cfg.lua
@@ -35,6 +35,7 @@ local platform_order = {
    "netbsd",
    "openbsd",
    "freebsd",
+   "dragonfly",
    "linux",
    "macosx",
    "cygwin",
@@ -154,6 +155,7 @@ end
 local function make_platforms(system)
    if system then
       if system == "Linux"            then return { unix = true, linux = true }
+      elseif system == "DragonFly"    then return { unix = true, bsd = true, dragonfly = true }
       elseif system == "FreeBSD"      then return { unix = true, bsd = true, freebsd = true }
       elseif system == "OpenBSD"      then return { unix = true, bsd = true, openbsd = true }
       elseif system == "NetBSD"       then return { unix = true, bsd = true, netbsd = true }
@@ -357,13 +359,13 @@ local function make_defaults(lua_version, target_cpu, 
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
-
+      defaults.variables.LIBFLAG = (os.getenv("LDFLAGS") or "").." -shared"
       defaults.external_deps_patterns = {
          bin = { "?" },
          lib = { "lib?.a", "lib?.so", "lib?.so.*" },
@@ -449,15 +451,18 @@ local function make_defaults(lua_version, target_cpu, 
       end
    end
 
+   if platforms.dragonfly then
+      defaults.arch = "dragonfly-"..target_cpu
+   end
+
    if platforms.freebsd then
       defaults.arch = "freebsd-"..target_cpu
       defaults.gcc_rpath = false
-      defaults.variables.CC = "cc"
-      defaults.variables.LD = "cc"
    end
 
    if platforms.openbsd then
       defaults.arch = "openbsd-"..target_cpu
+      defaults.gcc_rpath = false
    end
 
    if platforms.netbsd then
