--- ../cppuhelper/source/makefile.mk.orig	Sat Mar  2 21:08:19 2002
+++ ../cppuhelper/source/makefile.mk	Sat Mar  2 21:08:08 2002
@@ -174,6 +174,8 @@
 SHL1VERSIONMAP=cc5_solaris_sparc.map
 .ELIF "$(OS)$(CPU)$(COM)"=="LINUXIGCC"
 SHL1VERSIONMAP=gcc2_linux_intel.map
+.ELIF "$(OS)$(CPU)"=="FREEBSDI"
+#SHL1VERSIONMAP=gcc2_freebsd_intel.map
 .ENDIF
 
 # --- Targets ------------------------------------------------------
