--- ../connectivity/source/drivers/flat/makefile.mk.orig	Sat Mar  2 20:51:31 2002
+++ ../connectivity/source/drivers/flat/makefile.mk	Sat Mar  2 20:51:56 2002
@@ -104,7 +104,7 @@
 	$(SLO)$/EDriver.obj
 
 
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP=$(TARGET).$(DLLPOSTFIX).map
 .ELSE      
 SHL1VERSIONMAP=$(TARGET).map
