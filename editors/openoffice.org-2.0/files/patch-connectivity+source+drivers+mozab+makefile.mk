--- ../connectivity/source/drivers/mozab/makefile.mk.orig	Mon Mar 11 16:07:41 2002
+++ ../connectivity/source/drivers/mozab/makefile.mk	Sun May 19 14:10:59 2002
@@ -107,9 +107,7 @@
 # --- MOZAB BASE Library -----------------------------------
 
 SHL1VERSIONMAP= $(TARGET).map
-.IF "$(OS)"!="FREEBSD"
 SHL1TARGET=	$(TARGET)$(MOZAB_MAJOR)
-.ENDIF
 SHL1OBJS=$(SLOFILES)
 SHL1STDLIBS=\
 	$(CPPULIB)					\
@@ -159,7 +157,9 @@
 
 # --- MOZAB BASE Library -----------------------------------
 
+.IF "$(OS)"!="FREEBSD"
 SHL2VERSIONMAP= $(TARGET2).map
+.ENDIF
 SHL2TARGET=	$(TARGET2)$(MOZAB_MAJOR)
 SHL2OBJS=$(SLO2FILES)
 SHL2STDLIBS=\
