--- src/Misc/Config.cpp.orig	2011-12-19 21:14:30 UTC
+++ src/Misc/Config.cpp
@@ -84,10 +84,9 @@ void Config::init()
         //banks
         cfg.bankRootDirList[0] = "~/banks";
         cfg.bankRootDirList[1] = "./";
-        cfg.bankRootDirList[2] = "/usr/share/zynaddsubfx/banks";
-        cfg.bankRootDirList[3] = "/usr/local/share/zynaddsubfx/banks";
-        cfg.bankRootDirList[4] = "../banks";
-        cfg.bankRootDirList[5] = "banks";
+        cfg.bankRootDirList[2] = "%%DATADIR%%/banks";
+        cfg.bankRootDirList[3] = "../banks";
+        cfg.bankRootDirList[4] = "banks";
     }
 
     if(cfg.presetsDirList[0].empty()) {
@@ -95,8 +94,7 @@ void Config::init()
         cfg.presetsDirList[0] = "./";
         cfg.presetsDirList[1] = "../presets";
         cfg.presetsDirList[2] = "presets";
-        cfg.presetsDirList[3] = "/usr/share/zynaddsubfx/presets";
-        cfg.presetsDirList[4] = "/usr/local/share/zynaddsubfx/presets";
+        cfg.presetsDirList[3] = "%%DATADIR%%/presets";
     }
     cfg.LinuxALSAaudioDev = "default";
     cfg.nameTag = "";
