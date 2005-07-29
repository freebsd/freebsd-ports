--- connectivity/source/drivers/flat/makefile.mk.orig	Wed Jun 12 01:14:43 2002
+++ connectivity/source/drivers/flat/makefile.mk	Wed Jun 12 01:15:03 2002
@@ -104,7 +104,7 @@
 	$(SLO)$/EDriver.obj
 
 
-.IF "$(OS)"=="MACOSX"||"$(OS)"=="FREEBSD"
+.IF "$(OS)"=="MACOSX"
 #SHL1VERSIONMAP=$(TARGET).$(DLLPOSTFIX).map
 .ELSE      
 SHL1VERSIONMAP=$(TARGET).map
