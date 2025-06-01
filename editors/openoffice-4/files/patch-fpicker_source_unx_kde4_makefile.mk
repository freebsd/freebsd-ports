--- fpicker/source/unx/kde4/makefile.mk.orig	2021-04-02 12:58:21 UTC
+++ fpicker/source/unx/kde4/makefile.mk
@@ -43,7 +43,7 @@ dummy:
 
 .ELSE # we build for KDE
 
-CFLAGS+= $(KDE4_CFLAGS)
+INCSYSTEM+= $(KDE4_CFLAGS)
 
 # --- Files --------------------------------------------------------
 
