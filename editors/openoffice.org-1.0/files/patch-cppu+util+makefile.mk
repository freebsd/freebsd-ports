--- cppu/util/makefile.mk.orig	Wed Jun 12 01:39:28 2002
+++ cppu/util/makefile.mk	Wed Jun 12 01:39:32 2002
@@ -87,9 +87,7 @@
 
 SHL1DEPN=
 SHL1IMPLIB=i$(TARGET)
-.IF "$(OS)"!="FREEBSD"
 SHL1DEF=$(MISC)$/$(SHL1TARGET).def
-.ENDIF
 
 SHL1VERSIONMAP=$(TARGET).map
 
