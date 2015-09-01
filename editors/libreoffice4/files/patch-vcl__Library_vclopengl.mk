--- vcl/Library_vclopengl.mk.orig	2014-11-10 06:52:56.000000000 -0500
+++ vcl/Library_vclopengl.mk	2014-11-25 16:06:48.000000000 -0500
@@ -53,6 +53,12 @@
 $(eval $(call gb_Library_use_system_darwin_frameworks,vclopengl,\
 	OpenGL \
 ))
+else ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Library_add_libs,vclopengl,\
+    -lGL \
+    -lGLU \
+    -lX11 \
+))
 else ifeq ($(OS),LINUX)
 $(eval $(call gb_Library_add_libs,vclopengl,\
     -ldl \
