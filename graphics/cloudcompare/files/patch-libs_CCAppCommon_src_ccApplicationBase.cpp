--- libs/CCAppCommon/src/ccApplicationBase.cpp.orig	2024-07-06 10:08:06 UTC
+++ libs/CCAppCommon/src/ccApplicationBase.cpp
@@ -213,7 +213,7 @@ void ccApplicationBase::setupPaths()
 	m_pluginPaths << (appDir.absolutePath() + "/plugins");
 	m_shaderPath = (appDir.absolutePath() + "/shaders");
 	m_translationPath = (appDir.absolutePath() + "/translations");
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	// Shaders & plugins are relative to the bin directory where the executable is found
 	QDir  theDir = appDir;
 
