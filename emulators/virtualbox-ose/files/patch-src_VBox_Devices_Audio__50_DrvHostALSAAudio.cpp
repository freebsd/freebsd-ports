--- src/VBox/Devices/Audio_50/DrvHostALSAAudio.cpp.orig	2016-11-21 17:27:56 UTC
+++ src/VBox/Devices/Audio_50/DrvHostALSAAudio.cpp
@@ -983,6 +983,7 @@ static DECLCALLBACK(int) drvHostALSAAudi
                             continue;
                         }
 
+#if EPIPE != ESTRPIPE
                         case -ESTRPIPE:
                         {
                             /* Stream was suspended and waiting for a recovery. */
@@ -996,6 +997,7 @@ static DECLCALLBACK(int) drvHostALSAAudi
                             LogFlowFunc(("Resumed suspended output stream\n"));
                             continue;
                         }
+#endif
 
                         default:
                             LogFlowFunc(("Failed to write %RI32 output frames, rc=%Rrc\n",
