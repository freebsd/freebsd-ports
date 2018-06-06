--- api/logic/minecraft/MinecraftInstance.cpp.orig	2017-12-18 00:19:43 UTC
+++ api/logic/minecraft/MinecraftInstance.cpp
@@ -163,7 +163,11 @@ QString MinecraftInstance::binRoot() con
 
 QString MinecraftInstance::getNativePath() const
 {
+#if defined(Q_OS_FREEBSD)
+	QDir natives_dir(LWJGL_DIR "/");
+#else
 	QDir natives_dir(FS::PathCombine(instanceRoot(), "natives/"));
+#endif
 	return natives_dir.absolutePath();
 }
 
