--- build/premake/premake5.lua.orig	2021-02-28 23:45:14 UTC
+++ build/premake/premake5.lua
@@ -87,6 +87,8 @@ else
 			arch = "aarch64"
 		elseif string.find(machine, "e2k") == 1 then
 			arch = "e2k"
+		elseif string.find(machine, "ppc64") == 1 or string.find(machine, "powerpc64") == 1 then
+			arch = "ppc64"
 		else
 			print("WARNING: Cannot determine architecture from GCC, assuming x86")
 		end
@@ -365,7 +365,7 @@ function project_set_build_flags()
 
 		if os.istarget("linux") or os.istarget("bsd") then
 			if _OPTIONS["prefer-local-libs"] then
-				libdirs { "/usr/local/lib" }
+				libdirs { "%%LOCALBASE%%/lib" }
 			end
 
 			-- To use our local shared libraries, they need to be found in the
@@ -865,6 +867,8 @@ function setup_all_libs ()
 		table.insert(source_dirs, "lib/sysdep/arch/aarch64");
 	elseif arch == "e2k" then
 		table.insert(source_dirs, "lib/sysdep/arch/e2k");
+	elseif arch == "ppc64" then
+		table.insert(source_dirs, "lib/sysdep/arch/ppc64");
 	end

 	-- OS-specific
