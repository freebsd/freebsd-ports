--- connectivity/source/drivers/evoab2/makefile.mk.orig	2020-10-06 14:16:17 UTC
+++ connectivity/source/drivers/evoab2/makefile.mk
@@ -41,7 +41,7 @@ PKGCONFIG_MODULES=gtk+-2.0
 PKGCONFIG_MODULES=gtk+-2.0
 .INCLUDE : pkg_config.mk
 
-CFLAGS+=$(GOBJECT_CFLAGS)
+INCSYSTEM+=$(GOBJECT_CFLAGS)
 
 # --- Files -------------------------------------
 
