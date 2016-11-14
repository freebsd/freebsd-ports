--- src/lib/io/kdirwatch.cpp.orig	2016-05-07 15:08:21 UTC
+++ src/lib/io/kdirwatch.cpp
@@ -109,7 +109,7 @@ static KDirWatch::Method methodFromStrin
     } else if (method == "QFSWatch") {
         return KDirWatch::QFSWatch;
     } else {
-#ifdef Q_OS_LINUX
+#if defined(HAVE_SYS_INOTIFY_H)
         // inotify supports delete+recreate+modify, which QFSWatch doesn't support
         return KDirWatch::INotify;
 #else
