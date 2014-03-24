--- ./premake4.lua.orig	2014-01-06 20:04:42.000000000 -0500
+++ ./premake4.lua	2014-03-23 19:34:38.037102075 -0400
@@ -30,11 +30,14 @@
 
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
 
 configuration "windows"
 	libdirs {
@@ -61,8 +64,6 @@
 
 configuration "Release"
 	defines { "NDEBUG=1" }
-	flags { "Optimize", "NoFramePointer" }
-	buildoptions { "-O2" }
 	targetdir "bin/Release"
 
 
