diff -r -c tse3-0.2.7.old/src/tse3/plt/OSS.cpp tse3-0.2.7/src/tse3/plt/OSS.cpp
*** src/tse3/plt/OSS.cpp.orig	Tue Oct 22 09:29:29 2002
--- src/tse3/plt/OSS.cpp	Wed Nov 12 16:13:39 2003
***************
*** 1484,1494 ****
  #ifdef TSE3_WITH_OSS
      // Happily, if you switch -pedantic on in gcc these macros will always
      // throw up warnings. Marvel at the beauty of awe_voice.h for reasons why.
! 
      AWE_SET_CHANNEL_MODE(deviceno, AWE_PLAY_MULTI);
      AWE_SET_CHANNEL_MODE(deviceno, 1);
      AWE_DRUM_CHANNELS(deviceno, 1<<9);
      AWE_TERMINATE_ALL(deviceno);
      seqbuf_dump();
  #endif
  }
--- 1484,1495 ----
  #ifdef TSE3_WITH_OSS
      // Happily, if you switch -pedantic on in gcc these macros will always
      // throw up warnings. Marvel at the beauty of awe_voice.h for reasons why.
! #if 0
      AWE_SET_CHANNEL_MODE(deviceno, AWE_PLAY_MULTI);
      AWE_SET_CHANNEL_MODE(deviceno, 1);
      AWE_DRUM_CHANNELS(deviceno, 1<<9);
      AWE_TERMINATE_ALL(deviceno);
+ #endif
      seqbuf_dump();
  #endif
  }
***************
*** 1996,2002 ****
          // there is no soundcard
          throw TSE3::MidiSchedulerError(TSE3::MidiSchedulerCreateErr);
      }
!     ioctl(seqfd, SNDCTL_SEQ_NRMIDIS, &nomidis);
      rate = 0;
      ioctl(seqfd, SNDCTL_SEQ_CTRLRATE, &rate);
      if (rate == -1 || rate <= 0) rate = 100;
--- 1997,2004 ----
          // there is no soundcard
          throw TSE3::MidiSchedulerError(TSE3::MidiSchedulerCreateErr);
      }
!     // ioctl(seqfd, SNDCTL_SEQ_NRMIDIS, &nomidis);
!     nomidis = 0;
      rate = 0;
      ioctl(seqfd, SNDCTL_SEQ_CTRLRATE, &rate);
      if (rate == -1 || rate <= 0) rate = 100;
***************
*** 2044,2049 ****
--- 2046,2059 ----
                  }
                  std::cout << ")\n";
              }
+ #if 1
+ 	    devices[n]
+ 		= new OSSMidiScheduler_AWEDevice(n, synthinfo[n], seqfd,
+ 						 _seqbuf, _seqbuflen,
+ 						 _seqbufptr);
+ 	}
+     }
+ #else	
              if (synthinfo[n].synth_type == SYNTH_TYPE_SAMPLE
                  && synthinfo[n].synth_subtype == SAMPLE_TYPE_AWE32)
              {
***************
*** 2100,2105 ****
--- 2110,2116 ----
         }
      }
  
+ #endif
      // Now let the public API know about these devices
      for (unsigned int n = 0; n < nodevices; ++n)
      {
Only in tse3-0.2.7/src/tse3/plt: OSS.cpp.orig
