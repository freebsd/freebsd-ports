--- bridges/source/cpp_uno/gcc2_freebsd_intel/makefile.mk.orig	Fri May 31 10:22:18 2002
+++ bridges/source/cpp_uno/gcc2_freebsd_intel/makefile.mk	Fri May 31 10:22:46 2002
@@ -76,7 +76,7 @@
 
 # --- Files --------------------------------------------------------
 
-.IF "$(COM)$(OS)$(CPU)" == "GCCFREEBSDI"
+.IF "$(COM)$(OS)$(CPU)$(COMNAME)-$(EXCEPTIONS)" == "GCCFREEBSDIgcc2-dwarf2"
 
 CFLAGSNOOPT=-O0
 NOOPTFILES=$(SLO)$/uno2cpp.obj
