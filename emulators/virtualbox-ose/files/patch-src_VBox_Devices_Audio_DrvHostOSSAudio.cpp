--- src/VBox/Devices/Audio/DrvHostOSSAudio.cpp.orig	2021-01-07 15:37:12 UTC
+++ src/VBox/Devices/Audio/DrvHostOSSAudio.cpp
@@ -253,10 +253,11 @@ static int ossStreamOpen(const char *pszDev, int fOpen
 
             default:
                 rc = VERR_AUDIO_STREAM_COULD_NOT_CREATE;
+                iFormat = -1;				
                 break;
         }
 
-        if (RT_FAILURE(rc))
+        if (RT_UNLIKELY(iFormat == -1))
             break;
 
         if (ioctl(fdFile, SNDCTL_DSP_SAMPLESIZE, &iFormat))
@@ -664,6 +665,7 @@ static int ossCreateStreamIn(POSSAUDIOSTREAM pStreamOS
 
                 pCfgAcq->Backend.cFramesPeriod     = PDMAUDIOSTREAMCFG_B2F(pCfgAcq, ossAcq.cbFragmentSize);
                 pCfgAcq->Backend.cFramesBufferSize = pCfgAcq->Backend.cFramesPeriod * 2; /* Use "double buffering". */
+                pCfgAcq->Backend.cFramesPreBuffering     = pCfgAcq->Backend.cFramesBufferSize;                
                 /** @todo Pre-buffering required? */
             }
         }
@@ -782,6 +784,7 @@ static int ossCreateStreamOut(POSSAUDIOSTREAM pStreamO
 #endif
             pCfgAcq->Backend.cFramesPeriod     = PDMAUDIOSTREAMCFG_B2F(pCfgAcq, obtStream.cbFragmentSize);
             pCfgAcq->Backend.cFramesBufferSize = pCfgAcq->Backend.cFramesPeriod * 2; /* Use "double buffering" */
+            pCfgAcq->Backend.cFramesPreBuffering     = pCfgAcq->Backend.cFramesBufferSize;            
         }
 
     } while (0);
