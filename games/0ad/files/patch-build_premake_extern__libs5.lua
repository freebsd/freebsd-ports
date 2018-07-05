--- build/premake/extern_libs5.lua.orig	2018-04-29 15:44:48 UTC
+++ build/premake/extern_libs5.lua
@@ -191,7 +191,7 @@ extern_lib_defs = {
 			end
 			-- TODO: This actually applies to most libraries we use on BSDs, make this a global setting.
 			if os.istarget("bsd") then
-				sysincludedirs { "/usr/local/include" }
+				sysincludedirs { "%%LOCALBASE%%/include" }
 			end
 		end,
 		link_settings = function()
@@ -301,9 +301,6 @@ extern_lib_defs = {
 			elseif os.istarget("macosx") then
 				add_default_include_paths("iconv")
 				defines { "LIBICONV_STATIC" }
-			elseif os.getversion().description == "FreeBSD" then
-				defines { "HAVE_ICONV_CONST" }
-				defines { "ICONV_CONST=const" }
 			end
 		end,
 		link_settings = function()
