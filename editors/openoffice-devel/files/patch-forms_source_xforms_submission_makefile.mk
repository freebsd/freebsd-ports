--- forms/source/xforms/submission/makefile.mk.orig	2019-09-17 22:55:15 UTC
+++ forms/source/xforms/submission/makefile.mk
@@ -34,7 +34,8 @@ ENABLE_EXCEPTIONS=TRUE
 .INCLUDE: $(PRJ)$/makefile.pmk
 
 .IF "$(SYSTEM_LIBXML)" == "YES"
-CFLAGS+=-DSYSTEM_LIBXML $(LIBXML_CFLAGS)
+INCSYSTEM+=$(LIBXML_CFLAGS)
+CFLAGS+=-DSYSTEM_LIBXML
 .ENDIF
 
 # --- Files --------------------------------------------------------
