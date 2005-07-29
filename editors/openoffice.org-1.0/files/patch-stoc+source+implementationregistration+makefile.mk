--- stoc/source/implementationregistration/makefile.mk.orig	Tue Jan  1 14:12:02 2002
+++ stoc/source/implementationregistration/makefile.mk
@@ -85,9 +85,9 @@
 SHL1VERSIONMAP=$(TARGET).map
 
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPULIB)		\
-		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(TARGET)
