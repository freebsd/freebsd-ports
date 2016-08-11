--- src/tse3/plt/OSS.cpp.orig	2005-07-25 11:22:56 UTC
+++ src/tse3/plt/OSS.cpp
@@ -25,6 +25,7 @@
 #include <fcntl.h>
 #include <stdarg.h>
 #include <sys/types.h>
+#include <cstring>
 
 // These #includes are linux specific and I need to do some autoconf
 // magic to work out how to conditionally include them
@@ -1484,11 +1485,12 @@ OSSMidiScheduler_AWEDevice::OSSMidiSched
 #ifdef TSE3_WITH_OSS
     // Happily, if you switch -pedantic on in gcc these macros will always
     // throw up warnings. Marvel at the beauty of awe_voice.h for reasons why.
-
+#if 0
     AWE_SET_CHANNEL_MODE(deviceno, AWE_PLAY_MULTI);
     AWE_SET_CHANNEL_MODE(deviceno, 1);
     AWE_DRUM_CHANNELS(deviceno, 1<<9);
     AWE_TERMINATE_ALL(deviceno);
+#endif
     seqbuf_dump();
 #endif
 }
@@ -1996,7 +1998,8 @@ OSSMidiScheduler::OSSMidiScheduler()
         // there is no soundcard
         throw TSE3::MidiSchedulerError(TSE3::MidiSchedulerCreateErr);
     }
-    ioctl(seqfd, SNDCTL_SEQ_NRMIDIS, &nomidis);
+    // ioctl(seqfd, SNDCTL_SEQ_NRMIDIS, &nomidis);
+    nomidis = 0;
     rate = 0;
     ioctl(seqfd, SNDCTL_SEQ_CTRLRATE, &rate);
     if (rate == -1 || rate <= 0) rate = 100;
@@ -2044,6 +2047,14 @@ OSSMidiScheduler::OSSMidiScheduler()
                 }
                 std::cout << ")\n";
             }
+#if 1
+	    devices[n]
+		= new OSSMidiScheduler_AWEDevice(n, synthinfo[n], seqfd,
+						 _seqbuf, _seqbuflen,
+						 _seqbufptr);
+	}
+    }
+#else	
             if (synthinfo[n].synth_type == SYNTH_TYPE_SAMPLE
                 && synthinfo[n].synth_subtype == SAMPLE_TYPE_AWE32)
             {
@@ -2100,6 +2111,7 @@ OSSMidiScheduler::OSSMidiScheduler()
        }
     }
 
+#endif
     // Now let the public API know about these devices
     for (unsigned int n = 0; n < nodevices; ++n)
     {
