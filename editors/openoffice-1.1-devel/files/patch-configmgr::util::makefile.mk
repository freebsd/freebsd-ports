--- ../configmgr/util/makefile.mk.orig	Sat Mar  2 20:36:09 2002
+++ ../configmgr/util/makefile.mk	Sat Mar  2 20:36:24 2002
@@ -73,7 +73,7 @@
 # --- Library -----------------------------------
 
 SHL1TARGET=	$(CFGMGR_TARGET)$(CFGMGR_MAJOR)
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP= $(TARGET).$(DLLPOSTFIX).map
 .ELSE
 SHL1VERSIONMAP= $(TARGET).map
