--- ../cppu/util/makefile.mk.orig	Fri Nov  9 10:14:31 2001
+++ ../cppu/util/makefile.mk	Mon Mar 11 13:35:07 2002
@@ -89,7 +89,9 @@
 SHL1IMPLIB=i$(TARGET)
 SHL1DEF=$(MISC)$/$(SHL1TARGET).def
 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=$(TARGET).map
+.ENDIF
 
 DEF1NAME=$(SHL1TARGET)
 
