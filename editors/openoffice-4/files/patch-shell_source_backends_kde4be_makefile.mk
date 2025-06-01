--- shell/source/backends/kde4be/makefile.mk.orig	2020-10-06 14:16:31 UTC
+++ shell/source/backends/kde4be/makefile.mk
@@ -45,7 +45,7 @@ DLLPRE =
 
 .IF "$(ENABLE_KDE4)" == "TRUE"
 
-CFLAGS+=$(KDE4_CFLAGS)
+INCSYSTEM+=$(KDE4_CFLAGS)
 
 # --- Files ---
 
