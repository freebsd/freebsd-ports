--- dpf/Makefile.base.mk.orig	2021-01-17 22:01:08 UTC
+++ dpf/Makefile.base.mk
@@ -132,7 +132,7 @@ BASE_FLAGS = -Wall -Wextra -pipe -MD -MP
 BASE_OPTS  = -O3 -ffast-math -fdata-sections -ffunction-sections
 
 ifeq ($(CPU_I386_OR_X86_64),true)
-BASE_OPTS += -mtune=generic -msse -msse2
+BASE_OPTS += ${PORT_SIMD_FLAGS}
 endif
 
 ifeq ($(CPU_ARM),true)
