--- dpf/Makefile.base.mk.orig	2019-11-04 21:45:33 UTC
+++ dpf/Makefile.base.mk
@@ -129,7 +129,7 @@ endif
 # Set build and link flags
 
 BASE_FLAGS = -Wall -Wextra -pipe -MD -MP
-BASE_OPTS  = -O3 -ffast-math -mtune=generic -fdata-sections -ffunction-sections
+BASE_OPTS  = -O3 -ffast-math -fdata-sections -ffunction-sections
 
 ifeq ($(CPU_I386_OR_X86_64),true)
 BASE_OPTS += -msse -msse2
