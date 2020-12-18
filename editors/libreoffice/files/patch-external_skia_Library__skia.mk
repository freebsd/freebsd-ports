--- external/skia/Library_skia.mk.orig	2020-11-22 14:05:28 UTC
+++ external/skia/Library_skia.mk
@@ -71,7 +71,7 @@ $(eval $(call gb_Library_use_externals,skia,\
     libpng \
 ))
 
-ifeq ($(OS),LINUX)
+ifneq (,$(filter DRAGONFLY FREEBSD LINUX NETBSD OPENBSD,$(OS)))
 $(eval $(call gb_Library_add_libs,skia,\
     -lm \
     -ldl \
