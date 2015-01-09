--- src/csound.cpp.orig	2013-12-24 23:45:41.000000000 -0800
+++ src/csound.cpp	2015-01-09 11:00:21.000000000 -0800
@@ -21,7 +21,7 @@
 
 using namespace std;
 extern Parameter settings;
-CSound::CSound ( int ptt = -1 ) : Input ( ptt )
+CSound::CSound ( int ptt ) : Input ( ptt )
 {
   started = false;
   output = false;
@@ -41,7 +41,13 @@
     return 0;
   if ( anzahl > available )
     return 0;
-  memcpy ( sample, &buffer[readPointer], anzahl*sizeof ( double ) ) ;
+  for (int i=0; i<anzahl; i++) {
+	sample[i] = (double)buffer[readPointer+i] / 0x7fffffff;
+	if (sample[i] < -1.0)
+	  sample[i] = -1.0;
+	else if(sample[i] > 1.0)
+	  sample[i] = 1.0;
+  }
   LockPointers.lock();
   available -= anzahl;
   free += anzahl;
@@ -101,10 +107,10 @@
     return false;
   }
   /* Set the sample format */
-  err = snd_pcm_hw_params_set_format ( handle, hwparams, SND_PCM_FORMAT_FLOAT_LE );
+  err = snd_pcm_hw_params_set_format ( handle, hwparams, SND_PCM_FORMAT_S32 );
   if ( err < 0 )
   {
-    *errorstring = QString ( "Sample format Float not available : " ) + QString ( snd_strerror ( err ) );
+    *errorstring = QString ( "Sample format Signed 32-bit not available : " ) + QString ( snd_strerror ( err ) );
     return false;
   }
   /* Set the count of channels, most soundcards only support stereo */
@@ -229,10 +235,10 @@
     return false;
   }
   /* Set the sample format */
-  err = snd_pcm_hw_params_set_format ( handle, hwparams, SND_PCM_FORMAT_FLOAT_LE );
+  err = snd_pcm_hw_params_set_format ( handle, hwparams, SND_PCM_FORMAT_S32 );
   if ( err < 0 )
   {
-    *errorstring = QString ( "Sample format Float not available : " ) + QString ( snd_strerror ( err ) );
+    *errorstring = QString ( "Sample format Signed 32-bit not available : " ) + QString ( snd_strerror ( err ) );
     return false;
   }
   /* Set the count of channels */
@@ -305,7 +311,8 @@
 {
   if ( anzahl <= free )
   {
-    memcpy ( &buffer[freePointer], sample, anzahl*sizeof ( double ) );
+	for (int i=0; i<anzahl; i++)
+	  buffer[freePointer+i] = sample[i] * 0x7fffffff;
     LockPointers.lock();
     toBePlayed += anzahl;
     free -= anzahl;
@@ -394,7 +401,7 @@
 void CSound::record()
 {
   int toBeRead, err;
-  float SampleBuffer[256];
+  int32_t SampleBuffer[256];
   qDebug ( "Start recording" );
   while ( started )
   {
@@ -447,7 +454,7 @@
 
 void CSound::play()
 {
-  float SampleBuffer[256], x;
+  int32_t SampleBuffer[256], x;
   bool signaled;
   int err, laenge;
   laenge = 128;
