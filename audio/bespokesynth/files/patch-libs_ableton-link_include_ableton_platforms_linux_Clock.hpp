--- libs/ableton-link/include/ableton/platforms/linux/Clock.hpp.orig	2023-11-14 04:55:52 UTC
+++ libs/ableton-link/include/ableton/platforms/linux/Clock.hpp
@@ -53,7 +53,7 @@ class Clock (public)
 };
 
 using ClockMonotonic = Clock<CLOCK_MONOTONIC>;
-using ClockMonotonicRaw = Clock<CLOCK_MONOTONIC_RAW>;
+using ClockMonotonicRaw = Clock<CLOCK_MONOTONIC>;
 
 } // namespace linux
 } // namespace platforms
