--- forms/source/xforms/xpathlib/makefile.mk.orig	2019-09-17 22:55:15 UTC
+++ forms/source/xforms/xpathlib/makefile.mk
@@ -36,7 +36,8 @@ INCPRE+=$(PRJ)$/source$/inc
 INCPRE+=$(PRJ)$/source$/inc
 
 .IF "$(SYSTEM_LIBXML)" == "YES"
-CFLAGS+=-DSYSTEM_LIBXML $(LIBXML_CFLAGS)
+INCSYSTEM+=$(LIBXML_CFLAGS)
+CFLAGS+=-DSYSTEM_LIBXML
 .ENDIF
 
 # --- Files --------------------------------------------------------
