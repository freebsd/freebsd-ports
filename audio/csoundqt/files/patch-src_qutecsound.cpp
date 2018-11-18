--- src/qutecsound.cpp.orig	2017-11-19 10:59:36 UTC
+++ src/qutecsound.cpp
@@ -267,6 +267,9 @@ CsoundQt::CsoundQt(QStringList fileNames
 #ifdef Q_OS_LINUX
         possibleDirectories  << "/usr/share/doc/csound-manual/html/" << "/usr/share/doc/csound-doc/html/";
 #endif
+#ifdef Q_OS_FREEBSD
+        possibleDirectories  << initialDir+"/../share/doc/csound-manual/html/" << initialDir+"/../share/doc/csound-doc/html/";
+#endif
 #ifdef Q_OS_WIN
         QString programFilesPath = QDir::fromNativeSeparators(getenv("PROGRAMFILES"));
         QString programFilesPathx86 = QDir::fromNativeSeparators(getenv("PROGRAMFILES(X86)"));
@@ -1255,6 +1258,8 @@ void CsoundQt::createApp()
 #ifdef USE_DOUBLE
 #ifdef Q_OS_LINUX
 #endif
+#ifdef Q_OS_FREEBSD
+#endif
 #ifdef Q_OS_SOLARIS
 #endif
 #ifdef Q_OS_WIN32
@@ -1267,6 +1272,8 @@ void CsoundQt::createApp()
 
 #ifdef Q_OS_LINUX
 #endif
+#ifdef Q_OS_FREEBSD
+#endif
 #ifdef Q_OS_SOLARS
 #endif
 #ifdef Q_OS_WIN32
@@ -1314,10 +1321,10 @@ void CsoundQt::createApp()
         wizard.setField("targetDir", appDir);
         if (m_options->sdkDir.isEmpty()) { // No sdk,
             wizard.setField("customPaths", true);
-#if defined(Q_OS_LINUX) || defined(Q_OS_SOLARIS)
-            wizard.setField("libDir", "/usr/lib");
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_SOLARIS)
+            wizard.setField("libDir", QCoreApplication::applicationDirPath()+"/../lib");
             if (opcodeDir.isEmpty()) {
-                wizard.setField("opcodeDir", "/usr/lib/csound/plugins");
+                wizard.setField("opcodeDir", QCoreApplication::applicationDirPath()+"/../lib/csound/plugins64-6.0");
             }
 #endif
 #ifdef Q_OS_WIN32
@@ -1810,6 +1817,9 @@ void CsoundQt::runInTerm(bool realtime)
 #ifdef Q_OS_LINUX
     options = "-e " + scriptFileName;
 #endif
+#ifdef Q_OS_FREEBSD
+    options = "-e " + scriptFileName;
+#endif
 #ifdef Q_OS_SOLARIS
     options = "-e " + scriptFileName;
 #endif
@@ -2797,6 +2807,9 @@ void CsoundQt::runUtility(QString flags)
 #ifdef Q_OS_LINUX
         options = "-e " + SCRIPT_NAME;
 #endif
+#ifdef Q_OS_FREEBSD
+        options = "-e " + SCRIPT_NAME;
+#endif
 #ifdef Q_OS_SOLARIS
         options = "-e " + SCRIPT_NAME;
 #endif
@@ -3911,10 +3924,10 @@ QString CsoundQt::getExamplePath(QString
     examplePath = qApp->applicationDirPath() + "/../Resources/" + dir;
     qDebug() << examplePath;
 #endif
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     examplePath = qApp->applicationDirPath() + "/Examples/" + dir;
     if (!QDir(examplePath).exists()) {
-        examplePath = qApp->applicationDirPath() + "/../src/Examples/" + dir;
+        examplePath = qApp->applicationDirPath() + "/../share/examples/CsoundQt/" + dir;
     }
     if (!QDir(examplePath).exists()) { // for out of tree builds
         examplePath = qApp->applicationDirPath() + "/../../csoundqt/src/Examples/" + dir;
@@ -4380,7 +4393,7 @@ void CsoundQt::fillFileMenu()
         templatePath = qApp->applicationDirPath() + "/../templates/";
         qDebug() << templatePath;
 #endif
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         templatePath = qApp->applicationDirPath() + "/templates/";
         if (!QDir(templatePath).exists()) {
             templatePath = qApp->applicationDirPath() + "/../templates/";
@@ -5058,6 +5071,9 @@ int CsoundQt::execute(QString executable
 #ifdef Q_OS_LINUX
     QString commandLine = "\"" + executable + "\" " + options;
 #endif
+#ifdef Q_OS_FREEBSD
+    QString commandLine = "\"" + executable + "\" " + options;
+#endif
 #ifdef Q_OS_HAIKU
     QString commandLine = "\"" + executable + "\" " + options;
 #endif
