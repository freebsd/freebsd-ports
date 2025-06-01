--- xmlhelp/source/cxxhelp/provider/makefile.mk.orig	2021-04-02 12:58:23 UTC
+++ xmlhelp/source/cxxhelp/provider/makefile.mk
@@ -49,14 +49,14 @@ CFLAGS +=  -DHAVE_EXPAT_H
 CFLAGS +=  -DHAVE_EXPAT_H
 
 .IF "$(SYSTEM_LIBXML)" == "YES"
-CFLAGS+= $(LIBXML_CFLAGS)
+INCSYSTEM+= $(LIBXML_CFLAGS)
 .ELSE
 LIBXMLINCDIR=external$/libxml
 CFLAGS+= -I$(SOLARINCDIR)$/$(LIBXMLINCDIR)
 .ENDIF
 
 .IF "$(SYSTEM_LIBXSLT)" == "YES"
-CFLAGS+= $(LIBXSLT_CFLAGS)
+INCSYSTEM+= $(LIBXSLT_CFLAGS)
 .ELSE
 LIBXSLTINCDIR=external$/libxslt
 CFLAGS+= -I$(SOLARINCDIR)$/$(LIBXSLTINCDIR)
