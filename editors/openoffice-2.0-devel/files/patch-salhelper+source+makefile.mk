--- ../salhelper/source/makefile.mk	Sun Mar  3 01:30:52 2002
+++ ../salhelper/source/makefile.mk	Sun Mar  3 01:30:59 2002
@@ -109,6 +109,8 @@
 SHL1VERSIONMAP=soli.map
 .ELIF "$(OS)$(CPU)"=="LINUXI"
 SHL1VERSIONMAP=lngi.map
+.ELIF "$(OS)$(CPU)"=="FREEBSDI"
+SHL1VERSIONMAP=fbsdi.map
 .ENDIF
 
 
