--- ../comphelper/util/makefile.mk.orig	Tue Jan  1 14:08:53 2002
+++ ../comphelper/util/makefile.mk
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
 
 SHL1DEPN=
