--- ../sc/util/makefile.mk.orig	Mon Mar 11 21:48:24 2002
+++ ../sc/util/makefile.mk	Wed Apr  3 01:06:57 2002
@@ -105,7 +105,9 @@
 # --- StarClac DLL
 
 SHL1TARGET= sc$(UPD)$(DLLPOSTFIX)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP= sc.map
+.ENDIF
 SHL1IMPLIB= sci
 
 .IF "$(GUI)"=="UNX"
