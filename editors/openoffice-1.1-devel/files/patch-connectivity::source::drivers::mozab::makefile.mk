--- ../connectivity/source/drivers/mozab/makefile.mk.orig	Mon Aug 19 19:23:47 2002
+++ ../connectivity/source/drivers/mozab/makefile.mk	Wed Oct 16 00:01:36 2002
@@ -167,7 +167,9 @@
 
 # --- MOZAB BASE Library -----------------------------------
 
+.IF "$(OS)"!="FREEBSD"
 SHL2VERSIONMAP= $(TARGET2).map
+.ENDIF
 SHL2TARGET=	$(TARGET2)$(MOZAB_MAJOR)
 SHL2OBJS=$(SLO2FILES)
 SHL2STDLIBS=\
