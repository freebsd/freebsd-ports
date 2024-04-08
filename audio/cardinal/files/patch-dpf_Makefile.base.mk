
- workaround for https://github.com/DISTRHO/Cardinal/issues/641

--- dpf/Makefile.base.mk.orig	2024-04-08 16:00:03 UTC
+++ dpf/Makefile.base.mk
@@ -373,7 +373,7 @@ endif
 # ---------------------------------------------------------------------------------------------------------------------
 # Check for optional libraries
 
-HAVE_LIBLO = $(shell $(PKG_CONFIG) --exists liblo && echo true)
+HAVE_LIBLO = $(shell $(PKG_CONFIG) --exists liblo && echo $(WITH_LIBLO))
 
 ifneq ($(SKIP_NATIVE_AUDIO_FALLBACK),true)
 ifneq ($(SKIP_RTAUDIO_FALLBACK),true)
