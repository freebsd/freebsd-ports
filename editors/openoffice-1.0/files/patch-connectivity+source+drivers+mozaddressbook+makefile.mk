--- connectivity/source/drivers/mozaddressbook/makefile.mk.orig	Wed Jun 12 01:40:36 2002
+++ connectivity/source/drivers/mozaddressbook/makefile.mk	Wed Jun 12 01:40:37 2002
@@ -134,9 +134,7 @@
 SLOFILES+=$(SLO)$/staticmbmozab.obj
 .ENDIF
 
-.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= $(TARGET).map
-.ENDIF
 # --- Library -----------------------------------
 
 SHL1TARGET=$(TARGET)$(UPD)$(DLLPOSTFIX)
