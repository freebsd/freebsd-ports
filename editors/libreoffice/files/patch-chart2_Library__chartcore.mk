--- chart2/Library_chartcore.mk.orig	2015-08-22 06:41:35 UTC
+++ chart2/Library_chartcore.mk
@@ -254,6 +254,11 @@ else ifeq ($(OS),MACOSX)
 $(eval $(call gb_Library_use_system_darwin_frameworks,chartcore,\
 	OpenGL \
 ))
+else ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Library_add_libs,chartcore,\
+	-lGL \
+	-lX11 \
+))
 else ifeq ($(OS),LINUX)
 $(eval $(call gb_Library_add_libs,chartcore,\
 	-ldl \
