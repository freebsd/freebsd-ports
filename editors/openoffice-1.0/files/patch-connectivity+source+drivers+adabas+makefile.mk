--- connectivity/source/drivers/adabas/makefile.mk.orig	Wed Jun 12 01:06:20 2002
+++ connectivity/source/drivers/adabas/makefile.mk	Wed Jun 12 01:06:34 2002
@@ -104,7 +104,7 @@
 		$(SLO)$/BResultSetMetaData.obj			\
         $(SLO)$/BResultSet.obj
 		
-.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
+.IF "$(OS)"=="MACOSX"
 #SHL1VERSIONMAP=$(ADABAS_TARGET).$(DLLPOSTFIX).map
 .ELSE      
 SHL1VERSIONMAP=$(ADABAS_TARGET).map
