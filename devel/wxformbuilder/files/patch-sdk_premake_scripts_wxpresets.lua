--- sdk/premake/scripts/wxpresets.lua.orig	2015-08-29 07:11:48 UTC
+++ sdk/premake/scripts/wxpresets.lua
@@ -197,12 +197,12 @@ function ConfigureWxWidgets( package, al
 		table.insert( package.excludes, matchrecursive( "*.rc" ) )
 		
 		-- Set wxWidgets build options.
-		table.insert( package.config["Debug"].buildoptions, "`wx-config "..debug_option.." --cflags`" )
-		table.insert( package.config["Release"].buildoptions, "`wx-config --debug=no --cflags`" )
+		table.insert( package.config["Debug"].buildoptions, "`%%WX_CONFIG%% "..debug_option.." --cflags`" )
+		table.insert( package.config["Release"].buildoptions, "`%%WX_CONFIG%% --debug=no --cflags`" )
 		
 		-- Set the wxWidgets link options.
-		table.insert( package.config["Debug"].linkoptions, "`wx-config "..debug_option.." --libs`" )
-		table.insert( package.config["Release"].linkoptions, "`wx-config --libs`" )
+		table.insert( package.config["Debug"].linkoptions, "`%%WX_CONFIG%% "..debug_option.." --libs`" )
+		table.insert( package.config["Release"].linkoptions, "`%%WX_CONFIG%% --libs`" )
 		
 		-- Set the Linux defines.
 		table.insert( package.defines, "__WXGTK__" )
@@ -212,8 +212,8 @@ function ConfigureWxWidgets( package, al
 			package.config["Release"].target = targetName
 			package.config["Debug"].target = targetName.."d"
 		else
-			package.config["Debug"].target = "`wx-config "..debug_option.." --basename`_"..targetName.."-`wx-config --release`"
-			package.config["Release"].target = "`wx-config --basename`_"..targetName.."-`wx-config --release`"
+			package.config["Debug"].target = "`%%WX_CONFIG%% "..debug_option.." --basename`_"..targetName.."-`%%WX_CONFIG%% --release`"
+			package.config["Release"].target = "`%%WX_CONFIG%% --basename`_"..targetName.."-`%%WX_CONFIG%% --release`"
 		end
 	end
 end
