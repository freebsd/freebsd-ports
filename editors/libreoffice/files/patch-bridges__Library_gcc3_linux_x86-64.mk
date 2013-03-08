--- ./bridges/Library_gcc3_linux_x86-64.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./bridges/Library_gcc3_linux_x86-64.mk	2013-02-19 17:34:24.000000000 -0500
@@ -41,9 +41,11 @@
 	) \
 ))
 
+ifeq ($(filter DRAGONFLY FREEBSD NETBSD OPENBSD MACOSX,$(OS)),)
 $(eval $(call gb_Library_add_libs,gcc3_uno,\
 	-ldl \
 ))
+endif
 
 $(eval $(call gb_Library_use_libraries,gcc3_uno,\
 	cppu \
