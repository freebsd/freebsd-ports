--- ../connectivity/source/drivers/dbase/makefile.mk.orig	Sat Mar  2 20:45:45 2002
+++ ../connectivity/source/drivers/dbase/makefile.mk	Sat Mar  2 20:45:27 2002
@@ -117,7 +117,7 @@
 	$(SLO)$/DDriver.obj
 
 
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP=$(TARGET).$(DLLPOSTFIX).map
 .ELSE      
 SHL1VERSIONMAP=$(TARGET).map
