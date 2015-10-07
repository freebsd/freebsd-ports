--- vcl/Library_vcl.mk.orig	2015-08-22 06:41:35 UTC
+++ vcl/Library_vcl.mk
@@ -58,7 +58,7 @@ $(eval $(call gb_Library_use_custom_head
 ))
 
 $(eval $(call gb_Library_use_externals,vcl,\
-	$(if $(filter LINUX MACOSX,$(OS)), \
+	$(if $(filter FREEBSD LINUX MACOSX,$(OS)), \
 		curl) \
 	jpeg \
 	$(if $(filter-out WNT,$(OS)), \
@@ -716,7 +716,16 @@ $(eval $(call gb_Library_use_system_win3
 $(eval $(call gb_Library_add_nativeres,vcl,vcl/salsrc))
 endif
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Library_add_libs,vcl,\
+    -lGL \
+    -lX11 \
+))
+
+$(eval $(call gb_Library_add_exception_objects,vcl,\
+    vcl/opengl/x11/X11DeviceInfo \
+))
+else ifeq ($(OS),LINUX)
 $(eval $(call gb_Library_add_libs,vcl,\
 	-lm \
 	-ldl \
