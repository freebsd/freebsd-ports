--- api/logic/java/JavaUtils.cpp.orig	2017-12-18 00:19:43 UTC
+++ api/logic/java/JavaUtils.cpp
@@ -81,7 +81,7 @@ QProcessEnvironment CleanEnviroment()
 			qDebug() << "Env: ignoring" << key << value;
 			continue;
 		}
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 		// Do not pass LD_* variables to java. They were intended for MultiMC
 		if(key.startsWith("LD_"))
 		{
@@ -110,7 +110,7 @@ QProcessEnvironment CleanEnviroment()
 		qDebug() << "Env: " << key << value;
 		env.insert(key, value);
 	}
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	// HACK: Workaround for QTBUG42500
 	if(!env.contains("LD_LIBRARY_PATH"))
 	{
@@ -291,7 +291,7 @@ QList<QString> JavaUtils::FindJavaPaths(
 	return javas;
 }
 
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 QList<QString> JavaUtils::FindJavaPaths()
 {
 	qDebug() << "Linux Java detection incomplete - defaulting to \"java\"";
