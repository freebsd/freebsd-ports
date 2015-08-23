--- src/libcore/timer.cpp.orig	2015-07-15 10:37:38 UTC
+++ src/libcore/timer.cpp
@@ -37,9 +37,6 @@
 // Assume POSIX. Check for good clock sources
 # include <unistd.h>
 # include <ctime>
-# if _POSIX_C_SOURCE < 199309L
-# error "The required POSIX clock functions are not available."
-# endif
 # if defined(_POSIX_MONOTONIC_CLOCK)
 # define TIMER_CLOCK CLOCK_MONOTONIC
 # elif defined(CLOCK_HIGHRES)
