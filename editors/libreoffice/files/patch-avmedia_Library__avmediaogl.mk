--- avmedia/Library_avmediaogl.mk.orig	2015-08-22 06:41:35 UTC
+++ avmedia/Library_avmediaogl.mk
@@ -52,7 +52,7 @@ else ifeq ($(OS),MACOSX)
 $(eval $(call gb_Library_use_system_darwin_frameworks,avmediaogl,\
 	OpenGL \
 ))
-else ifeq ($(OS),LINUX)
+else ifneq ($(filter FREEBSD LINUX,$(OS)),)
 $(eval $(call gb_Library_add_libs,avmediaogl,\
     -lGL \
 ))
