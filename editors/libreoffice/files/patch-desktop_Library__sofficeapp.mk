--- desktop/Library_sofficeapp.mk.orig	2015-08-22 06:41:35 UTC
+++ desktop/Library_sofficeapp.mk
@@ -104,7 +104,16 @@ $(eval $(call gb_Library_add_libs,soffic
 	-lpthread \
 ))
 else
-ifeq ($(OS),LINUX)
+ifeq ($(OS),FREEBSD)
+$(eval $(call gb_Library_use_static_libraries,sofficeapp,\
+    glxtest \
+))
+
+$(eval $(call gb_Library_add_libs,sofficeapp,\
+    -lGL \
+    -lX11 \
+))
+else ifeq ($(OS),LINUX)
 $(eval $(call gb_Library_use_static_libraries,sofficeapp,\
     glxtest \
 ))
