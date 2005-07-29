--- cppuhelper/source/makefile.mk.orig	Mon Mar 11 22:17:52 2002
+++ cppuhelper/source/makefile.mk	Wed Apr  3 00:31:19 2002
@@ -175,6 +175,10 @@
 #SHL1VERSIONMAP=gcc2_freebsd_intel.map
 .ELIF "$(OS)$(CPU)$(COMNAME)"=="LINUXIgcc3"
 SHL1VERSIONMAP=gcc3_linux_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc2"
+#SHL1VERSIONMAP=gcc2_freebsd_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)"=="FREEBSDIgcc3"
+#SHL1VERSIONMAP=gcc3_freebsd_intel.map
 .ENDIF
 
 # --- Targets ------------------------------------------------------
