src/vulkan/kernel_latency.cpp:188:23: error: use of undeclared identifier 'CLOCK_MONOTONIC_RAW'
  188 |                     ? CLOCK_MONOTONIC_RAW : CLOCK_MONOTONIC, &ts);
      |                       ^~~~~~~~~~~~~~~~~~~

--- src/vulkan/kernel_latency.cpp.orig	2026-05-19 16:41:31 UTC
+++ src/vulkan/kernel_latency.cpp
@@ -185,7 +185,7 @@ int vkPeak::runKernelLatency(VulkanDevice &dev, benchm
 #else
     struct timespec ts;
     clock_gettime((hostDomain == VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT)
-                    ? CLOCK_MONOTONIC_RAW : CLOCK_MONOTONIC, &ts);
+                    ? CLOCK_MONOTONIC_FAST : CLOCK_MONOTONIC, &ts);
     return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
 #endif
   };
