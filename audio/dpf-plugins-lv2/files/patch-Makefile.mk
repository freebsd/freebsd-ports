--- Makefile.mk.orig	2018-04-27 06:05:19 UTC
+++ Makefile.mk
@@ -23,7 +23,7 @@ endif
 # Set build and link flags
 
 BASE_FLAGS = -Wall -Wextra -pipe
-BASE_OPTS  = -O2 -ffast-math -mtune=generic -msse -msse2 -fdata-sections -ffunction-sections
+BASE_OPTS  = -O2 -ffast-math -mtune=generic $(SIMD_FLAGS) -fdata-sections -ffunction-sections
 
 ifneq ($(MACOS_OLD),true)
 # Old MacOS doesn't support this
@@ -35,13 +35,13 @@ ifeq ($(MACOS),true)
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
 
 ifeq ($(NOOPT),true)
