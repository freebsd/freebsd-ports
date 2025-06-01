--- shell/source/backends/kdebe/makefile.mk.orig	2020-10-06 14:16:31 UTC
+++ shell/source/backends/kdebe/makefile.mk
@@ -45,7 +45,7 @@ DLLPRE =
 
 .IF "$(ENABLE_KDE)" == "TRUE"
 
-CFLAGS+=$(KDE_CFLAGS)
+INCSYSTEM+=$(KDE_CFLAGS)
 
 # --- Files ---
 
