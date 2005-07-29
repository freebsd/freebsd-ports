--- connectivity/source/drivers/calc/makefile.mk.orig	Wed Jun 12 01:36:16 2002
+++ connectivity/source/drivers/calc/makefile.mk	Wed Jun 12 01:36:22 2002
@@ -92,9 +92,7 @@
 	$(SLO)$/CDriver.obj
 
 .IF "$(OS)"!="MACOSX"
-.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= $(TARGET).map
-.ENDIF
 .ENDIF
 # --- Library -----------------------------------
 
