--- ../store/util/makefile.mk.orig	Tue Mar  5 21:47:39 2002
+++ ../store/util/makefile.mk	Tue Mar  5 21:47:59 2002
@@ -88,7 +88,7 @@
 
 SHL1TARGET= 	$(TARGET)
 SHL1IMPLIB= 	istore
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP=	$(TARGET).$(DLLPOSTFIX).map
 .ELSE
 SHL1VERSIONMAP=	$(TARGET).map
