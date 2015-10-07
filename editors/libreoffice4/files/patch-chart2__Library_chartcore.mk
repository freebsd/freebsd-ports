--- chart2/Library_chartcore.mk.orig	2014-11-10 06:52:56.000000000 -0500
+++ chart2/Library_chartcore.mk	2014-11-25 16:17:07.000000000 -0500
@@ -261,6 +261,11 @@
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
