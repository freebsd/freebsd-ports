--- src/audiofileio/encode/SFAudioWriter.h.orig	2019-05-16 08:03:45 UTC
+++ src/audiofileio/encode/SFAudioWriter.h
@@ -25,7 +25,7 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #include "AbstractAudioWriter.h"
 
 #include "defines.h"
-#include "sndfile.h"
+#include <sndfile.h>
 
 #include <QFile>
 
