--- chart2/Library_chartopengl.mk.orig	2014-11-10 06:52:56.000000000 -0500
+++ chart2/Library_chartopengl.mk	2014-11-25 16:22:54.000000000 -0500
@@ -67,6 +67,11 @@
 $(eval $(call gb_Library_use_system_darwin_frameworks,chartopengl,\
 	OpenGL \
 ))
+else ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Library_add_libs,chartopengl,\
+	-lGL \
+	-lX11 \
+))
 else ifeq ($(OS),LINUX)
 $(eval $(call gb_Library_add_libs,chartopengl,\
 	-ldl \
