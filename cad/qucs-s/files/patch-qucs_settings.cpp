- this patch works together with post-patch: %%LOCALBASE%% are substituted there

--- qucs/settings.cpp.orig	2025-03-14 13:47:08 UTC
+++ qucs/settings.cpp
@@ -62,7 +62,7 @@ void settingsManager::initDefaults()
 #else
     m_Defaults["NgspiceExecutable"] = "ngspice";
     #ifndef Q_OS_MACOS
-        m_Defaults["XyceExecutable"] = "/usr/local/Xyce-Release-6.8.0-OPENSOURCE/bin/Xyce";
+        m_Defaults["XyceExecutable"] = "%%LOCALBASE%%/bin/Xyce";
     #else
         m_Defaults["XyceExecutable"] = "Xyce";
     #endif
@@ -70,7 +70,7 @@ void settingsManager::initDefaults()
     m_Defaults["OctaveExecutable"] = "octave";
 #endif
 
-    m_Defaults["XyceParExecutable"] = "mpirun -np %p /usr/local/Xyce-Release-6.8.0-OPENMPI-OPENSOURCE/bin/Xyce";
+    m_Defaults["XyceParExecutable"] = "mpirun -np %p %%LOCALBASE%%/bin/Xyce";
     m_Defaults["S4Q_workdir"] = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
     m_Defaults["Nprocs"] = 4;
     m_Defaults["SpiceOpusExecutable"] = "spiceopus";
