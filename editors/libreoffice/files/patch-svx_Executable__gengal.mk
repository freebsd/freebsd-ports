--- svx/Executable_gengal.mk.orig	2015-08-22 06:41:35 UTC
+++ svx/Executable_gengal.mk
@@ -67,7 +67,16 @@ $(eval $(call gb_Executable_add_libs,gen
 	-lpthread \
 ))
 else
-ifeq ($(OS),LINUX)
+ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Executable_add_libs,gengal,\
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,gengal,\
+    glxtest \
+))
+else ifeq ($(OS),LINUX)
 $(eval $(call gb_Executable_add_libs,gengal,\
 	-ldl \
 	-lpthread \
