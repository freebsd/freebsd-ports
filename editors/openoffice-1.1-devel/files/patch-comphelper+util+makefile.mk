--- ../comphelper/util/makefile.mk.orig	Fri Feb 14 15:40:49 2003
+++ ../comphelper/util/makefile.mk	Wed Mar  5 20:43:02 2003
@@ -86,10 +86,10 @@
 
 SHL1TARGET=$(COMPHLP_TARGET)$(COMPHLP_MAJOR)$(COMID)
 SHL1STDLIBS= \
+	$(SALLIB) \
 	$(CPPUHELPERLIB) \
 	$(CPPULIB) \
-	$(VOSLIB) \
-	$(SALLIB)
+	$(VOSLIB)
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(COMPHLP_TARGET)
