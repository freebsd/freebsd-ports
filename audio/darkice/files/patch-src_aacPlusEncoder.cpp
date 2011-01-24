--- src/aacPlusEncoder.cpp.orig	2010-05-10 00:18:48.000000000 +0200
+++ src/aacPlusEncoder.cpp	2011-01-20 13:39:21.000000000 +0100
@@ -5,8 +5,8 @@
    Tyrell DarkIce
 
    File     : aacPlusEncoder.cpp
-   Version  : $Revision: 474 $
-   Author   : $Author: rafael@riseup.net $
+   Version  : $Revision$
+   Author   : $Author$
    Location : $HeadURL$
 
    Copyright notice:
@@ -51,7 +51,7 @@
 /*------------------------------------------------------------------------------
  *  File identity
  *----------------------------------------------------------------------------*/
-static const char fileid[] = "$Id: aacPlusEncoder.cpp 474 2010-05-10 01:18:15Z rafael@riseup.net $";
+static const char fileid[] = "$Id$";
 
 
 /* ===============================================  local function prototypes */
@@ -76,82 +76,27 @@
                          "aacplus lib opening underlying sink error");
     }
 
-    reportEvent(1, "Using aacplus codec version", "720 3gpp");
+    reportEvent(1, "Using aacplus codec");
     
