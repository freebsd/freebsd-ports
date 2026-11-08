--- src/external/miniaudio.h.orig	2026-10-15 15:12:55 UTC
+++ src/external/miniaudio.h
@@ -43599,6 +43599,8 @@ MA_API ma_device_config ma_device_config_init(ma_devic
     MA_ZERO_OBJECT(&config);
     config.deviceType = deviceType;
     config.resampling = ma_resampler_config_init(ma_format_unknown, 0, 0, 0, ma_resample_algorithm_linear); /* Format/channels/rate don't matter here. */
+    config.periodSizeInMilliseconds = 10;
+    config.periods = 2;
 
     return config;
 }
