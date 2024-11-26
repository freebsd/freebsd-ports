Fix conflicting definitions of NULL beween glib and cdio when CDIO option
is enabled.

https://github.com/strawberrymusicplayer/strawberry/issues/1610

--- src/device/cddadevice.h.orig	2024-11-23 16:55:49 UTC
+++ src/device/cddadevice.h
@@ -24,13 +24,14 @@
 
 #include "config.h"
 
-#include <cdio/cdio.h>
-#include <gst/audio/gstaudiocdsrc.h>
-
 #include <QObject>
 #include <QString>
 #include <QStringList>
 #include <QUrl>
+
+// These must come after Qt includes
+#include <cdio/cdio.h>
+#include <gst/audio/gstaudiocdsrc.h>
 
 #include "includes/shared_ptr.h"
 #include "core/song.h"
