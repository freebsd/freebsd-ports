--- ../eventattacher/source/makefile.mk.orig	Tue Jan  1 14:09:28 2002
+++ ../eventattacher/source/makefile.mk
@@ -110,10 +110,10 @@
 SHL1TARGET=	$(TARGET)
 
 SHL1STDLIBS= \
+		$(SALLIB)					\
 		$(CPPULIB)					\
 		$(CPPUHELPERLIB)				\
-		$(VOSLIB)					\
-		$(SALLIB)
+		$(VOSLIB)					
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(TARGET)
