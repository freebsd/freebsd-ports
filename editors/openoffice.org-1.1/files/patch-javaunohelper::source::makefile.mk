--- ../javaunohelper/source/makefile.mk.orig	Tue Jan  1 14:10:20 2002
+++ ../javaunohelper/source/makefile.mk
@@ -110,9 +110,9 @@
 SHL1TARGET=	$(TARGET)
 
 SHL1STDLIBS= \
+		$(SALLIB)		\
 		$(CPPULIB)		\
-		$(CPPUHELPERLIB)	\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(TARGET)
