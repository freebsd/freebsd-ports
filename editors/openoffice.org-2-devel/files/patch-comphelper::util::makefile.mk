--- ../comphelper/util/makefile.mk.orig	Tue Feb 19 13:26:37 2002
+++ ../comphelper/util/makefile.mk	Wed Apr  3 00:16:43 2002
@@ -85,11 +85,11 @@
 
 SHL1TARGET=$(COMPHLP_TARGET)$(COMPHLP_MAJOR)
 SHL1STDLIBS=\
+	$(SALLIB)					\
 	$(CPPULIB)					\
 	$(CPPUHELPERLIB)			\
 	$(VOSLIB)					\
 	$(OSLLIB)					\
-	$(SALLIB)					\
 	$(CPPRTLLIB)
 
 .IF "$(OS)$(CPU)"=="SOLARISS"
