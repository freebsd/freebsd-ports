--- src/VBox/Devices/Audio/DrvHostAudioAlsa.cpp.orig	2021-04-20 04:27:52 UTC
+++ src/VBox/Devices/Audio/DrvHostAudioAlsa.cpp
@@ -833,6 +833,7 @@ static DECLCALLBACK(int) drvHostAlsaAudioHA_StreamPlay
                         continue;
                     }
 
+#if EPIPE != ESTRPIPE
                     case -ESTRPIPE:
                     {
                         /* Stream was suspended and waiting for a recovery. */
@@ -846,6 +847,7 @@ static DECLCALLBACK(int) drvHostAlsaAudioHA_StreamPlay
                         LogFlowFunc(("Resumed suspended output stream\n"));
                         continue;
                     }
+#endif
 
                     default:
                         LogFlowFunc(("Failed to write %RU32 bytes, error unknown\n", cbToWrite));
