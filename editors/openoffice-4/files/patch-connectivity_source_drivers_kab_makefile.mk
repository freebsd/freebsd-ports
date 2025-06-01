--- connectivity/source/drivers/kab/makefile.mk.orig	2021-04-02 12:58:20 UTC
+++ connectivity/source/drivers/kab/makefile.mk
@@ -38,7 +38,7 @@ VISIBILITY_HIDDEN=TRUE
 .IF "$(GUI)" == "UNX"
 .IF "$(ENABLE_KAB)" == "TRUE"
 
-CFLAGS+=$(KDE_CFLAGS)
+INCSYSTEM+=$(KDE_CFLAGS)
 
 .IF "$(KDE_ROOT)"!=""
 EXTRALIBPATHS+=-L$(KDE_ROOT)$/lib
