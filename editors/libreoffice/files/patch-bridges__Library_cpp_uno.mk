--- bridges/Library_cpp_uno.mk.orig	2013-12-11 01:11:21.000000000 +0900
+++ bridges/Library_cpp_uno.mk	2014-01-29 16:13:21.000000000 +0900
@@ -188,7 +188,7 @@
 	$(if $(filter TRUE,$(HAVE_GCC_AVX)),-mno-avx) \
 ))
 
-ifeq ($(filter ANDROID WNT,$(OS)),)
+ifeq ($(filter ANDROID WNT DRAGONFLY FREEBSD NETBSD OPENBSD MACOSX,$(OS)),)
 $(eval $(call gb_Library_add_libs,gcc3_uno,\
 	-ldl \
 ))
