--- make/gcc.mak.orig	Sat Sep 10 16:45:50 2005
+++ make/gcc.mak	Thu Sep  7 20:39:52 2006
@@ -14,7 +14,7 @@
 MAKEOVERRIDES=
 
 # The install prefix and directories
-prefix		= /usr
+prefix		= ${PREFIX}
 exec_prefix	= $(prefix)
 
 bindir		= $(exec_prefix)/bin
@@ -37,9 +37,9 @@
 INSTALL		= install
 #INSTALL		= install-sh
 
-INSTALL_DATA	= $(INSTALL) -c -m 644
-INSTALL_PROG	= $(INSTALL) -c -m 755
-INSTALL_STRIP	= $(INSTALL_PROG) -s
+INSTALL_DATA	= ${BSD_INSTALL_DATA}
+INSTALL_PROG	= ${BSD_INSTALL_SCRIPT}
+INSTALL_STRIP	= ${BSD_INSTALL_PROGRAM}
 
 # Rules
 
@@ -48,7 +48,7 @@
 # a system on the command-line.  (A user can do those rules with their
 # defaults by putting "all samples tests" on the command-line.)
 #
-all:	bins libs docs $(SYS:%=samples tests)
+all:	bins libs $(SYS:%=samples tests)
 
 bins:
 	@$(MAKE) -C src -f make/gcc.mak
@@ -139,7 +139,4 @@
 	  done
 	for f in readme.1st compile.txt CREDITS BUGS internal.txt newvers.txt; \
 	  do $(INSTALL_DATA) doc/$$f $(CC65DOC) || exit 1; \
-	  done
-	-for f in doc/*.html; \
-	  do $(INSTALL_DATA) $$f $(CC65DOC) || exit 1; \
 	  done
