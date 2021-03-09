--- src/VBox/Devices/Audio/DrvHostALSAAudio.cpp.orig	2020-05-13 19:39:41 UTC
+++ src/VBox/Devices/Audio/DrvHostALSAAudio.cpp
@@ -819,6 +819,7 @@ static DECLCALLBACK(int) drvHostALSAAudioStreamPlay(PP
                         continue;
                     }
 
+#if EPIPE != ESTRPIPE
                     case -ESTRPIPE:
                     {
                         /* Stream was suspended and waiting for a recovery. */
@@ -832,6 +833,7 @@ static DECLCALLBACK(int) drvHostALSAAudioStreamPlay(PP
                         LogFlowFunc(("Resumed suspended output stream\n"));
                         continue;
                     }
+#endif
 
                     default:
                         LogFlowFunc(("Failed to write %RU32 bytes, error unknown\n", cbToWrite));
