--- src/vk_peak.cpp.orig	2026-05-07 12:12:10 UTC
+++ src/vk_peak.cpp
@@ -2192,7 +2192,7 @@ int vkPeak::runKernelLatency(VulkanDevice &dev, benchm
 #else
     struct timespec ts;
     clock_gettime((hostDomain == VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT)
-                    ? CLOCK_MONOTONIC_RAW : CLOCK_MONOTONIC, &ts);
+                    ? CLOCK_MONOTONIC_FAST : CLOCK_MONOTONIC, &ts);
     return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
 #endif
   };
