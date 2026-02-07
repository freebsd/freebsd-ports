--- src/qutecsound.cpp.orig	2020-01-12 07:45:31 UTC
+++ src/qutecsound.cpp
@@ -279,6 +279,9 @@ CsoundQt::CsoundQt(QStringList fileNames)
 #ifdef Q_OS_LINUX
         possibleDirectories  << "/usr/share/doc/csound-manual/html/" << "/usr/share/doc/csound-doc/html/";
 #endif
+#ifdef Q_OS_FREEBSD
+        possibleDirectories  << initialDir+"/../share/doc/csound-manual/html/" << initialDir+"/../share/doc/csound-doc/html/";
+#endif
 #ifdef Q_OS_WIN
         QString programFilesPath = QDir::fromNativeSeparators(getenv("PROGRAMFILES"));
         QString programFilesPathx86 = QDir::fromNativeSeparators(getenv("PROGRAMFILES(X86)"));
@@ -1299,6 +1302,8 @@ void CsoundQt::createApp()
 #ifdef USE_DOUBLE
 #ifdef Q_OS_LINUX
 #endif
+#ifdef Q_OS_FREEBSD
+#endif
 #ifdef Q_OS_SOLARIS
 #endif
 #ifdef Q_OS_WIN32
@@ -1311,6 +1316,8 @@ void CsoundQt::createApp()
 
 #ifdef Q_OS_LINUX
 #endif
+#ifdef Q_OS_FREEBSD
+#endif
 #ifdef Q_OS_SOLARS
 #endif
 #ifdef Q_OS_WIN32
@@ -1358,10 +1365,10 @@ void CsoundQt::createApp()
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
@@ -1899,6 +1906,9 @@ void CsoundQt::runInTerm(bool realtime)
 #ifdef Q_OS_LINUX
     options = "-e " + scriptFileName;
 #endif
+#ifdef Q_OS_FREEBSD
+    options = "-e " + scriptFileName;
+#endif
 #ifdef Q_OS_SOLARIS
     options = "-e " + scriptFileName;
 #endif
@@ -2896,6 +2906,9 @@ void CsoundQt::runUtility(QString flags)
 #ifdef Q_OS_LINUX
         options = "-e " + SCRIPT_NAME;
 #endif
+#ifdef Q_OS_FREEBSD
+        options = "-e " + SCRIPT_NAME;
+#endif
 #ifdef Q_OS_SOLARIS
         options = "-e " + SCRIPT_NAME;
 #endif
@@ -4024,8 +4037,8 @@ QString CsoundQt::getExamplePath(QString dir)
     examplePath = qApp->applicationDirPath() + "/../Resources/" + dir;
     qDebug() << examplePath;
 #endif
-#ifdef Q_OS_LINUX
-    examplePath = QString(); //qApp->applicationDirPath() + "/Examples/" + dir;
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+    examplePath = qApp->applicationDirPath() + "/../share/examples/CsoundQt/" + dir;
     QStringList possiblePaths;
     possiblePaths << qApp->applicationDirPath() + "/Examples/" << "~/.local/share/csoundqt/Examples/"
                   << "/usr/share/csoundqt/Examples/" << qApp->applicationDirPath() + "/../src/Examples/"
@@ -4507,7 +4520,7 @@ void CsoundQt::fillFileMenu()
         templatePath = qApp->applicationDirPath() + "/../templates/";
         qDebug() << templatePath;
 #endif
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         templatePath = qApp->applicationDirPath() + "/templates/";
         if (!QDir(templatePath).exists()) {
             templatePath = qApp->applicationDirPath() + "/../templates/";
@@ -5196,6 +5209,9 @@ int CsoundQt::execute(QString executable, QString opti
     QString commandLine = "open -a \"" + executable + "\" " + options;
 #endif
 #ifdef Q_OS_LINUX
+    QString commandLine = "\"" + executable + "\" " + options;
+#endif
+#ifdef Q_OS_FREEBSD
     QString commandLine = "\"" + executable + "\" " + options;
 #endif
 #ifdef Q_OS_HAIKU
