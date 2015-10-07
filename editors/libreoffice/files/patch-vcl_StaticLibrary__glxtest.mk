--- vcl/StaticLibrary_glxtest.mk.orig	2015-08-22 06:41:35 UTC
+++ vcl/StaticLibrary_glxtest.mk
@@ -29,6 +29,16 @@ $(eval $(call gb_StaticLibrary_use_api,g
     udkapi \
 ))
 
+ifeq ($(OS),FREEBSD)
+$(eval $(call gb_StaticLibrary_add_libs,glxtest,\
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_StaticLibrary_add_exception_objects,glxtest,\
+    vcl/unx/glxtest \
+))
+else
 $(eval $(call gb_StaticLibrary_add_libs,glxtest,\
 	-lm \
 	-ldl \
@@ -40,5 +50,6 @@ $(eval $(call gb_StaticLibrary_add_libs,
 $(eval $(call gb_StaticLibrary_add_exception_objects,glxtest,\
     vcl/unx/glxtest \
 ))
+endif
 
 # vim: set noet sw=4 ts=4:
