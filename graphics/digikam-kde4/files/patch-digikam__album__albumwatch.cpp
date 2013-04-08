--- ./digikam/album/albumwatch.cpp.orig	2013-04-04 16:03:45.920385000 +0000
+++ ./digikam/album/albumwatch.cpp	2013-04-04 16:04:05.410385977 +0000
@@ -278,7 +278,7 @@
             // Disable file watch for OS X and Windows and hope for future
             // improvement (possibly with the improvements planned for
             // QFileSystemWatcher in Qt 5.1)
-#if defined(Q_WS_MAC) || defined(Q_WS_WIN)
+#if defined(Q_WS_MAC) || defined(Q_WS_WIN) || defined(Q_OS_FREEBSD)
             d->dirWatch->addDir(dir, KDirWatch::WatchDirOnly);
 #else
             d->dirWatch->addDir(dir, KDirWatch::WatchFiles | KDirWatch::WatchDirOnly);
