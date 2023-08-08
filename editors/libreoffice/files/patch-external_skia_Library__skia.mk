--- external/skia/Library_skia.mk.orig	2022-12-22 00:14:09 UTC
+++ external/skia/Library_skia.mk
@@ -96,7 +96,7 @@ $(eval $(call gb_Library_use_externals,skia,\
     libpng \
 ))
 
-ifeq ($(OS),LINUX)
+ifneq (,$(filter DRAGONFLY FREEBSD LINUX NETBSD OPENBSD,$(OS)))
 $(eval $(call gb_Library_add_libs,skia,\
     -lm \
     -ldl \
