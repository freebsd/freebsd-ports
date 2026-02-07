--- dpf/Makefile.base.mk.orig	2023-01-24 05:46:15 UTC
+++ dpf/Makefile.base.mk
@@ -218,7 +218,7 @@ BASE_OPTS  = -O3 -ffast-math -fdata-sections -ffunctio
 LINK_OPTS  = -fdata-sections -ffunction-sections
 
 ifeq ($(GCC),true)
-BASE_FLAGS += -fno-gnu-unique
+#BASE_FLAGS += -fno-gnu-unique
 endif
 
 ifeq ($(SKIP_STRIPPING),true)
