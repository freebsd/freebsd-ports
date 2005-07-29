--- solenv/inc/tg_ext.mk.orig	Fri May 10 14:12:12 2002
+++ solenv/inc/tg_ext.mk	Mon Jul 15 14:34:30 2002
@@ -81,7 +81,9 @@
 .ENDIF			# "$(GUI)"=="WNT"
 
 .IF "$(OS)"!="NETBSD"
+.IF "$(OS)"!="FREEBSD"
 PATCHFLAGS=-b
+.ENDIF			# "$(OS)"=="FREEBSD"
 .ENDIF			# "$(OS)"=="NETBSD"
 
 #override
