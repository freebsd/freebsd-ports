--- ../salhelper/source/makefile.mk.orig	Sun Sep  1 18:22:39 2002
+++ ../salhelper/source/makefile.mk	Wed Mar 12 23:54:12 2003
@@ -114,6 +114,10 @@
 SHL1VERSIONMAP=lngi.map
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="LINUXIgcc3"
 SHL1VERSIONMAP=gcc3_linux_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc2"
+SHL1VERSIONMAP=gcc2_linux_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc3"
+SHL1VERSIONMAP=gcc3_linux_intel.map
 .ENDIF
 
 # --- Targets ------------------------------------------------------
