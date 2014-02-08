--- ./premake4.lua.orig	2014-02-06 13:23:35.469164876 -0500
+++ ./premake4.lua	2014-02-06 13:34:48.071117476 -0500
@@ -35,6 +35,9 @@
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
 
 
