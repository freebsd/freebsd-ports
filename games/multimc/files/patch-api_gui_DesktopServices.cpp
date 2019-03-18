--- api/gui/DesktopServices.cpp.orig	2019-02-20 23:45:36 UTC
+++ api/gui/DesktopServices.cpp
@@ -7,7 +7,7 @@
 /**
  * This shouldn't exist, but until QTBUG-9328 and other unreported bugs are fixed, it needs to be a thing.
  */
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 #include <unistd.h>
 #include <errno.h>
@@ -83,7 +83,7 @@ bool openDirectory(const QString &path, bool ensureExi
     {
         return QDesktopServices::openUrl(QUrl::fromLocalFile(dir.absolutePath()));
     };
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     return IndirectOpen(f);
 #else
     return f();
@@ -97,7 +97,7 @@ bool openFile(const QString &path)
     {
         return QDesktopServices::openUrl(QUrl::fromLocalFile(path));
     };
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     return IndirectOpen(f);
 #else
     return f();
@@ -107,7 +107,7 @@ bool openFile(const QString &path)
 bool openFile(const QString &application, const QString &path, const QString &workingDirectory, qint64 *pid)
 {
     qDebug() << "Opening file" << path << "using" << application;
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     // FIXME: the pid here is fake. So if something depends on it, it will likely misbehave
     return IndirectOpen([&]()
     {
@@ -121,7 +121,7 @@ bool openFile(const QString &application, const QStrin
 bool run(const QString &application, const QStringList &args, const QString &workingDirectory, qint64 *pid)
 {
     qDebug() << "Running" << application << "with args" << args.join(' ');
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     // FIXME: the pid here is fake. So if something depends on it, it will likely misbehave
     return IndirectOpen([&]()
     {
@@ -139,7 +139,7 @@ bool openUrl(const QUrl &url)
     {
         return QDesktopServices::openUrl(url);
     };
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     return IndirectOpen(f);
 #else
     return f();
