--- src/audiofileio/decode/SFAudioReader.h.orig	2019-05-16 08:03:28 UTC
+++ src/audiofileio/decode/SFAudioReader.h
@@ -23,7 +23,7 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #define SFAUDIOREADER_H
 
 #include <AbstractAudioReader.h>
-#include "sndfile.h"
+#include <sndfile.h>
 
 #include <QFile>
 
