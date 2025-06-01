--- connectivity/source/drivers/evoab2/makefile.mk.orig	2019-09-17 22:55:11 UTC
+++ connectivity/source/drivers/evoab2/makefile.mk
@@ -41,7 +41,7 @@ PKGCONFIG_MODULES=gtk+-2.0
 PKGCONFIG_MODULES=gtk+-2.0
 .INCLUDE : pkg_config.mk
 
-CFLAGS+=$(GOBJECT_CFLAGS)
+INCSYSTEM+=$(GOBJECT_CFLAGS)
 
 # --- Files -------------------------------------
 
