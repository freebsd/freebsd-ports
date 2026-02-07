--- src/Application.cpp.orig	2024-08-25 17:07:43 UTC
+++ src/Application.cpp
@@ -117,8 +117,16 @@ Application::Application(int& argc, char** argv) :
 
     // First of all try to load the application translation file.
     m_translatorApp = new QTranslator(this);
+
+#ifdef Q_OS_FREEBSD
+    QString trans_dir = "%%DATADIR%%/translations";
     ok = m_translatorApp->load("sqlb_" + name,
+                               trans_dir);
+#else
+    ok = m_translatorApp->load("sqlb_" + name,
                                QCoreApplication::applicationDirPath() + "/translations");
+#endif
+
     // If failed then try to load .qm file from resources
     if (ok == false) {
         ok = m_translatorApp->load("sqlb_" + name, ":/translations");
