--- ../stoc/source/corereflection/makefile.mk.orig	Tue Jan  1 14:12:02 2002
+++ ../stoc/source/corereflection/makefile.mk
@@ -87,9 +87,9 @@
 SHL1TARGET=	$(TARGET)
 SHL1VERSIONMAP=	$(TARGET).map
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPULIB)		\
-		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(TARGET)
