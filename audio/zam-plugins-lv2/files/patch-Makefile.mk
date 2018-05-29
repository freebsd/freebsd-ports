--- Makefile.mk.orig	2018-05-29 08:20:20 UTC
+++ Makefile.mk
@@ -35,19 +35,19 @@ ifeq ($(MACOS),true)
 LINK_OPTS  = -fdata-sections -ffunction-sections -Wl,-dead_strip -Wl,-dead_strip_dylibs
 else
 # Common linker flags
-LINK_OPTS  = -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,-O1 -Wl,--as-needed -Wl,--strip-all
+LINK_OPTS  = -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,-O1 -Wl,--strip-all
 endif
 
 ifeq ($(RASPPI),true)
 # Raspberry-Pi optimization flags
 BASE_OPTS  = -O2 -ffast-math -march=armv6 -mfpu=vfp -mfloat-abi=hard
-LINK_OPTS  = -Wl,-O1 -Wl,--as-needed -Wl,--strip-all
+LINK_OPTS  = -Wl,-O1 -Wl,--strip-all
 endif
 
 ifeq ($(PANDORA),true)
 # OpenPandora optimization flags
 BASE_OPTS  = -O2 -ffast-math -march=armv7-a -mcpu=cortex-a8 -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp
-LINK_OPTS  = -Wl,-O1 -Wl,--as-needed -Wl,--strip-all
+LINK_OPTS  = -Wl,-O1 -Wl,--strip-all
 endif
 
 ifeq ($(NOOPT),true)
