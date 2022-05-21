--- dpf/Makefile.base.mk.orig	2022-05-21 05:45:04 UTC
+++ dpf/Makefile.base.mk
@@ -173,7 +173,7 @@ BASE_OPTS  = -O2 -ffast-math -fdata-sections -ffunctio
 endif
 
 ifneq ($(MACOS_OR_WINDOWS),true)
-BASE_FLAGS += -fno-gnu-unique
+#BASE_FLAGS += -fno-gnu-unique
 endif
 
 ifeq ($(WINDOWS),true)
