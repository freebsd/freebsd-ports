- this patch works together with post-patch: %%PREFIX%% are substituted there

--- qucs/main.cpp.orig	2022-06-30 18:34:40 UTC
+++ qucs/main.cpp
@@ -114,10 +114,10 @@ bool loadSettings()
         if (QucsSettings.Qucsconv.isEmpty())
             QucsSettings.Qucsconv = QucsSettings.QucsatorDir + QDir::separator() + "qucsconv" + executableSuffix;
     } else {
-        QucsSettings.Qucsator = QucsSettings.BinDir + "qucsator" + executableSuffix;
+        QucsSettings.Qucsator = "%%PREFIX%%/bin/qucsator";
         QucsSettings.QucsatorDir = QucsSettings.BinDir;
         if (QucsSettings.Qucsconv.isEmpty())
-            QucsSettings.Qucsconv = QucsSettings.BinDir + "qucsconv" + executableSuffix;
+            QucsSettings.Qucsconv = "%%PREFIX%%/bin/qucsconv";
     }
     //if(settings.contains("BinDir"))QucsSettings.BinDir = settings.value("BinDir").toString();
     //if(settings.contains("LangDir"))QucsSettings.LangDir = settings.value("LangDir").toString();
@@ -139,13 +139,13 @@ bool loadSettings()
 #ifdef Q_OS_WIN
         QucsSettings.XyceExecutable = "Xyce.exe";
 #else
-        QucsSettings.XyceExecutable = "/usr/local/Xyce-Release-6.8.0-OPENSOURCE/bin/Xyce";
+        QucsSettings.XyceExecutable = "%%PREFIX%%/bin/Xyce";
 #endif
     }
     if(settings.contains("XyceParExecutable")) QucsSettings.XyceParExecutable = settings.value("XyceParExecutable").toString();
-    else QucsSettings.XyceParExecutable = "mpirun -np %p /usr/local/Xyce-Release-6.8.0-OPENMPI-OPENSOURCE/bin/Xyce";
+    else QucsSettings.XyceParExecutable = "mpirun -np %p %%PREFIX%%/bin/Xyce";
     if(settings.contains("SpiceOpusExecutable")) QucsSettings.SpiceOpusExecutable = settings.value("SpiceOpusExecutable").toString();
-    else QucsSettings.SpiceOpusExecutable = "spiceopus";
+    else QucsSettings.SpiceOpusExecutable = "%%PREFIX%%/bin/spiceopus";
     if(settings.contains("Nprocs")) QucsSettings.NProcs = settings.value("Nprocs").toInt();
     else QucsSettings.NProcs = 4;
     if(settings.contains("S4Q_workdir")) QucsSettings.S4Qworkdir = settings.value("S4Q_workdir").toString();
