--- Makefile.mk.orig	2018-06-10 17:12:48 UTC
+++ Makefile.mk
@@ -34,7 +34,7 @@ CXX ?= g++
 # Set build and link flags
 
 BASE_FLAGS = -Wall -Wextra -Wshadow -pipe
-BASE_OPTS  = -O2 -ffast-math -mtune=generic -msse -msse2 -mfpmath=sse -fdata-sections -ffunction-sections
+BASE_OPTS  = -O2 -ffast-math $(PORT_SIMD_FLAGS) -fdata-sections -ffunction-sections
 
 ifeq ($(MACOS),true)
 # MacOS linker flags
