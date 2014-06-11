--- ./build/te4core.lua.orig	2014-05-19 04:42:12.000000000 -0400
+++ ./build/te4core.lua	2014-06-04 12:45:57.973283399 -0400
@@ -40,7 +40,6 @@
 	links { "physfs", "lua".._OPTIONS.lua, "fov", "luasocket", "luaprofiler", "lpeg", "tcodimport", "lxp", "expatstatic", "luamd5", "luazlib", "luabitop", "te4-bzip" }
 	defines { "_DEFAULT_VIDEOMODE_FLAGS_='SDL_HWSURFACE|SDL_DOUBLEBUF'" }
 	defines { [[TENGINE_HOME_PATH='".t-engine"']], "TE4CORE_VERSION="..TE4CORE_VERSION }
-	buildoptions { "-O3" }
 
 	if _OPTIONS.relpath=="32" then linkoptions{"-Wl,-rpath -Wl,\\\$\$ORIGIN/lib "} end
 	if _OPTIONS.relpath=="64" then linkoptions{"-Wl,-rpath -Wl,\\\$\$ORIGIN/lib64 "} end
@@ -194,7 +193,7 @@
 		if _OPTIONS.wincross then
 			arch_test = os.capture("i686-pc-mingw32-gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
 		else
-			arch_test = os.capture("gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
+			arch_test = os.capture("cc -E ../src/luajit2/src/lj_arch.h -dM", true)
 		end
 
 		if string.find(arch_test, "LJ_TARGET_X64") then
@@ -253,7 +252,7 @@
 		if _OPTIONS.wincross then
 			arch_test = os.capture("i686-pc-mingw32-gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
 		else
-			arch_test = os.capture("gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
+			arch_test = os.capture("cc -E ../src/luajit2/src/lj_arch.h -dM", true)
 		end
 
 		if string.find(arch_test, "LJ_TARGET_X64") then
