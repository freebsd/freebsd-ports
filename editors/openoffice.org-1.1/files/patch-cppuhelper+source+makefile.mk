--- ../cppuhelper/source/makefile.mk.orig	Thu Feb 20 17:04:36 2003
+++ ../cppuhelper/source/makefile.mk	Wed Mar  5 20:32:03 2003
@@ -194,9 +194,9 @@
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="LINUXIgcc3"
 SHL1VERSIONMAP=gcc3_linux_intel.map
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc2"
-#SHL1VERSIONMAP=gcc2_freebsd_intel.map
+SHL1VERSIONMAP=gcc2_linux_intel.map
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc3"
-#SHL1VERSIONMAP=gcc3_freebsd_intel.map
+SHL1VERSIONMAP=gcc3_linux_intel.map
 .ENDIF
 
 # --- Targets ------------------------------------------------------
