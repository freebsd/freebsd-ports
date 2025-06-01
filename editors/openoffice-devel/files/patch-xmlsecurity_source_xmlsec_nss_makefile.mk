--- xmlsecurity/source/xmlsec/nss/makefile.mk.orig	2019-09-17 22:55:25 UTC
+++ xmlsecurity/source/xmlsec/nss/makefile.mk
@@ -34,7 +34,8 @@ ENABLE_EXCEPTIONS = TRUE
 .INCLUDE :	$(PRJ)$/util$/target.pmk
 
 .IF "$(SYSTEM_LIBXML)" == "YES"
-CFLAGS+=-DSYSTEM_LIBXML $(LIBXML_CFLAGS)
+INCSYSTEM+=$(LIBXML_CFLAGS)
+CFLAGS+=-DSYSTEM_LIBXML
 .ENDIF
 
 .IF "$(ENABLE_NSS_MODULE)"!="YES"
