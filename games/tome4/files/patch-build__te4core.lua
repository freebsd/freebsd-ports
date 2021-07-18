--- ./build/te4core.lua.orig	2014-05-19 04:42:12.000000000 -0400
+++ ./build/te4core.lua	2014-06-04 12:45:57.973283399 -0400
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
