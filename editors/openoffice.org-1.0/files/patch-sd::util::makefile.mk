--- ../sd/util/makefile.mk.orig	Sun Mar  3 01:39:39 2002
+++ ../sd/util/makefile.mk	Sun Mar  3 01:40:09 2002
@@ -108,7 +108,9 @@
 # --- StarDraw DLL
 
 SHL1TARGET= sd$(UPD)$(DLLPOSTFIX)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= sd.map
+.ENDIF
 SHL1IMPLIB= sdi
 SHL1STDLIBS=        \
 	$(SCHLIB) \
