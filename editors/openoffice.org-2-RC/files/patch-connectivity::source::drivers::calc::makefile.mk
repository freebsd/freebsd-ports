--- ../connectivity/source/drivers/calc/makefile.mk.orig	Sat Mar  2 20:42:07 2002
+++ ../connectivity/source/drivers/calc/makefile.mk	Sat Mar  2 20:41:59 2002
@@ -91,7 +91,7 @@
 	$(SLO)$/Cservices.obj			\
 	$(SLO)$/CDriver.obj
 
-.IF "$(OS)"!="MACOSX"
+.IF "$(OS)"!="MACOSX" || "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= $(TARGET).map
 .ENDIF
 # --- Library -----------------------------------
