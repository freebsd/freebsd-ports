--- ../sch/util/makefile.mk.orig	Sun Mar  3 01:37:53 2002
+++ ../sch/util/makefile.mk	Sun Mar  3 01:38:16 2002
@@ -111,7 +111,9 @@
 
 
 SHL1TARGET= sch$(UPD)$(DLLPOSTFIX)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= sch.map
+.ENDIF
 .IF "$(GUI)" == "WNT" || "$(GUI)" == "WIN"
 SHL1RES=	$(RCTARGET)
 .ENDIF
