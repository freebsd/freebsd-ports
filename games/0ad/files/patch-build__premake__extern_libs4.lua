--- build/premake/extern_libs4.lua.orig	2015-11-19 23:47:41 UTC
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
@@ -347,9 +347,6 @@ extern_lib_defs = {
 			elseif os.is("macosx") then
 				add_default_include_paths("iconv")
 				defines { "LIBICONV_STATIC" }
-			elseif os.getversion().description == "FreeBSD" then
-				defines { "HAVE_ICONV_CONST" }
-				defines { "ICONV_CONST=const" }
 			end
 		end,
 		link_settings = function()
