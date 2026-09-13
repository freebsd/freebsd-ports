--- external/skia/Library_skia.mk.orig	2026-08-21 12:51:44 UTC
+++ external/skia/Library_skia.mk
@@ -109,7 +109,7 @@ $(eval $(call gb_Library_use_externals,skia,\
     libpng \
 ))
 
-ifeq ($(OS),LINUX)
+ifneq (,$(filter DRAGONFLY FREEBSD LINUX NETBSD OPENBSD,$(OS)))
 $(eval $(call gb_Library_add_libs,skia,\
     -lm \
     -ldl \
@@ -297,7 +297,7 @@ $(eval $(call gb_Library_add_generated_exception_objec
 #
 $(eval $(call gb_Library_add_generated_exception_objects,skia,\
     UnpackedTarball/skia/tools/window/WindowContext \
-	$(if $(filter LINUX,$(OS)),UnpackedTarball/skia/tools/window/unix/RasterWindowContext_unix) \
+	$(if $(filter DRAGONFLY FREEBSD LINUX NETBSD OPENBSD,$(OS)),UnpackedTarball/skia/tools/window/unix/RasterWindowContext_unix) \
     $(if $(filter WNT,$(OS)),UnpackedTarball/skia/tools/window/win/RasterWindowContext_win) \
 ))
 ifeq ($(SKIA_GPU),METAL)
