--- ./extensions/Library_npsoplugin.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./extensions/Library_npsoplugin.mk	2013-02-19 17:00:56.000000000 -0500
@@ -44,9 +44,11 @@
 
 ifeq ($(GUI),UNX)
 
+ifeq ($(filter DRAGONFLY FREEBSD NETBSD OPENBSD MACOSX,$(OS)),)
 $(eval $(call gb_Library_add_libs,npsoplugin,\
 	-ldl \
 ))
+endif
 
 $(eval $(call gb_Library_use_external,npsoplugin,gtk))
 