-    bitrate = getOutBitrate() * 1000;
-    bandwidth = 0;
-    useParametricStereo = 0;
-    numAncDataBytes=0;
-    coreWriteOffset = 0;
-    envReadOffset = 0;
-    writeOffset = INPUT_DELAY*MAX_CHANNELS;
-    writtenSamples = 0;
-    aacEnc = NULL;
-    hEnvEnc=NULL;
-
-    /* set up basic parameters for aacPlus codec */
-    AacInitDefaultConfig(&config);
-    nChannelsAAC = nChannelsSBR = getOutChannel();
-    
-    if ( (getInChannel() == 2) && (bitrate >= 16000) && (bitrate < 44001) ) {
-        useParametricStereo = 1;
-        nChannelsAAC = 1;
-        nChannelsSBR = 2;
-        
-        reportEvent(10, "use Parametric Stereo");
-        
-        envReadOffset = (MAX_DS_FILTER_DELAY + INPUT_DELAY)*MAX_CHANNELS;
-        coreWriteOffset = CORE_INPUT_OFFSET_PS;
-        writeOffset = envReadOffset;
-    } else {
-    	/* set up 2:1 downsampling */
-    	InitIIR21_Resampler(&(IIR21_reSampler[0]));
-    	InitIIR21_Resampler(&(IIR21_reSampler[1]));
-    	
-    	if(IIR21_reSampler[0].delay > MAX_DS_FILTER_DELAY)
-    		throw Exception(__FILE__, __LINE__, "IIR21 resampler delay is bigger then MAX_DS_FILTER_DELAY");
-        writeOffset += IIR21_reSampler[0].delay*MAX_CHANNELS;
+    encoderHandle = aacplusEncOpen(getOutSampleRate(),
+                                getInChannel(),
+                                &inputSamples,
+                                &maxOutputBytes);
+
+    aacplusEncConfiguration      * aacplusConfig;
+
+    aacplusConfig = aacplusEncGetCurrentConfiguration(encoderHandle);
+
+    aacplusConfig->bitRate       = getOutBitrate() * 1000;
+    aacplusConfig->bandWidth     = lowpass;
+    aacplusConfig->outputFormat  = 1;
+    aacplusConfig->inputFormat   = AACPLUS_INPUT_16BIT;
+    aacplusConfig->nChannelsOut  = getOutChannel();
+
+    if (!aacplusEncSetConfiguration(encoderHandle, aacplusConfig)) {
+        throw Exception(__FILE__, __LINE__,
+                        "error configuring libaacplus library");
     }
-    
-    sampleRateAAC = getOutSampleRate();
-    config.bitRate = bitrate;
-    config.nChannelsIn=getInChannel();
-    config.nChannelsOut=nChannelsAAC;
-    config.bandWidth=bandwidth;
-    
-    /* set up SBR configuration    */
-    if(!IsSbrSettingAvail(bitrate, nChannelsAAC, sampleRateAAC, &sampleRateAAC))
-        throw Exception(__FILE__, __LINE__, "No valid SBR configuration found");
-    
-    InitializeSbrDefaults (&sbrConfig);
-    sbrConfig.usePs = useParametricStereo;
-    
-    AdjustSbrSettings( &sbrConfig,
-                       bitrate,
-                       nChannelsAAC,
-                       sampleRateAAC,
-                       AACENC_TRANS_FAC,
-                       24000);
-    
-    EnvOpen( &hEnvEnc,
-             inBuf + coreWriteOffset,
-             &sbrConfig,
-             &config.bandWidth);
-        
-    /* set up AAC encoder, now that samling rate is known */
-    config.sampleRate = sampleRateAAC;
-    if (AacEncOpen(&aacEnc, config) != 0){
-        AacEncClose(aacEnc);
-        throw Exception(__FILE__, __LINE__, "Initialisation of AAC failed !");
-    }
-    
-    init_plans();
-    
-    /* create the ADTS header */
-    adts_hdr(outBuf, &config);
-    
-    inSamples = AACENC_BLOCKSIZE * getInChannel() * 2;
-    
 
     // initialize the resampling coverter if needed
     if ( converter ) {
@@ -159,8 +104,8 @@
         converterData.input_frames   = 4096/((getInBitsPerSample() / 8) * getInChannel());
         converterData.data_in        = new float[converterData.input_frames*getInChannel()];
         converterData.output_frames  = (int) (converterData.input_frames * resampleRatio + 1);
-        if ((int) inSamples >  getInChannel() * converterData.output_frames) {
-            resampledOffset       = new float[2 * inSamples];
+        if ((int) inputSamples >  getInChannel() * converterData.output_frames) {
+            resampledOffset       = new float[2 * inputSamples];
         } else {
             resampledOffset       = new float[2 * getInChannel() * converterData.input_frames];
         }
@@ -178,13 +123,9 @@
     }
 
     aacplusOpen = true;
-    reportEvent(10, "bitrate=", bitrate);
-    reportEvent(10, "nChannelsIn", getInChannel());
-    reportEvent(10, "nChannelsOut", getOutChannel());
-    reportEvent(10, "nChannelsSBR", nChannelsSBR);
-    reportEvent(10, "nChannelsAAC", nChannelsAAC);
-    reportEvent(10, "sampleRateAAC", sampleRateAAC);
-    reportEvent(10, "inSamples", inSamples);
+    reportEvent(10, "nChannelsAAC", aacplusConfig->nChannelsOut);
+    reportEvent(10, "sampleRateAAC", aacplusConfig->sampleRate);
+    reportEvent(10, "inSamples", inputSamples);
     return true;
 }
 
@@ -199,21 +140,23 @@
     if ( !isOpen() || len == 0) {
         return 0;
     }
-    
+
     unsigned int    channels         = getInChannel();
     unsigned int    bitsPerSample    = getInBitsPerSample();
     unsigned int    sampleSize       = (bitsPerSample / 8) * channels;
+    unsigned char * b                = (unsigned char*) buf;
     unsigned int    processed        = len - (len % sampleSize);
     unsigned int    nSamples         = processed / sampleSize;
-    unsigned int    samples          = (unsigned int) nSamples * channels;
-    int processedSamples = 0;
-    
-    
+    unsigned char * aacplusBuf          = new unsigned char[maxOutputBytes];
+    int             samples          = (int) nSamples * channels;
+    int             processedSamples = 0;
+
+
 
     if ( converter ) {
         unsigned int         converted;
 #ifdef HAVE_SRC_LIB
-        src_short_to_float_array ((short *) buf, converterData.data_in, samples);
+        src_short_to_float_array ((short *) b, converterData.data_in, samples);
         converterData.input_frames   = nSamples;
         converterData.data_out = resampledOffset + (resampledOffsetSize * channels);
         int srcError = src_process (converter, &converterData);
@@ -224,7 +167,6 @@
         int         inCount  = nSamples;
         short int     * shortBuffer  = new short int[samples];
         int         outCount = (int) (inCount * resampleRatio);
-        unsigned char * b = (unsigned char*) buf;
         Util::conv( bitsPerSample, b, processed, shortBuffer, isInBigEndian());
         converted = converter->resample( inCount,
                                          outCount+1,
@@ -235,18 +177,27 @@
         resampledOffsetSize += converted;
 
         // encode samples (if enough)
-        while(resampledOffsetSize - processedSamples >= inSamples/channels) {
+        while(resampledOffsetSize - processedSamples >= inputSamples/channels) {
+            int outputBytes;
 #ifdef HAVE_SRC_LIB
-            short *shortData = new short[inSamples];
+            short *shortData = new short[inputSamples];
             src_float_to_short_array(resampledOffset + (processedSamples * channels),
-                                     shortData, inSamples) ;
-
-            encodeAacSamples (shortData, inSamples, channels);
+                                     shortData, inputSamples) ;
+            outputBytes = aacplusEncEncode(encoderHandle,
+                                       (int32_t*) shortData,
+                                        inputSamples,
+                                        aacplusBuf,
+                                        maxOutputBytes);
             delete [] shortData;
 #else
-            encodeAacSamples (&resampledOffset[processedSamples*channels], inSamples, channels);
+            outputBytes = aacplusEncEncode(encoderHandle,
+                                       (int32_t*) &resampledOffset[processedSamples*channels],
+                                        inputSamples,
+                                        aacplusBuf,
+                                        maxOutputBytes);
 #endif
-            processedSamples+=inSamples/channels;
+            getSink()->write(aacplusBuf, outputBytes);
+            processedSamples+=inputSamples/channels;
         }
 
         if (processedSamples && (int) resampledOffsetSize >= processedSamples) {
@@ -262,70 +213,27 @@
 #endif
         }
     } else {
-        encodeAacSamples ((short *) buf, samples, channels);
-    }
+        while (processedSamples < samples) {
+            int     outputBytes;
+            int     inSamples = samples - processedSamples < (int) inputSamples
+                              ? samples - processedSamples
+                              : inputSamples;
+
+            outputBytes = aacplusEncEncode(encoderHandle,
+                                       (int32_t*) (b + processedSamples/sampleSize),
+                                        inSamples,
+                                        aacplusBuf,
+                                        maxOutputBytes);
+            getSink()->write(aacplusBuf, outputBytes);
 
-    return samples;
-}
-
-void
-aacPlusEncoder :: encodeAacSamples (short *TimeDataPcm, unsigned int samples, int channels)
-                                                                               throw ( Exception )
-{
-    unsigned int i;
-    int ch, outSamples, numOutBytes;
-
-    for (i=0; i<samples; i++)
-        inBuf[(2/channels)*i+writeOffset+writtenSamples] = (float) TimeDataPcm[i];
-
-    writtenSamples+=samples;
-
-    if (writtenSamples < inSamples)
-        return;
-    
-    /* encode one SBR frame */
-    EnvEncodeFrame( hEnvEnc,
-                    inBuf + envReadOffset,
-                    inBuf + coreWriteOffset,
-                    MAX_CHANNELS,
-                    &numAncDataBytes,
-                    ancDataBytes);
-    
-    /* 2:1 downsampling for AAC core */
-    if (!useParametricStereo) {
-        for( ch=0; ch<nChannelsAAC; ch++ )
-            IIR21_Downsample( &(IIR21_reSampler[ch]),
-                              inBuf + writeOffset+ch,
-                              writtenSamples/channels,
-                              MAX_CHANNELS,
-                              inBuf+ch,
-                              &outSamples,
-                              MAX_CHANNELS);
-    }
-        
-    /* encode one AAC frame */
-    AacEncEncode( aacEnc,
-                  inBuf,
-                  useParametricStereo ? 1 : MAX_CHANNELS, /* stride (step) */
-                  ancDataBytes,
-                  &numAncDataBytes,
-                  (unsigned *) (outBuf+ADTS_HEADER_SIZE),
-                  &numOutBytes);
-    if (useParametricStereo) {
-        memcpy( inBuf,inBuf+AACENC_BLOCKSIZE,CORE_INPUT_OFFSET_PS*sizeof(float));
-    } else {
-        memmove( inBuf,inBuf+AACENC_BLOCKSIZE*2*MAX_CHANNELS,writeOffset*sizeof(float));
-    }
-    
-    /* Write one frame of encoded audio */
-    if (numOutBytes) {
-        adts_hdr_up(outBuf, numOutBytes);
-        sink->write(outBuf, numOutBytes+ADTS_HEADER_SIZE);
+            processedSamples += inSamples;
+        }
     }
-    
-    writtenSamples=0;
 
-    return;
+    delete[] aacplusBuf;
+
+//    return processedSamples;
+    return samples;
 }
 
 /*------------------------------------------------------------------------------
@@ -352,12 +260,7 @@
     if ( isOpen() ) {
         flush();
     
-        destroy_plans();
-        AacEncClose(aacEnc);
-        if (hEnvEnc) {
-            EnvClose(hEnvEnc);
-        }
-    
+        aacplusEncClose(encoderHandle);
         aacplusOpen = false;
     
         sink->close();
