--- l10ntools/source/help/makefile.mk.orig	2019-09-17 22:55:16 UTC
+++ l10ntools/source/help/makefile.mk
@@ -34,7 +34,7 @@ TARGETTYPE=CUI
 .INCLUDE : helplinker.pmk
  
 .IF "$(SYSTEM_LIBXSLT)" == "YES"
-CFLAGS+= $(LIBXSLT_CFLAGS)
+INCSYSTEM+= $(LIBXSLT_CFLAGS)
 .ELSE
 LIBXSLTINCDIR=external$/libxslt
 CFLAGS+= -I$(SOLARINCDIR)$/$(LIBXSLTINCDIR)
