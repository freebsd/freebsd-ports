--- ../bridges/source/prot_uno/makefile.mk.orig	Fri Oct 26 09:22:57 2001
+++ ../bridges/source/prot_uno/makefile.mk	Wed Mar  6 15:45:09 2002
@@ -88,8 +88,8 @@
 SHL1VERSIONMAP=..$/bridge_exports.map
 
 SHL1STDLIBS= \
-	$(CPPULIB)		\
-	$(SALLIB)
+	$(SALLIB) \
+	$(CPPULIB)
 
 DEF1NAME=$(SHL1TARGET)
 
