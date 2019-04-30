--- scripts/toolchain.lua.orig	2018-02-27 15:59:06 UTC
+++ scripts/toolchain.lua
@@ -23,6 +23,7 @@ newoption {
 		{ "android-x64",   "Android - x64"          },
 		{ "asmjs",         "Emscripten/asm.js"      },
 		{ "freebsd",       "FreeBSD"                },
+		{ "freebsd-clang", "FreeBSD (Clang)"        },
 		{ "linux-gcc",     "Linux (GCC compiler)"   },
 		{ "linux-clang",   "Linux (Clang compiler)" },
 		{ "ios-arm",       "iOS - ARM"              },
@@ -168,6 +169,10 @@ function toolchain(_buildDir, _subDir)
 			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-freebsd")
 		end
 
+		if "freebsd-clang" == _OPTIONS["gcc"] then
+			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-freebsd-clang")
+		end
+
 		if "netbsd" == _OPTIONS["gcc"] then
 			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-netbsd")
 		end
