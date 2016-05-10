--- src/modules_limit.cpp.orig	2014-10-14 18:56:24 UTC
+++ src/modules_limit.cpp
@@ -429,7 +429,7 @@ uint32_t multibandlimiter_audio_module::
                 }
                 
                 // write multiband coefficient to buffer
-                buffer[pos] = std::min(*params[param_limit] / std::max(fabs(tmpL), fabs(tmpR)), 1.0);
+                buffer[pos] = std::min(*params[param_limit] / std::max(fabsf(tmpL), fabsf(tmpR)), 1.0f);
                 
                 // step forward in multiband buffer
                 pos = (pos + channels) % buffer_size;
@@ -811,7 +811,7 @@ uint32_t sidechainlimiter_audio_module::
                 }
                 
                 // write multiband coefficient to buffer
-                buffer[pos] = std::min(*params[param_limit] / std::max(fabs(tmpL), fabs(tmpR)), 1.0);
+                buffer[pos] = std::min(*params[param_limit] / std::max(fabsf(tmpL), fabsf(tmpR)), 1.0f);
                 
                 // step forward in multiband buffer
                 pos = (pos + channels) % buffer_size;
