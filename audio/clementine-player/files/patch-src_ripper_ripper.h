--- src/ripper/ripper.h.orig	2016-04-19 15:08:35 UTC
+++ src/ripper/ripper.h
@@ -18,9 +18,9 @@
 #ifndef SRC_RIPPER_RIPPER_H_
 #define SRC_RIPPER_RIPPER_H_
 
-#include <cdio/cdio.h>
 #include <QMutex>
 #include <QObject>
+#include <cdio/cdio.h>
 
 #include "core/song.h"
 #include "core/tagreaderclient.h"
