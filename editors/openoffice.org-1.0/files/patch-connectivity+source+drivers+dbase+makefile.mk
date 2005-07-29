--- connectivity/source/drivers/dbase/makefile.mk.orig	Wed Jun 12 01:26:39 2002
+++ connectivity/source/drivers/dbase/makefile.mk	Wed Jun 12 01:26:48 2002
@@ -116,7 +116,7 @@
 	$(SLO)$/DDriver.obj
 
 
-.IF "$(OS)"=="MACOSX"||"$(OS)"=="FREEBSD"
+.IF "$(OS)"=="MACOSX"
 #SHL1VERSIONMAP=$(TARGET).$(DLLPOSTFIX).map
 .ELSE      
 SHL1VERSIONMAP=$(TARGET).map
