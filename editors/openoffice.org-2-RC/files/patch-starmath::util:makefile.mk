--- ../starmath/util/makefile.mk.orig	Tue Mar  5 21:44:02 2002
+++ ../starmath/util/makefile.mk	Tue Mar  5 21:44:22 2002
@@ -84,7 +84,9 @@
     $(SOLARVERSION)$/$(INPATH)$/res$(EXT_UPDMINOR)$/sfx.srs
 
 SHL1TARGET= sm$(UPD)$(DLLPOSTFIX)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= sm.map
+.ENDIF
 .IF "$(GUI)" == "WNT"
 SHL1RES=	$(RCTARGET)
 .ENDIF
