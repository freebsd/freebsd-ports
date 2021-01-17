--- dpf/Makefile.base.mk.orig	2021-01-15 11:38:19 UTC
+++ dpf/Makefile.base.mk
@@ -136,7 +136,7 @@ BASE_FLAGS = -Wall -Wextra -pipe -MD -MP
 BASE_OPTS  = -O3 -ffast-math -fdata-sections -ffunction-sections
 
 ifeq ($(CPU_I386_OR_X86_64),true)
-BASE_OPTS += -mtune=generic -msse -msse2 -mfpmath=sse
+BASE_OPTS += $(SIMD_FLAGS)
 endif
 
 ifeq ($(CPU_ARM),true)
