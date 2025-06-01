--- xmlsecurity/source/xmlsec/makefile.mk.orig	2020-10-06 14:16:36 UTC
+++ xmlsecurity/source/xmlsec/makefile.mk
@@ -34,7 +34,8 @@ ENABLE_EXCEPTIONS = TRUE
 .INCLUDE :	$(PRJ)$/util$/target.pmk
 
 .IF "$(SYSTEM_LIBXML)" == "YES"
-CFLAGS+=-DSYSTEM_LIBXML $(LIBXML_CFLAGS)
+INCSYSTEM+=$(LIBXML_CFLAGS)
+CFLAGS+=-DSYSTEM_LIBXML
 .ENDIF
 
 .IF "$(ENABLE_NSS_MODULE)"!="YES"
