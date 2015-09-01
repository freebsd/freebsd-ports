--- vcl/Executable_vcldemo.mk.orig	2015-08-22 06:41:35 UTC
+++ vcl/Executable_vcldemo.mk
@@ -41,7 +41,16 @@ $(eval $(call gb_Executable_use_static_l
     vclmain \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Executable_add_libs,vcldemo,\
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,vcldemo,\
+    glxtest \
+))
+else ifeq ($(OS),LINUX)
 $(eval $(call gb_Executable_add_libs,vcldemo,\
 	-lm \
 	-ldl \
