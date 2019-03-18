--- libraries/iconfix/internal/qiconloader.cpp.orig	2019-03-09 17:22:58 UTC
+++ libraries/iconfix/internal/qiconloader.cpp
@@ -320,7 +320,7 @@ Description: Make it so that the QIcon loader honors /
              icon theme specification.
 Bug: https://bugreports.qt.nokia.com/browse/QTBUG-12874
  *********************************************************************/
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     /* Freedesktop standard says to look in /usr/share/pixmaps last */
     if (entries.isEmpty())
     {
