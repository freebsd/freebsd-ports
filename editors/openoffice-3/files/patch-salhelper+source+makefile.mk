--- ../salhelper/source/makefile.mk.orig	Sat May 31 23:48:19 2003
+++ ../salhelper/source/makefile.mk	Sat May 31 23:48:21 2003
@@ -114,6 +114,10 @@
 SHL1VERSIONMAP=lngi.map
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="LINUXIgcc3"
 SHL1VERSIONMAP=gcc3_linux_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc2"
+SHL1VERSIONMAP=lngi.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc3"
+SHL1VERSIONMAP=gcc3_linux_intel.map
 .ENDIF
 
 # --- Targets ------------------------------------------------------
