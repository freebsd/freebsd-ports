#i48978#

Index: bridges/source/cpp_uno/gcc2_freebsd_intel/makefile.mk
===================================================================
RCS file: /cvs/udk/bridges/source/cpp_uno/gcc2_freebsd_intel/Attic/makefile.mk,v
retrieving revision 1.1
diff -u -r1.1 makefile.mk
--- bridges/source/cpp_uno/gcc2_freebsd_intel/makefile.mk	12 Nov 2001 22:43:04 -0000	1.1
+++ bridges/source/cpp_uno/gcc2_freebsd_intel/makefile.mk	10 May 2005 01:12:25 -0000
@@ -76,7 +76,7 @@
 
 # --- Files --------------------------------------------------------
 
-.IF "$(COM)$(OS)$(CPU)" == "GCCFREEBSDI"
+.IF "$(COM)$(OS)$(CPU)$(COMNAME)" == "GCCFREEBSDIgcc2"
 
 CFLAGSNOOPT=-O0
 NOOPTFILES=$(SLO)$/uno2cpp.obj
