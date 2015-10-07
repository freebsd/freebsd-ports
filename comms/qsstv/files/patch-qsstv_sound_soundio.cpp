--- qsstv/sound/soundio.cpp.orig	2015-02-28 15:05:28 UTC
+++ qsstv/sound/soundio.cpp
@@ -328,7 +328,9 @@ int soundIO::capture()
               if ( count == -EPIPE )
                 {
                   // Overrun
-                  snd_pcm_prepare (captureHandle );
+                  snd_pcm_drop (captureHandle);
+                  snd_pcm_reset (captureHandle);
+                  snd_pcm_prepare (captureHandle);
                   snd_pcm_start (captureHandle);
                   qDebug()<< "Overrun";
                 }
@@ -573,8 +575,6 @@ bool soundIO::listCards()
 //  int totalDevices;
   snd_pcm_info_t *pcmInfo;
   snd_ctl_t *cardHandle;
-  inputPCMNameList << "default";
-  outputPCMNameList << "default";
 
   // No cards found yet
   totalCards = 0;
@@ -582,6 +582,11 @@ bool soundIO::listCards()
   // Start with first card
   cardNum = -1;
 
+  // We need to get a snd_ctl_card_info_t. Just alloc it on the stack
+  snd_ctl_card_info_alloca(&cardInfo);
+  // To get some info about the subdevices of this wave device (on the card), we need a
+  // snd_pcm_info_t, so let's allocate one on the stack
+  snd_pcm_info_alloca(&pcmInfo);
   for (;;)
     {
 
@@ -599,8 +604,6 @@ bool soundIO::listCards()
           qDebug() << "Can't open card "<< cardNum << snd_strerror(err);
           continue;
         }
-      // We need to get a snd_ctl_card_info_t. Just alloc it on the stack
-      snd_ctl_card_info_alloca(&cardInfo);
 
       // Tell ALSA to fill in our snd_ctl_card_info_t with info about this card
       if ((err = snd_ctl_card_info(cardHandle, cardInfo)) >= 0)
@@ -619,9 +622,6 @@ bool soundIO::listCards()
           // NOTE: It's possible that this sound card may have no wave devices on it
           // at all, for example if it's only a MIDI card
           if (devNum < 0) break;
-          // To get some info about the subdevices of this wave device (on the card), we need a
-          // snd_pcm_info_t, so let's allocate one on the stack
-          snd_pcm_info_alloca(&pcmInfo);
           memset(pcmInfo, 0, snd_pcm_info_sizeof());
 
           // Tell ALSA which device (number) we want info about
@@ -636,6 +636,22 @@ bool soundIO::listCards()
 //      qDebug() << "Found:" << totalDevices << " digital audio devices on card " <<  cardNum;
     }
 
+	snd_config_t	*pcm;
+	snd_config_update();
+	if(snd_config_search(snd_config, "pcm", &pcm)==0) {
+		snd_config_iterator_t i, next;
+		snd_config_for_each(i, next, pcm) {
+			snd_config_t *n = snd_config_iterator_entry(i);
+			if (snd_config_get_type(n) != SND_CONFIG_TYPE_COMPOUND)
+				continue;
+			const char *id;
+			if(snd_config_get_id(n, &id)==0) {
+				inputPCMNameList << id;
+				outputPCMNameList << id;
+			}
+		}
+	}
+
 //  qDebug() << "ALSA found cards" << totalCards;
 
   // ALSA allocates some mem to load its config file when we call
