--- dpf/Makefile.base.mk.orig	2022-12-14 11:22:42 UTC
+++ dpf/Makefile.base.mk
@@ -218,7 +218,7 @@ BASE_OPTS  = -O3 -ffast-math -fdata-sections -ffunctio
 LINK_OPTS  = -fdata-sections -ffunction-sections
 
 ifeq ($(GCC),true)
-BASE_FLAGS += -fno-gnu-unique
+#BASE_FLAGS += -fno-gnu-unique
 endif
 
 ifeq ($(SKIP_STRIPPING),true)
@@ -244,7 +244,7 @@ BASE_OPTS += -msse -msse2 -msse3 -msimd128
 else ifeq ($(CPU_ARM32),true)
 BASE_OPTS += -mfpu=neon-vfpv4 -mfloat-abi=hard
 else ifeq ($(CPU_I386_OR_X86_64),true)
-BASE_OPTS += -mtune=generic -msse -msse2 -mfpmath=sse
+BASE_OPTS +=  -msse -msse2 -mfpmath=sse
 endif
 
 ifeq ($(MACOS),true)
