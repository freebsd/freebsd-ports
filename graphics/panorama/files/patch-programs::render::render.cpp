--- programs/render/render.cpp.bak	Thu Nov 21 06:30:00 2002
+++ programs/render/render.cpp	Thu Nov 21 06:52:35 2002
@@ -169,12 +169,12 @@
     _tLocalPath = std::string (pcEnv) + "/.panorama/";
     if ( !FileExists (_tLocalPath + "config") )
     {
-      _tLocalPath = "/etc/panorama/";
+      _tLocalPath = _tTopDir + "/etc/panorama/";
     }
   }
   else
   {
-    _tLocalPath = "/etc/panorama/";
+    _tLocalPath = _tTopDir + "/etc/panorama/";
   }
 
   _tLogFileName = _tLocalPath + "panorama.log";
