--- ../salhelper/test/rtti/makefile.mk.orig	Sat May 31 23:49:55 2003
+++ ../salhelper/test/rtti/makefile.mk	Sat May 31 23:50:20 2003
@@ -116,6 +116,8 @@
 SHL1VERSIONMAP=	sols.map
 .ELIF "$(OS)$(CPU)"=="LINUXI"
 SHL1VERSIONMAP= lngi.map
+.ELIF "$(OS)$(CPU)"=="FREEBSDI"
+SHL1VERSIONMAP= lngi.map
 .ENDIF
 
 
