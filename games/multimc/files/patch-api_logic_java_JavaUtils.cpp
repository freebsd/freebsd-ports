--- api/logic/java/JavaUtils.cpp.orig	2019-02-20 23:45:36 UTC
+++ api/logic/java/JavaUtils.cpp
@@ -31,7 +31,7 @@ JavaUtils::JavaUtils()
 {
 }
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 static QString processLD_LIBRARY_PATH(const QString & LD_LIBRARY_PATH)
 {
     QDir mmcBin(QCoreApplication::applicationDirPath());
@@ -83,7 +83,7 @@ QProcessEnvironment CleanEnviroment()
             qDebug() << "Env: ignoring" << key << value;
             continue;
         }
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         // Do not pass LD_* variables to java. They were intended for MultiMC
         if(key.startsWith("LD_"))
         {
@@ -112,7 +112,7 @@ QProcessEnvironment CleanEnviroment()
         // qDebug() << "Env: " << key << value;
         env.insert(key, value);
     }
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     // HACK: Workaround for QTBUG42500
     if(!env.contains("LD_LIBRARY_PATH"))
     {
