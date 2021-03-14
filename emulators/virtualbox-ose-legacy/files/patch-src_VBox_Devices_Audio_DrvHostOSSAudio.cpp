--- src/VBox/Devices/Audio/DrvHostOSSAudio.cpp.orig	2020-07-09 16:52:47 UTC
+++ src/VBox/Devices/Audio/DrvHostOSSAudio.cpp
@@ -248,11 +248,11 @@ static int ossStreamOpen(const char *pszDev, int fOpen
                 break;
 
             default:
-                rc = VERR_AUDIO_STREAM_COULD_NOT_CREATE;
+                iFormat = -1;
                 break;
         }
 
-        if (RT_FAILURE(rc))
+        if (RT_UNLIKELY(iFormat == -1))
             break;
 
         if (ioctl(hFile, SNDCTL_DSP_SAMPLESIZE, &iFormat))
@@ -660,6 +660,7 @@ static int ossCreateStreamIn(POSSAUDIOSTREAM pStreamOS
 
                 pCfgAcq->Backend.cfPeriod     = PDMAUDIOSTREAMCFG_B2F(pCfgAcq, ossAcq.cbFragmentSize);
                 pCfgAcq->Backend.cfBufferSize = pCfgAcq->Backend.cfPeriod * 2; /* Use "double buffering". */
+                pCfgAcq->Backend.cfPreBuf     = pCfgAcq->Backend.cfBufferSize;
                 /** @todo Pre-buffering required? */
             }
         }
@@ -778,6 +779,7 @@ static int ossCreateStreamOut(POSSAUDIOSTREAM pStreamO
 #endif
             pCfgAcq->Backend.cfPeriod     = PDMAUDIOSTREAMCFG_B2F(pCfgAcq, obtStream.cbFragmentSize);
             pCfgAcq->Backend.cfBufferSize = pCfgAcq->Backend.cfPeriod * 2; /* Use "double buffering" */
+            pCfgAcq->Backend.cfPreBuf     = pCfgAcq->Backend.cfBufferSize;
         }
 
     } while (0);
