# Patch taken from er2off: https://github.com/er2off/freebsd-ports
--- launcher/minecraft/MinecraftInstance.cpp.orig        2023-11-27 12:44:40 UTC
+++ launcher/minecraft/MinecraftInstance.cpp
@@ -305,7 +305,16 @@ QString MinecraftInstance::getNativePath() const
 
 QString MinecraftInstance::getNativePath() const
 {
+#ifdef Q_OS_FREEBSD
+    Version instance_ver{ getPackProfile()->getComponentVersion("net.minecraft") };
+    QDir natives_dir;
+    if (instance_ver < Version("1.13.0"))
+        natives_dir = QDir("%%LOCALBASE%%/lib/lwjgl/");
+    else
+        natives_dir = QDir("%%LOCALBASE%%/lib/lwjgl3/");
+#else
     QDir natives_dir(FS::PathCombine(instanceRoot(), "natives/"));
+#endif
     return natives_dir.absolutePath();
 }
 
