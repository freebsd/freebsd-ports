--- dpf/dgl/Makefile.mk.orig	2018-05-29 08:20:51 UTC
+++ dpf/dgl/Makefile.mk
@@ -30,13 +30,13 @@ ifeq ($(MACOS),true)
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
