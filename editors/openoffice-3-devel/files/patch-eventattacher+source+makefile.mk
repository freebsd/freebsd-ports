--- ../eventattacher/source/makefile.mk.orig	Tue Oct  1 09:45:21 2002
+++ ../eventattacher/source/makefile.mk	Wed Mar  5 21:06:11 2003
@@ -104,9 +104,9 @@
 SHL1TARGET=	$(TARGET)
 
 SHL1STDLIBS= \
+		$(SALLIB)					\
 		$(CPPULIB)					\
-		$(CPPUHELPERLIB)				\
-		$(SALLIB)
+		$(CPPUHELPERLIB)
 
 SHL1DEPN=
 SHL1IMPLIB=	i$(TARGET)
