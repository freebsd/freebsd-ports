--- ../cppuhelper/source/makefile.mk.orig	Wed Nov 14 14:17:37 2001
+++ ../cppuhelper/source/makefile.mk	Sun Mar  3 17:40:47 2002
@@ -173,6 +173,10 @@
 SHL1VERSIONMAP=gcc2_linux_intel.map
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="LINUXIgcc3"
 SHL1VERSIONMAP=gcc3_linux_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc2"
+#SHL1VERSIONMAP=gcc2_freebsd_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc3"
+#SHL1VERSIONMAP=gcc3_freebsd_intel.map
 .ENDIF
 
 # --- Targets ------------------------------------------------------
