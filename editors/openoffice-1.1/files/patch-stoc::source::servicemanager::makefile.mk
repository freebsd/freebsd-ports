--- ../stoc/source/servicemanager/makefile.mk.orig	Tue Jan  1 14:12:03 2002
+++ ../stoc/source/servicemanager/makefile.mk
@@ -84,9 +84,9 @@
 SHL1VERSIONMAP=$(TARGET).map
 
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPULIB)		\
-		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(TARGET)
