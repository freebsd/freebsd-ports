--- ./bridges/Library_gcc3_linux_intel.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./bridges/Library_gcc3_linux_intel.mk	2013-02-19 20:22:56.000000000 -0500
@@ -39,7 +39,7 @@
 	) \
 ))
 
-ifneq ($(OS),ANDROID)
+ifeq ($(filter ANDROID DRAGONFLY FREEBSD NETBSD OPENBSD MACOSX,$(OS)),)
 $(eval $(call gb_Library_add_libs,gcc3_uno,\
 	-ldl \
 ))
