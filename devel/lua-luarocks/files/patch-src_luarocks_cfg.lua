- Add DragonFly support
- Respect CC/CFLAGS/LD/LDFLAGS
- Prefer system compiler over GCC on BSDs/Solaris
- OpenBSD uses Clang by default, so don't pass GCC RPATH

--- src/luarocks/cfg.lua.orig	2018-03-13 00:08:59 UTC
+++ src/luarocks/cfg.lua
@@ -87,7 +87,11 @@ elseif proc:match("Power Macintosh") then
    cfg.target_cpu = proc
 end
 
-if system == "FreeBSD" then
+if system == "DragonFly" then
+   cfg.platforms.unix = true
+   cfg.platforms.dragonfly = true
+   cfg.platforms.bsd = true
+elseif system == "FreeBSD" then
    cfg.platforms.unix = true
    cfg.platforms.freebsd = true
    cfg.platforms.bsd = true
@@ -517,16 +521,17 @@ if cfg.platforms.unix then
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
-   defaults.variables.CC = "gcc"
-   defaults.variables.LD = "gcc"
+   -- Assume "cc" is a modern GCC-compatible compiler
+   defaults.variables.CC = os.getenv("CC") or defaults.variables.CC
+   defaults.variables.LD = os.getenv("CC") or defaults.variables.CC
    defaults.gcc_rpath = true
-   defaults.variables.LIBFLAG = "-shared"
+   defaults.variables.LIBFLAG = (os.getenv("LDFLAGS") or "").." -shared"
    defaults.external_deps_patterns = {
       bin = { "?" },
       lib = { "lib?.a", "lib?.so", "lib?.so.*" },
@@ -607,15 +612,18 @@ if cfg.platforms.linux then
    defaults.arch = "linux-"..cfg.target_cpu
 end
 
+if cfg.platforms.dragonfly then
+   defaults.arch = "dragonfly-"..cfg.target_cpu
+end
+
 if cfg.platforms.freebsd then
    defaults.arch = "freebsd-"..cfg.target_cpu
    defaults.gcc_rpath = false
-   defaults.variables.CC = "cc"
-   defaults.variables.LD = "cc"
 end
 
 if cfg.platforms.openbsd then
    defaults.arch = "openbsd-"..cfg.target_cpu
+   defaults.gcc_rpath = false
 end
 
 if cfg.platforms.netbsd then
