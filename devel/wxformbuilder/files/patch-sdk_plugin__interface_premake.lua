--- sdk/plugin_interface/premake.lua.orig	2015-08-29 07:10:51 UTC
+++ sdk/plugin_interface/premake.lua
@@ -216,10 +216,10 @@ else
 	table.insert( package.buildoptions, "-fPIC" )
 
 	-- Set wxWidgets build options.
-	table.insert( package.config["Debug"].buildoptions, "`wx-config "..debug_option.." --cflags`" )
-	table.insert( package.config["Release"].buildoptions, "`wx-config --debug=no --cflags`" )
+	table.insert( package.config["Debug"].buildoptions, "`%%WX_CONFIG%% "..debug_option.." --cflags`" )
+	table.insert( package.config["Release"].buildoptions, "`%%WX_CONFIG%% --debug=no --cflags`" )
 
 	-- Set the wxWidgets link options.
-	table.insert( package.config["Debug"].linkoptions, "`wx-config "..debug_option.." --libs`" )
-	table.insert( package.config["Release"].linkoptions, "`wx-config --libs`" )
+	table.insert( package.config["Debug"].linkoptions, "`%%WX_CONFIG%% "..debug_option.." --libs`" )
+	table.insert( package.config["Release"].linkoptions, "`%%WX_CONFIG%% --libs`" )
 end
