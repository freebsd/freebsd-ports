--- src/libwavpack.cpp.orig	2009-09-28 02:52:56 UTC
+++ src/libwavpack.cpp
@@ -40,7 +40,7 @@ extern "C" {
 #define M_LN10   2.3025850929940456840179914546843642
 #endif
 
-#define DBG(format, args...) fprintf(stderr, format, ## args)
+#define DBG(format, args...) //fprintf(stderr, format, ## args)
 #define BUFFER_SIZE 256 // read buffer size, in samples
 
 extern "C" InputPlugin * get_iplugin_info(void);
@@ -167,7 +167,7 @@ public:
         int tsamples = num_samples * num_channels;
 
         if (!(WavpackGetMode (ctx) & MODE_FLOAT)) {
-            float scaler = (float) (1.0 / ((unsigned int32_t) 1 << (bytes_per_sample * 8 - 1)));
+            float scaler = (float) (1.0 / ((uint32_t) 1 << (bytes_per_sample * 8 - 1)));
             float *fptr = (float *) input;
             int32_t *lptr = input;
             int cnt = tsamples;
