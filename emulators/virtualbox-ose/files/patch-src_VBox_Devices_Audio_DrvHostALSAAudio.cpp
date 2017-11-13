--- src/VBox/Devices/Audio/DrvHostALSAAudio.cpp.orig	2017-10-18 07:09:04 UTC
+++ src/VBox/Devices/Audio/DrvHostALSAAudio.cpp
@@ -1231,6 +1231,7 @@ static DECLCALLBACK(int) drvHostALSAAudioStreamPlay(PP
                         continue;
                     }
 
+#if EPIPE != ESTRPIPE
                     case -ESTRPIPE:
                     {
                         /* Stream was suspended and waiting for a recovery. */
@@ -1244,6 +1245,7 @@ static DECLCALLBACK(int) drvHostALSAAudioStreamPlay(PP
                         LogFlowFunc(("Resumed suspended output stream\n"));
                         continue;
                     }
+#endif
 
                     default:
                         LogFlowFunc(("Failed to write %RU32 bytes, error unknown\n", cbToWrite));
