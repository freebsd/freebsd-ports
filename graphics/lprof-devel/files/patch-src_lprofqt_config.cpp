The function get_QTDIR reads the environment variable 'QTDIR'. Which is not set
most of the time. So define a sensible fallback value, and return that one in
this case.

This should help the program find the assistant binary, without going over
qtchooser (and requiring to set QT_SELECT).

--- src/lprofqt/config.cpp.orig	2017-02-04 19:46:56 UTC
+++ src/lprofqt/config.cpp
@@ -72,7 +72,9 @@ QString get_QTDIR()
 {
     // qDebug(QString::fromLocal8Bit("get_home_dir"));
     const char* qtdir= "QTDIR";
-    return QString::fromLocal8Bit(getenv(qtdir));
+    const QString fallback = "%%QT_ARCHDIR%%";
+    QString env_qtdir = QString::fromLocal8Bit(getenv(qtdir));
+    return (env_qtdir.isEmpty() ? fallback : env_qtdir);
 }

 void init_env()
