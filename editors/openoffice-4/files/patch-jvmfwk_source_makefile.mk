--- jvmfwk/source/makefile.mk.orig	2021-04-02 12:58:21 UTC
+++ jvmfwk/source/makefile.mk
@@ -34,7 +34,8 @@ UNIXVERSIONNAMES = UDK
 .INCLUDE: settings.mk
 
 .IF "$(SYSTEM_LIBXML)" == "YES"
-CFLAGS+=-DSYSTEM_LIBXML $(LIBXML_CFLAGS)
+INCSYSTEM+=$(LIBXML_CFLAGS)
+CFLAGS+=-DSYSTEM_LIBXML
 .ENDIF
 
 UNOUCROUT = $(OUT)$/inc
