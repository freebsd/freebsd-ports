--- salhelper/source/makefile.mk.orig	Wed Nov 14 14:19:21 2001
+++ salhelper/source/makefile.mk	Sun Mar  3 17:58:15 2002
@@ -109,6 +109,10 @@
 SHL1VERSIONMAP=lngi.map
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="LINUXIgcc3"
 SHL1VERSIONMAP=gcc3_linux_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc2"
+SHL1VERSIONMAP=gcc2_freebsd_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc3"
+SHL1VERSIONMAP=gcc3_freebsd_intel.map
 .ENDIF
 
 
