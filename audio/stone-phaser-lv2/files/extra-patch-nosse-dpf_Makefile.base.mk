--- dpf/Makefile.base.mk.orig	2019-12-11 09:25:25 UTC
+++ dpf/Makefile.base.mk
@@ -106,7 +106,7 @@ endif
 # Set build and link flags
 
 BASE_FLAGS = -Wall -Wextra -pipe -MD -MP
-BASE_OPTS  = -O3 -ffast-math -mtune=generic -msse -msse2 -fdata-sections -ffunction-sections
+BASE_OPTS  = -O3 -ffast-math -fdata-sections -ffunction-sections
 
 ifeq ($(MACOS),true)
 # MacOS linker flags
