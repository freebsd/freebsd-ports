--- ../connectivity/source/drivers/adabas/makefile.mk.orig	Sat Mar  2 20:39:00 2002
+++ ../connectivity/source/drivers/adabas/makefile.mk	Sat Mar  2 20:38:16 2002
@@ -104,9 +104,9 @@
 		$(SLO)$/BResultSetMetaData.obj			\
         $(SLO)$/BResultSet.obj
 		
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP=$(ADABAS_TARGET).$(DLLPOSTFIX).map
-.ELSE
+.ELSE      
 SHL1VERSIONMAP=$(ADABAS_TARGET).map
 .ENDIF
 
