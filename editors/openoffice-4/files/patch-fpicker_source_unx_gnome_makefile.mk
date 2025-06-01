--- fpicker/source/unx/gnome/makefile.mk.orig	2021-04-02 12:58:21 UTC
+++ fpicker/source/unx/gnome/makefile.mk
@@ -56,7 +56,7 @@ CFLAGS+= $(WIDGETSET_CFLAGS)
 .ELSE
 
 CFLAGS+= $(WIDGETSET_CFLAGS)
-CFLAGS+= $(PKGCONFIG_CFLAGS)
+INCSYSTEM+= $(PKGCONFIG_CFLAGS)
 
 # --- Files --------------------------------------------------------
 
