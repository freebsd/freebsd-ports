--- stoc/source/typeconv/makefile.mk.orig	Tue Jan  1 14:12:03 2002
+++ stoc/source/typeconv/makefile.mk
@@ -82,9 +82,9 @@
 SHL1TARGET=	$(TARGET)
 
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPULIB)		\
-		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
 
 SHL1DEPN=
 SHL1VERSIONMAP=	$(TARGET).map
