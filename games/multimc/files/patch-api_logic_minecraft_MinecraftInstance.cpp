--- api/logic/minecraft/MinecraftInstance.cpp.orig	2019-03-08 14:41:15 UTC
+++ api/logic/minecraft/MinecraftInstance.cpp
@@ -161,7 +161,11 @@ QString MinecraftInstance::binRoot() const
 
 QString MinecraftInstance::getNativePath() const
 {
+#if defined(Q_OS_FREEBSD)
+	QDir natives_dir(LWJGL_DIR "/");
+#else
     QDir natives_dir(FS::PathCombine(instanceRoot(), "natives/"));
+#endif
     return natives_dir.absolutePath();
 }
 
