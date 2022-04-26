- workaround for https://github.com/falkTX/Carla/issues/1608: error: unknown argument: '-fno-gnu-unique'

--- source/Makefile.mk.orig	2022-04-17 05:37:05 UTC
+++ source/Makefile.mk
@@ -86,7 +86,7 @@ endif
 
 ifneq ($(MACOS),true)
 ifneq ($(WIN32),true)
-BASE_FLAGS += -fno-gnu-unique
+#BASE_FLAGS += -fno-gnu-unique
 endif
 endif
 
