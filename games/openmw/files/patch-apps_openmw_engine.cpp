--- apps/openmw/engine.cpp.orig	2015-11-24 02:42:35 UTC
+++ apps/openmw/engine.cpp
@@ -473,8 +473,9 @@ void OMW::Engine::prepareEngine (Setting
     }
 
     // find correct path to the game controller bindings
-    const std::string localdefault = mCfgMgr.getLocalPath().string() + "/gamecontrollerdb.cfg";
-    const std::string globaldefault = mCfgMgr.getGlobalPath().string() + "/gamecontrollerdb.cfg";
+    const std::string localdefault = mCfgMgr.getLocalPath().string() + "/gamecontrollerdb.txt";
+    const std::string globaldefault = mCfgMgr.getGlobalPath().string() + "/gamecontrollerdb.txt";
+
     std::string gameControllerdb;
     if (boost::filesystem::exists(localdefault))
         gameControllerdb = localdefault;
