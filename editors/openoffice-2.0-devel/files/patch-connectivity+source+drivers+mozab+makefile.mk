--- ../connectivity/source/drivers/mozab/makefile.mk.orig	Wed Oct 30 20:59:21 2002
+++ ../connectivity/source/drivers/mozab/makefile.mk	Wed Oct 30 20:59:31 2002
@@ -115,9 +115,7 @@
 # --- MOZAB BASE Library -----------------------------------
 
 SHL1VERSIONMAP= $(TARGET).map
-.IF "$(OS)"!="FREEBSD"
 SHL1TARGET=	$(TARGET)$(MOZAB_MAJOR)
-.ENDIF
 SHL1OBJS=$(SLOFILES)
 SHL1STDLIBS=\
 	$(CPPULIB)					\
