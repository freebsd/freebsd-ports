--- ./digikam/album/albumwatch.cpp.orig	2012-09-05 19:38:42.000000000 -0400
+++ ./digikam/album/albumwatch.cpp	2012-09-05 19:40:59.000000000 -0400
@@ -221,7 +221,7 @@
             #ifdef Q_WS_MAC
             d->dirWatch->addDir(dir, KDirWatch::WatchDirOnly);
             #else
-            d->dirWatch->addDir(dir, KDirWatch::WatchFiles | KDirWatch::WatchDirOnly);
+            d->dirWatch->addDir(dir, KDirWatch::WatchDirOnly);
             #endif
         }
     }
