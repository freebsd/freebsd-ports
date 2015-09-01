--- vcl/Executable_ui-previewer.mk.orig	2015-08-22 06:41:35 UTC
+++ vcl/Executable_ui-previewer.mk
@@ -34,7 +34,16 @@ $(eval $(call gb_Executable_add_exceptio
     vcl/source/uipreviewer/previewer \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Executable_add_libs,ui-previewer,\
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Executable_use_static_libraries,ui-previewer,\
+    glxtest \
+))
+else ifeq ($(OS),LINUX)
 $(eval $(call gb_Executable_add_libs,ui-previewer,\
 	-lm \
 	-ldl \
