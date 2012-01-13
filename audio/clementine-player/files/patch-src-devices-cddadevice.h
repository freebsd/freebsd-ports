--- src/devices/cddadevice.h.orig	2012-01-11 22:39:56.000000000 -0600
+++ src/devices/cddadevice.h	2012-01-11 22:40:33.000000000 -0600
@@ -18,10 +18,10 @@
 #ifndef CDDADEVICE_H
 #define CDDADEVICE_H
 
-#include <cdio/cdio.h>
-#include <gst/cdda/gstcddabasesrc.h>
 #include <QMutex>
 
+#include <cdio/cdio.h>
+#include <gst/cdda/gstcddabasesrc.h>
 #include "connecteddevice.h"
 #include "core/song.h"
 #include "musicbrainz/musicbrainzclient.h"
