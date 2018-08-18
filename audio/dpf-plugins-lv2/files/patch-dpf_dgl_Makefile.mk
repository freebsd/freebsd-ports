--- dpf/dgl/Makefile.mk.orig	2018-04-27 06:05:19 UTC
+++ dpf/dgl/Makefile.mk
@@ -23,20 +23,20 @@ endif
 # Set build and link flags
 
 BASE_FLAGS = -Wall -Wextra -pipe -MD -MP
-BASE_OPTS  = -O2 -mtune=generic -msse -msse2 -fdata-sections -ffunction-sections
+BASE_OPTS  = -O2 -mtune=generic $(SIMD_FLAGS) -fdata-sections -ffunction-sections
 
 ifeq ($(MACOS),true)
 # MacOS linker flags
 LINK_OPTS  = -fdata-sections -ffunction-sections -Wl,-dead_strip -Wl,-dead_strip_dylibs
 else
 # Common linker flags
-LINK_OPTS  = -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,-O1 -Wl,--as-needed -Wl,--strip-all
+LINK_OPTS  = -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,-O1 -Wl,--strip-all
 endif
 
 ifeq ($(RASPPI),true)
 # Raspberry-Pi optimization flags
 BASE_OPTS  = -O2 -march=armv6 -mfpu=vfp -mfloat-abi=hard
-LINK_OPTS  = -Wl,-O1 -Wl,--as-needed -Wl,--strip-all
+LINK_OPTS  = -Wl,-O1 -Wl,--strip-all
 endif
 
 ifeq ($(NOOPT),true)
