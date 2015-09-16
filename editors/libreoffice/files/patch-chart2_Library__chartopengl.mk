--- chart2/Library_chartopengl.mk.orig	2015-08-22 06:41:35 UTC
+++ chart2/Library_chartopengl.mk
@@ -66,6 +66,11 @@ else ifeq ($(OS),MACOSX)
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
