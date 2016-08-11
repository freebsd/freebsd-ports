--- src/VBox/Devices/Audio/DrvHostALSAAudio.cpp.orig	2016-07-18 11:52:55 UTC
+++ src/VBox/Devices/Audio/DrvHostALSAAudio.cpp
@@ -982,6 +982,7 @@ static DECLCALLBACK(int) drvHostALSAAudi
                             continue;
                         }
 
+#if EPIPE != ESTRPIPE
                         case -ESTRPIPE:
                         {
                             /* Stream was suspended and waiting for a recovery. */
@@ -995,6 +996,7 @@ static DECLCALLBACK(int) drvHostALSAAudi
                             LogFlowFunc(("Resumed suspended output stream\n"));
                             continue;
                         }
+#endif
 
                         default:
                             LogFlowFunc(("Failed to write %RI32 output frames, rc=%Rrc\n",
