--- carla/source/Makefile.mk.orig	2022-05-21 05:42:01 UTC
+++ carla/source/Makefile.mk
@@ -86,7 +86,7 @@ endif
 
 ifneq ($(MACOS),true)
 ifneq ($(WIN32),true)
-BASE_FLAGS += -fno-gnu-unique
+#BASE_FLAGS += -fno-gnu-unique
 endif
 endif
 
