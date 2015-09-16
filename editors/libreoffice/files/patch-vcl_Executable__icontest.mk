--- vcl/Executable_icontest.mk.orig	2015-08-22 06:41:35 UTC
+++ vcl/Executable_icontest.mk
@@ -25,7 +25,16 @@ $(eval $(call gb_Executable_use_static_l
     vclmain \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Executable_add_libs,icontest,\
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,icontest,\
+    glxtest \
+))
+else ifeq ($(OS),LINUX)
 $(eval $(call gb_Executable_add_libs,icontest,\
 	-lm \
 	-ldl \
