--- libfaad/structs.h.orig	Thu Jan 29 12:31:11 2004
+++ libfaad/structs.h	Sun May 23 10:52:13 2004
@@ -307,58 +307,58 @@
 typedef struct mp4AudioSpecificConfig
 {
     /* Audio Specific Info */
-    uint8_t objectTypeIndex;
-    uint8_t samplingFrequencyIndex;
-    uint32_t samplingFrequency;
-    uint8_t channelsConfiguration;
+    unsigned char objectTypeIndex;
+    unsigned char samplingFrequencyIndex;
+    unsigned long samplingFrequency;
+    unsigned char channelsConfiguration;
 
     /* GA Specific Info */
-    uint8_t frameLengthFlag;
-    uint8_t dependsOnCoreCoder;
-    uint16_t coreCoderDelay;
-    uint8_t extensionFlag;
-    uint8_t aacSectionDataResilienceFlag;
-    uint8_t aacScalefactorDataResilienceFlag;
-    uint8_t aacSpectralDataResilienceFlag;
-    uint8_t epConfig;
+    unsigned char frameLengthFlag;
+    unsigned char dependsOnCoreCoder;
+    unsigned short coreCoderDelay;
+    unsigned char extensionFlag;
+    unsigned char aacSectionDataResilienceFlag;
+    unsigned char aacScalefactorDataResilienceFlag;
+    unsigned char aacSpectralDataResilienceFlag;
+    unsigned char epConfig;
 
-    int8_t sbr_present_flag;
-    int8_t forceUpSampling;
+    char sbr_present_flag;
+    char forceUpSampling;
 } mp4AudioSpecificConfig;
 
 typedef struct faacDecConfiguration
 {
-    uint8_t defObjectType;
-    uint32_t defSampleRate;
-    uint8_t outputFormat;
-    uint8_t downMatrix;
-    uint8_t useOldADTSFormat;
-    uint8_t dontUpSampleImplicitSBR;
+    unsigned char defObjectType;
+    unsigned long defSampleRate;
+    unsigned char outputFormat;
+    unsigned char downMatrix;
+    unsigned char useOldADTSFormat;
+    unsigned char dontUpSampleImplicitSBR;
 } faacDecConfiguration, *faacDecConfigurationPtr;
 
 typedef struct faacDecFrameInfo
 {
-    uint32_t bytesconsumed;
-    uint32_t samples;
-    uint8_t channels;
-    uint8_t error;
-    uint32_t samplerate;
+    unsigned long bytesconsumed;
+    unsigned long samples;
+    unsigned char channels;
+    unsigned char error;
+    unsigned long samplerate;
 
     /* SBR: 0: off, 1: on; normal, 2: on; downsampled */
-    uint8_t sbr;
+    unsigned char sbr;
 
     /* MPEG-4 ObjectType */
-    uint8_t object_type;
+    unsigned char object_type;
 
     /* AAC header type; MP4 will be signalled as RAW also */
-    uint8_t header_type;
+    unsigned char header_type;
 
     /* multichannel configuration */
-    uint8_t num_front_channels;
-    uint8_t num_side_channels;
-    uint8_t num_back_channels;
-    uint8_t num_lfe_channels;
-    uint8_t channel_position[MAX_CHANNELS];
+    unsigned char num_front_channels;
+    unsigned char num_side_channels;
+    unsigned char num_back_channels;
+    unsigned char num_lfe_channels;
+    unsigned char channel_position[MAX_CHANNELS];
 } faacDecFrameInfo;
 
 typedef struct
