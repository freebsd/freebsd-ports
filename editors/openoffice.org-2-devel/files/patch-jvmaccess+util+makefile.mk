--- ../jvmaccess/util/makefile.mk.orig	Wed Mar 12 23:52:25 2003
+++ ../jvmaccess/util/makefile.mk	Wed Mar 12 23:52:50 2003
@@ -90,6 +90,8 @@
 SHL1VERSIONMAP = cc5_solaris_sparc.map
 .ELIF "$(OS)$(CPU)$(COMNAME)" == "LINUXIgcc3"
 SHL1VERSIONMAP = gcc3_linux_intel.map
+.ELIF "$(OS)$(CPU)$(COMNAME)" == "FREEBSDIgcc3"
+SHL1VERSIONMAP = gcc3_linux_intel.map
 .ENDIF
 
 DEF1NAME = $(SHL1TARGET)
