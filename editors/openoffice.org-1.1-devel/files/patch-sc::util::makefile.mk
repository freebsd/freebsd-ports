--- ../sc/util/makefile.mk.orig	Sun Mar  3 01:35:09 2002
+++ ../sc/util/makefile.mk	Sun Mar  3 01:34:53 2002
@@ -105,7 +105,9 @@
 # --- StarClac DLL
 
 SHL1TARGET= sc$(UPD)$(DLLPOSTFIX)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= sc.map
+.ENDIF
 SHL1IMPLIB= sci
 
 SHL1STDLIBS=        \
