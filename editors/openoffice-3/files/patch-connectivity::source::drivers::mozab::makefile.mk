--- ../connectivity/source/drivers/mozab/makefile.mk.orig	Sat Mar  2 20:56:52 2002
+++ ../connectivity/source/drivers/mozab/makefile.mk	Sat Mar  2 20:57:22 2002
@@ -107,7 +107,9 @@
 
 # --- MOZAB BASE Library -----------------------------------
 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= $(TARGET).map
+.ENDIF
 SHL1TARGET=	$(MOZAB_TARGET)$(MOZAB_MAJOR)
 SHL1OBJS=$(SLOFILES)
 SHL1STDLIBS=\
