--- src/core/linux/SDL_evdev_capabilities.h.orig	2022-01-08 02:29:52 UTC
+++ src/core/linux/SDL_evdev_capabilities.h
@@ -25,8 +25,6 @@
 #ifndef SDL_evdev_capabilities_h_
 #define SDL_evdev_capabilities_h_
 
-#if HAVE_LIBUDEV_H || defined(SDL_JOYSTICK_LINUX)
-
 #include <linux/input.h>
 
 /* A device can be any combination of these classes */
@@ -52,8 +50,6 @@ extern int SDL_EVDEV_GuessDeviceClass(unsigned long bi
                                       unsigned long bitmask_abs[NBITS(ABS_MAX)],
                                       unsigned long bitmask_key[NBITS(KEY_MAX)],
                                       unsigned long bitmask_rel[NBITS(REL_MAX)]);
-
-#endif /* HAVE_LIBUDEV_H || defined(SDL_JOYSTICK_LINUX) */
 
 #endif /* SDL_evdev_capabilities_h_ */
 
