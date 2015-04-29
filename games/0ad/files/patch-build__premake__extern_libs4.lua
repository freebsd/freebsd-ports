--- build/premake/extern_libs4.lua.orig	2015-02-20 05:52:18 UTC
+++ build/premake/extern_libs4.lua
@@ -237,7 +237,7 @@ extern_lib_defs = {
 			end
 			-- TODO: This actually applies to most libraries we use on BSDs, make this a global setting.
 			if os.is("bsd") then
-				includedirs { "/usr/local/include" }
+				includedirs { "%%LOCALBASE%%/include" }
 			end
 		end,
 		link_settings = function()
@@ -346,8 +346,6 @@ extern_lib_defs = {
 			elseif os.is("macosx") then
 				add_default_include_paths("iconv")
 				defines { "LIBICONV_STATIC" }
-			elseif os.getversion().description == "FreeBSD" then
-				defines { "HAVE_ICONV_CONST" }
 			end
 		end,
 		link_settings = function()
