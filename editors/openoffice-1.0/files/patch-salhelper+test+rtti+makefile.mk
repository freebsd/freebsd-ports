--- salhelper/test/rtti/makefile.mk.orig	Sat Jul 20 23:11:56 2002
+++ salhelper/test/rtti/makefile.mk	Sat Jul 20 23:12:01 2002
@@ -116,6 +116,10 @@
 SHL1VERSIONMAP=	sols.map
 .ELIF "$(OS)$(CPU)"=="LINUXI"
 SHL1VERSIONMAP= lngi.map
+.ELIF "$(OS)$(CPU)$(COMNAME)" == "GCCFREEBSDIgcc2"
+SHL1VERSIONMAP= gcc2_freebsd_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)" == "GCCFREEBSDIgcc3"
+SHL1VERSIONMAP= gcc3_freebsd_intel.map
 .ENDIF
 
 
