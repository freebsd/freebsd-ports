--- ../connectivity/source/drivers/mozab/makefile.mk.orig	Mon Mar 11 16:07:41 2002
+++ ../connectivity/source/drivers/mozab/makefile.mk	Wed Apr  3 00:23:37 2002
@@ -159,7 +159,9 @@
 
 # --- MOZAB BASE Library -----------------------------------
 
+.IF "$(OS)"!="FREEBSD"
 SHL2VERSIONMAP= $(TARGET2).map
+.ENDIF
 SHL2TARGET=	$(TARGET2)$(MOZAB_MAJOR)
 SHL2OBJS=$(SLO2FILES)
 SHL2STDLIBS=\
