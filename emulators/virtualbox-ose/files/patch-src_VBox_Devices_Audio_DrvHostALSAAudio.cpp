--- src/VBox/Devices/Audio/DrvHostALSAAudio.cpp.orig	2021-01-07 15:37:12 UTC
+++ src/VBox/Devices/Audio/DrvHostALSAAudio.cpp
@@ -820,6 +820,7 @@ static DECLCALLBACK(int) drvHostAlsaAudioHA_StreamPlay
                         continue;
                     }
 
+#if EPIPE != ESTRPIPE
                     case -ESTRPIPE:
                     {
                         /* Stream was suspended and waiting for a recovery. */
@@ -833,6 +834,7 @@ static DECLCALLBACK(int) drvHostAlsaAudioHA_StreamPlay
                         LogFlowFunc(("Resumed suspended output stream\n"));
                         continue;
                     }
+#endif
 
                     default:
                         LogFlowFunc(("Failed to write %RU32 bytes, error unknown\n", cbToWrite));
