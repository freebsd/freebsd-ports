--- ../connectivity/source/drivers/mozaddressbook/makefile.mk.orig	Sat Mar  2 20:58:59 2002
+++ ../connectivity/source/drivers/mozaddressbook/makefile.mk	Sat Mar  2 20:59:41 2002
@@ -134,7 +134,9 @@
 SLOFILES+=$(SLO)$/staticmbmozab.obj
 .ENDIF
 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= $(TARGET).map
+.ENDIF
 # --- Library -----------------------------------
 
 SHL1TARGET=$(TARGET)$(UPD)$(DLLPOSTFIX)
