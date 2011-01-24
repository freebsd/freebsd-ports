--- src/aacPlusEncoder.h.orig	2010-05-10 00:18:48.000000000 +0200
+++ src/aacPlusEncoder.h	2011-01-20 13:41:06.000000000 +0100
@@ -5,8 +5,8 @@
    Tyrell DarkIce
 
    File     : aacPlusEncoder.h
-   Version  : $Revision: 474 $
-   Author   : $Author: rafael@riseup.net $
+   Version  : $Revision$
+   Author   : $Author$
    Location : $HeadURL$
    
    Copyright notice:
@@ -41,18 +41,7 @@
 #endif
 
 #ifdef HAVE_AACPLUS_LIB
-extern "C" {
-#include <libaacplus/cfftn.h>
-#include <libaacplus/FloatFR.h>
-#include <libaacplus/aacenc.h>
-#include <libaacplus/resampler.h>
-
-#include <libaacplus/adts.h>
-
-#include <libaacplus/sbr_main.h>
-#include <libaacplus/aac_ram.h>
-#include <libaacplus/aac_rom.h>
-}
+#include <aacplus.h>
 #else
 #error configure with aacplus
 #endif
@@ -83,16 +72,10 @@
 /**
  *  A class representing aacplus AAC+ encoder.
  *
- *  @author  $Author: rafael@riseup.net $
- *  @version $Revision: 474 $
+ *  @author  $Author$
+ *  @version $Revision$
  */
 
-#define CORE_DELAY   (1600)
-#define INPUT_DELAY  ((CORE_DELAY)*2 +6*64-2048+1)     /* ((1600 (core codec)*2 (multi rate) + 6*64 (sbr dec delay) - 2048 (sbr enc delay) + magic*/
-#define MAX_DS_FILTER_DELAY 16                         /* the additional max resampler filter delay (source fs)*/
-
-#define CORE_INPUT_OFFSET_PS (0)  /* (96-64) makes AAC still some 64 core samples too early wrt SBR ... maybe -32 would be even more correct, but 1024-32 would need additional SBR bitstream delay by one frame */
-
 class aacPlusEncoder : public AudioEncoder, public virtual Reporter
 {
     private:
@@ -124,31 +107,26 @@
          */
         Ref<Sink>                   sink;
 
-		float inBuf[(AACENC_BLOCKSIZE*2 + MAX_DS_FILTER_DELAY + INPUT_DELAY)*MAX_CHANNELS];
-		char outBuf[(6144/8)*MAX_CHANNELS+ADTS_HEADER_SIZE];
-		IIR21_RESAMPLER IIR21_reSampler[MAX_CHANNELS];
-
-		AACENC_CONFIG     config;
-		
-		int nChannelsAAC, nChannelsSBR;
-		unsigned int sampleRateAAC;
-
-		int bitrate;
-		int bandwidth;
-		
-		unsigned int numAncDataBytes;
-		unsigned char ancDataBytes[MAX_PAYLOAD_SIZE];
-		
-		bool useParametricStereo;
-		int coreWriteOffset;
-		int envReadOffset;
-		int writeOffset;
-		struct AAC_ENCODER *aacEnc;
-		unsigned int inSamples;
-		unsigned int writtenSamples;
-		
-		HANDLE_SBR_ENCODER hEnvEnc;
-		sbrConfiguration sbrConfig;
+        /**
+         *  The handle to the AAC+ encoder instance.
+         */
+        aacplusEncHandle               encoderHandle;
+
+        /**
+         *  The maximum number of input samples to supply to the encoder.
+         */
+        unsigned long               inputSamples;
+
+        /**
+         *  The maximum number of output bytes the encoder returns in one call.
+         */
+        unsigned long               maxOutputBytes;
+
+        /**
+         *  Lowpass filter. Sound frequency in Hz, from where up the
+         *  input is cut.
+         */
+        int                             lowpass;
 
         /**
          *  Initialize the object.
@@ -157,10 +135,11 @@
          *  @exception Exception
          */
         inline void
-        init ( Sink           * sink)                throw (Exception)
+        init ( Sink           * sink, int lowpass)                throw (Exception)
         {
             this->aacplusOpen        = false;
             this->sink            = sink;
+            this->lowpass         = lowpass;
 	    
 	    /* TODO: if we have float as input, we don't need conversion */
             if ( getInBitsPerSample() != 16 && getInBitsPerSample() != 32 ) {
@@ -179,11 +158,6 @@
                         "unsupported number of output channels for the encoder",
                                  getOutChannel() );
             }
-	    /* TODO: this will be neede when we implement mono aac+ encoding */
-            if ( getInChannel() != getOutChannel() ) {
-                throw Exception( __FILE__, __LINE__,
-                             "input channels and output channels do not match");
-            }
 
             if ( getOutSampleRate() == getInSampleRate() ) {
                 resampleRatio = 1;
@@ -237,17 +211,6 @@
                                  "specified bits per sample with samplerate conversion not supported",
                                  getInBitsPerSample() );
             }
-
-            bitrate = getOutBitrate() * 1000;
-            bandwidth = 0;
-            useParametricStereo = 0;
-            numAncDataBytes=0;
-            coreWriteOffset = 0;
-            envReadOffset = 0;
-            writeOffset = INPUT_DELAY*MAX_CHANNELS;
-            writtenSamples = 0;
-            aacEnc = NULL;
-            hEnvEnc=NULL;
         }
 
         /**
@@ -269,10 +232,6 @@
             }
         }
 
-        void
-        encodeAacSamples (short *TimeDataPcm, unsigned int samples, int channels)
-                                                        throw ( Exception );
-
     protected:
 
         /**
@@ -335,7 +294,7 @@
                                      outSampleRate,
                                      outChannel )
         {
-            init( sink);
+            init( sink, lowpass);
         }
 
         /**
@@ -376,7 +335,7 @@
                                      outSampleRate,
                                      outChannel )
         {
-            init( sink);
+            init( sink, lowpass );
         }
 
         /**
@@ -389,7 +348,7 @@
                                                             throw ( Exception )
                     : AudioEncoder( encoder )
         {
-            init( encoder.sink.get());
+            init( encoder.sink.get(), encoder.lowpass);
         }
 
 
@@ -420,7 +379,7 @@
             if ( this != &encoder ) {
                 strip();
                 AudioEncoder::operator=( encoder);
-                init( encoder.sink.get());
+                init( encoder.sink.get(), encoder.lowpass);
             }
 
             return *this;
