--- ../remotebridges/source/unourl_resolver/makefile.mk.orig	Tue Jan  1 14:11:01 2002
+++ ../remotebridges/source/unourl_resolver/makefile.mk
@@ -102,9 +102,9 @@
 SHL1VERSIONMAP=	$(TARGET).map
 
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPULIB)		\
-		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(TARGET)
