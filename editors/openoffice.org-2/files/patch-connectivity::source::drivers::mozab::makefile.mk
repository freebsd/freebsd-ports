--- ../connectivity/source/drivers/mozab/makefile.mk.orig	Mon Dec  3 17:20:59 2001
+++ ../connectivity/source/drivers/mozab/makefile.mk	Sun Mar  3 17:26:52 2002
@@ -107,7 +107,9 @@
 
 # --- MOZAB BASE Library -----------------------------------
 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= $(TARGET).map
+.ENDIF
 SHL1TARGET=	$(TARGET)$(MOZAB_MAJOR)
 SHL1OBJS=$(SLOFILES)
 SHL1STDLIBS=\
@@ -158,7 +160,9 @@
 
 # --- MOZAB BASE Library -----------------------------------
 
+.IF "$(OS)"!="FREEBSD"
 SHL2VERSIONMAP= $(TARGET2).map
+.ENDIF
 SHL2TARGET=	$(TARGET2)$(MOZAB_MAJOR)
 SHL2OBJS=$(SLO2FILES)
 SHL2STDLIBS=\
