--- canvas/source/cairo/makefile.mk.orig	2021-04-02 12:58:20 UTC
+++ canvas/source/cairo/makefile.mk
@@ -49,7 +49,7 @@ DLLPRE =
 
 
 .IF "$(SYSTEM_CAIRO)" == "YES"
-CFLAGS+=$(CAIRO_CFLAGS)
+INCSYSTEM+=$(CAIRO_CFLAGS)
 .ELSE
 CFLAGS+=-I$(SOLARINCDIR)/cairo
 .ENDIF
