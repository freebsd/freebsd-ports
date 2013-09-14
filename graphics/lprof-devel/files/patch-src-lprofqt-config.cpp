--- ./src/lprofqt/config.cpp.orig	2008-03-09 01:31:11.000000000 +0300
+++ ./src/lprofqt/config.cpp	2013-09-14 04:36:26.160226093 +0400
@@ -206,7 +206,7 @@
     const QString assist = QString::fromLocal8Bit("assistant.app/Contents/MacOS/assistant");
 # else
     QChar pathSep = QChar::fromLatin1(':');
-    const QString assist = QString::fromLocal8Bit("assistant");
+    const QString assist = QString::fromLocal8Bit("assistant-qt4");
 # endif /* __WIN32__ */
     
     QString Path = QString::fromLocal8Bit(getenv("PATH"));
