--- scripts/release.lua.orig	2023-09-20 17:46:05 UTC
+++ scripts/release.lua
@@ -21,7 +21,7 @@ function dorelease()
 	f = io.popen("git log --format=format:%H -1")
 	local sha1 = f:read("*a")
 	f:close()
-	io.output("src/host/version.h")
+	io.output("../src/host/version.h")
 	io.write("#define VERSION " ..rev .. "\n")
 	io.write("#define VERSION_STR \"version " ..rev .. " (commit " .. sha1 .. ")\"\n")
 	io.close()
@@ -37,9 +37,7 @@ function dorelease()
 
 	print("Generating project files...")
 
-	exec(_PREMAKE_COMMAND .. " /to=../build/gmake.windows /os=windows gmake")
-	exec(_PREMAKE_COMMAND .. " /to=../build/gmake.linux /os=linux gmake")
-	exec(_PREMAKE_COMMAND .. " /to=../build/gmake.darwin /os=macosx /platform=universal32 gmake")
+	exec(_PREMAKE_COMMAND .. " /to=../build/gmake.freebsd /os=bsd gmake")
 
 	print("")
 	print( "Finished.")
