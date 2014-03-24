--- ./build/te4core.lua.orig	2014-01-05 19:42:37.000000000 -0500
+++ ./build/te4core.lua	2014-01-05 19:42:37.000000000 -0500
@@ -159,7 +159,7 @@
 
 		files { "../src/luajit2/src/host/minilua.c" }
 
-		local arch_test = os.capture("gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
+		local arch_test = os.capture("cc -E ../src/luajit2/src/lj_arch.h -dM", true)
 
 		if string.find(arch_test, "LJ_TARGET_X64") then
 			target_arch = "x64"
@@ -201,7 +201,7 @@
 		links { "minilua" }
 
 		local dasm_flags = ""
-		local arch_test = os.capture("gcc -E ../src/luajit2/src/lj_arch.h -dM", true)
+		local arch_test = os.capture("cc -E ../src/luajit2/src/lj_arch.h -dM", true)
 
 		if string.find(arch_test, "LJ_TARGET_X64") then
 			target_arch = "x64"
