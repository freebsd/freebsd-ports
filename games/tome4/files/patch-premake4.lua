--- ./premake4.lua.orig	2014-05-19 04:42:14.000000000 -0400
+++ ./premake4.lua	2014-06-04 12:40:26.968305458 -0400
@@ -28,11 +28,6 @@
 			"/usr/i686-pc-mingw32/usr/include/",
 			"/usr/i686-pc-mingw32/usr/include/GL/",
 		}
-	else
-		includedirs {
-			"/opt/SDL-2.0/include/SDL2",
-			"/usr/include/GL",
-		}
 	end
 	if _OPTIONS.lua == "default" then includedirs{"src/lua"}
 	elseif _OPTIONS.lua == "jit2" then includedirs{"src/luajit2/src", "src/luajit2/dynasm",}
@@ -44,11 +39,14 @@
 
 configuration "bsd"
 	libdirs {
-		"/usr/local/lib",
+		"bin/Release", "/usr/local/lib",
 	}
 	includedirs {
 		"/usr/local/include",
 	}
+	buildoptions {
+		"-pthread",
+	}
 
 if _OPTIONS.wincross then
 configuration "windows"
@@ -86,8 +84,6 @@
 
 configuration "Release"
 	defines { "NDEBUG=1" }
-	flags { "Optimize", "NoFramePointer" }
-	buildoptions { "-O2" }
 	targetdir "bin/Release"
 
 
