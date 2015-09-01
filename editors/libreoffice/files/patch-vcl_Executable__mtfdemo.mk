--- vcl/Executable_mtfdemo.mk.orig	2015-08-22 06:41:35 UTC
+++ vcl/Executable_mtfdemo.mk
@@ -40,7 +40,16 @@ $(eval $(call gb_Executable_use_static_l
     vclmain \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Executable_add_libs,mtfdemo,\
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,mtfdemo,\
+    glxtest \
+))
+else ifeq ($(OS),LINUX)
 $(eval $(call gb_Executable_add_libs,mtfdemo,\
 	-lm \
 	-ldl \
