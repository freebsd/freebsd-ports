--- sound/soundalsa.cpp.orig	2019-04-18 09:34:09 UTC
+++ sound/soundalsa.cpp
@@ -64,6 +64,8 @@ void soundAlsa::prepareCapture()
 {
   int err;
   if(!soundDriverOK) return;
+  snd_pcm_drop(captureHandle);
+  snd_pcm_reset(captureHandle);
   if((err=snd_pcm_prepare (captureHandle)) < 0)
     {
       alsaErrorHandler(err,"Unable to prepare "+inputAudioDevice);
@@ -77,6 +79,8 @@ void soundAlsa::prepareCapture()
 void soundAlsa::preparePlayback()
 {
   if(!soundDriverOK) return;
+  snd_pcm_drop(captureHandle);
+  snd_pcm_reset(captureHandle);
   snd_pcm_prepare (playbackHandle);
 }
 
@@ -99,6 +103,8 @@ int soundAlsa::read(int &countAvailable)
               if ( count == -EPIPE )
                 {
                   // Overrun
+                  snd_pcm_drop(captureHandle);
+                  snd_pcm_reset(captureHandle);
                   snd_pcm_prepare (captureHandle );
                   snd_pcm_start (captureHandle);
                   errorOut() << "Overrun";
@@ -153,6 +159,8 @@ int soundAlsa::write(uint numFrames)
       else if ( framesWritten == -EPIPE )
         {
           /* underrun */
+          snd_pcm_drop(captureHandle);
+          snd_pcm_reset(captureHandle);
           error = snd_pcm_prepare (playbackHandle);
           if ( error < 0 )
             {
@@ -384,5 +392,41 @@ void getCardList(QStringList &alsaInputL
       n++;
     }
   snd_device_name_free_hint(hints);
+
+	snd_config_t	*pcmc;
+	snd_pcm_t	*pcm;
+	if (!snd_config)
+		snd_config_update();
+	if(snd_config_search(snd_config, "pcm", &pcmc)==0) {
+		snd_config_iterator_t i, next;
+		snd_config_for_each(i, next, pcmc) {
+			snd_config_t *n = snd_config_iterator_entry(i);
+			if (snd_config_get_type(n) != SND_CONFIG_TYPE_COMPOUND)
+				continue;
+			const char *id;
+			if(snd_config_get_id(n, &id)==0) {
+				deviceName = QString(id);
+				if (deviceName == "hw" ||
+						deviceName == "plughw" ||
+						deviceName == "plug" ||
+						deviceName == "dsnoop" ||
+						deviceName == "tee" ||
+						deviceName == "file" ||
+						deviceName == "null" ||
+						deviceName == "shm" ||
+						deviceName == "cards" ||
+						deviceName == "rate_convert")
+					continue;
+				if (snd_pcm_open(&pcm, id, SND_PCM_STREAM_PLAYBACK, 0) == 0) {
+					alsaOutputList.append(deviceName + " ");
+					snd_pcm_close(pcm);
+				}
+				if (snd_pcm_open(&pcm, id, SND_PCM_STREAM_CAPTURE, 0) == 0) {
+					alsaInputList.append(deviceName + " ");
+					snd_pcm_close(pcm);
+				}
+			}
+		}
+	}
 }
 
