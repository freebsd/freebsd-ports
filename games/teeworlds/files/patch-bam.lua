--- bam.lua.orig	2011-04-09 23:15:25.000000000 +0400
+++ bam.lua	2011-08-04 01:03:26.000000000 +0400
@@ -154,7 +154,7 @@
 			settings.link.frameworks:Add("Carbon")
 			settings.link.frameworks:Add("AppKit")
 		else
-			settings.link.libs:Add("pthread")
+			settings.link.flags:Add("-pthread")
 		end
 	elseif family == "windows" then
 		settings.link.libs:Add("gdi32")
@@ -281,8 +281,10 @@
 release_settings.config_name = "release"
 release_settings.config_ext = ""
 release_settings.debug = 0
-release_settings.optimize = 1
+release_settings.optimize = 0
 release_settings.cc.defines:Add("CONF_RELEASE")
+release_settings.cc.flags_c:Add(os.getenv("CFLAGS"))
+release_settings.cc.flags_cxx:Add(os.getenv("CXXFLAGS"))
 
 if platform == "macosx"  and arch == "ia32" then
 	debug_settings_ppc = debug_settings:Copy()
