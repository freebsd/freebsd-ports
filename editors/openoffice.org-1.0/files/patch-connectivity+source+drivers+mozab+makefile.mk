--- connectivity/source/drivers/mozab/makefile.mk.orig	Wed Jun 12 01:37:30 2002
+++ connectivity/source/drivers/mozab/makefile.mk	Wed Jun 12 01:37:47 2002
@@ -107,9 +107,7 @@
 # --- MOZAB BASE Library -----------------------------------
 
 SHL1VERSIONMAP= $(TARGET).map
-.IF "$(OS)"!="FREEBSD"
 SHL1TARGET=	$(TARGET)$(MOZAB_MAJOR)
-.ENDIF
 SHL1OBJS=$(SLOFILES)
 SHL1STDLIBS=\
 	$(CPPULIB)					\
