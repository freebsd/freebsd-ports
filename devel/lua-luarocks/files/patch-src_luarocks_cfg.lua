--- src/luarocks/cfg.lua.orig	2015-04-24 18:28:33 UTC
+++ src/luarocks/cfg.lua
@@ -88,7 +88,15 @@ elseif proc:match("Power Macintosh") the
    proc = "powerpc"
 end
 
-if system == "FreeBSD" then
+if system == "Bitrig" then
+   detected.unix = true
+   detected.bitrig = true
+   detected.bsd = true
+elseif system == "DragonFly" then
+   detected.unix = true
+   detected.dragonfly = true
+   detected.bsd = true
+elseif system == "FreeBSD" then
    detected.unix = true
    detected.freebsd = true
    detected.bsd = true
@@ -397,17 +405,19 @@ if detected.unix then
    defaults.lib_extension = "so"
    defaults.external_lib_extension = "so"
    defaults.obj_extension = "o"
-   defaults.external_deps_dirs = { "/usr/local", "/usr" }
+   defaults.external_deps_dirs = { site_config.LUAROCKS_PREFIX, "/usr" }
    defaults.variables.LUA_BINDIR = site_config.LUA_BINDIR or "/usr/local/bin"
    defaults.variables.LUA_INCDIR = site_config.LUA_INCDIR or "/usr/local/include"
    defaults.variables.LUA_LIBDIR = site_config.LUA_LIBDIR or "/usr/local/lib"
-   defaults.variables.CFLAGS = "-O2"
+   defaults.variables.CFLAGS = os.getenv("CFLAGS") or "-O2"
    defaults.cmake_generator = "Unix Makefiles"
    defaults.platforms = { "unix" }
-   defaults.variables.CC = "gcc"
-   defaults.variables.LD = "gcc"
+   defaults.variables.MAKE = os.getenv("MAKE") or defaults.variables.MAKE
+   -- Assume "cc" is a modern GCC-compatible compiler
+   defaults.variables.CC = os.getenv("CC") or defaults.variables.CC
+   defaults.variables.LD = os.getenv("CC") or defaults.variables.CC
    defaults.gcc_rpath = true
-   defaults.variables.LIBFLAG = "-shared"
+   defaults.variables.LIBFLAG = (os.getenv("LDFLAGS") or "").." -shared"
    defaults.external_deps_patterns = {
       bin = { "?" },
       lib = { "lib?.a", "lib?.so", "lib?.so.*" },
@@ -472,12 +482,20 @@ if detected.linux then
    defaults.platforms = {"unix", "linux"}
 end
 
+if detected.bitrig then
+   defaults.arch = "bitrig-"..proc
+   defaults.platforms = {"unix", "bsd", "bitrig"}
+end
+
+if detected.dragonfly then
+   defaults.arch = "dragonfly-"..proc
+   defaults.platforms = {"unix", "bsd", "dragonfly"}
+end
+
 if detected.freebsd then
    defaults.arch = "freebsd-"..proc
    defaults.platforms = {"unix", "bsd", "freebsd"}
    defaults.gcc_rpath = false
-   defaults.variables.CC = "cc"
-   defaults.variables.LD = "cc"
 end
 
 if detected.openbsd then
