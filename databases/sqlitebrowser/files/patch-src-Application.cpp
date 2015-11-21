--- src/Application.cpp.orig	2015-06-14 10:13:37 UTC
+++ src/Application.cpp
@@ -30,8 +30,15 @@ Application::Application(int& argc, char
 
     // First of all try to load the application translation file.
     m_translatorApp = new QTranslator(this);
+
+#ifdef Q_OS_FREEBSD
+    QString trans_dir = "%%DATADIR%%/translations";
+    ok = m_translatorApp->load("sqlb_" + name,
+                               trans_dir);
+#else
     ok = m_translatorApp->load("sqlb_" + name,
                                QCoreApplication::applicationDirPath() + "/translations");
+#endif
     // If failed then try to load .qm file from resources
     if (ok == false) {
         ok = m_translatorApp->load("sqlb_" + name, ":/translations");
@@ -51,7 +58,9 @@ Application::Application(int& argc, char
         ok = m_translatorQt->load("qt_" + name,
                                   QLibraryInfo::location(QLibraryInfo::TranslationsPath));
         if (ok == false)
+	{
             ok = m_translatorQt->load("qt_" + name, "translations");
+	}
         if (ok == true)
             installTranslator(m_translatorQt);
     }
