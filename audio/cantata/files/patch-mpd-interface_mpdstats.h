https://github.com/CDrummond/cantata/pull/1052

--- mpd-interface/mpdstats.h.orig	2017-07-30 19:13:05 UTC
+++ mpd-interface/mpdstats.h
@@ -27,6 +27,7 @@
 #ifndef MPD_STATS_H
 #define MPD_STATS_H
 
+#include <ctime>
 #include <QDateTime>
 #include <QObject>
 
