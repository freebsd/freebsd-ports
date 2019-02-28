--- dpf/Makefile.base.mk.orig	2019-02-28 18:07:46 UTC
+++ dpf/Makefile.base.mk
@@ -90,7 +90,7 @@ endif
 # Set build and link flags
 
 BASE_FLAGS = -Wall -Wextra -pipe -MD -MP
-BASE_OPTS  = -O3 -ffast-math -mtune=generic -msse -msse2 -fdata-sections -ffunction-sections
+BASE_OPTS  = -O3 -ffast-math -mtune=generic $(SIMD_FLAGS) -fdata-sections -ffunction-sections
 
 ifeq ($(MACOS),true)
 # MacOS linker flags
