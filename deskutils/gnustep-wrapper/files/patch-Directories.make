--- Directories.make.orig	2017-08-13 17:48:46 UTC
+++ Directories.make
@@ -28,8 +28,4 @@ OBJ_BASE_DIR=shared_obj
 endif
 
 ARCH_DIR=$(GNUSTEP_TARGET_CPU)/$(GNUSTEP_TARGET_OS)/$(LIBRARY_COMBO)
-ifneq ($(GNUSTEP_FLATTENED),yes)
-OBJ_DIR=$(OBJ_BASE_DIR)/$(ARCH_DIR)
-else
 OBJ_DIR=$(OBJ_BASE_DIR)
-endif
