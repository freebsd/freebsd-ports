--- ../cppu/util/makefile.mk.orig	Sat Mar  2 21:05:22 2002
+++ ../cppu/util/makefile.mk	Sat Mar  2 21:05:43 2002
@@ -87,7 +87,9 @@
 SHL1IMPLIB=	i$(TARGET)
 SHL1DEF=	$(MISC)$/$(SHL1TARGET).def
 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=	$(TARGET).map
+.ENDIF
 
 DEF1NAME=	$(SHL1TARGET)
 #DEF1EXPORTFILE=	exports.dxp
