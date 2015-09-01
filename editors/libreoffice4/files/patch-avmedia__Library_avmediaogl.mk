--- avmedia/Library_avmediaogl.mk.orig	2014-11-10 06:52:56.000000000 -0500
+++ avmedia/Library_avmediaogl.mk	2014-11-25 15:42:07.000000000 -0500
@@ -53,7 +53,7 @@
 $(eval $(call gb_Library_use_system_darwin_frameworks,avmediaogl,\
 	OpenGL \
 ))
-else ifeq ($(OS),LINUX)
+else ifneq ($(filter FREEBSD LINUX,$(OS)),)
 $(eval $(call gb_Library_add_libs,avmediaogl,\
     -lGL \
 ))
