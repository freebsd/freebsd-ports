https://github.com/CDrummond/cantata/pull/1052

--- mpd-interface/httpstream.cpp.orig	2017-08-01 10:50:50 UTC
+++ mpd-interface/httpstream.cpp
@@ -25,7 +25,9 @@
 #include "mpdconnection.h"
 #include "mpdstatus.h"
 #include "gui/settings.h"
+#ifndef LIBVLC_FOUND
 #include <QtMultimedia/QMediaPlayer>
+#endif
 #include <QTimer>
 
 static const int constPlayerCheckPeriod=250;
