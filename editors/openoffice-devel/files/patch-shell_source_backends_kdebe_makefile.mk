--- shell/source/backends/kdebe/makefile.mk.orig	2019-09-17 22:55:21 UTC
+++ shell/source/backends/kdebe/makefile.mk
@@ -45,7 +45,7 @@ DLLPRE =
 
 .IF "$(ENABLE_KDE)" == "TRUE"
 
-CFLAGS+=$(KDE_CFLAGS)
+INCSYSTEM+=$(KDE_CFLAGS)
 
 # --- Files ---
 
