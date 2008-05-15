--- make/gcc.mak.orig	2007-06-22 00:40:27.000000000 +0400
+++ make/gcc.mak	2008-05-15 12:55:04.000000000 +0400
@@ -14,7 +14,7 @@
 MAKEOVERRIDES=
 
 # The install prefix and directories
-prefix		= /usr/local
+prefix		= ${PREFIX}
 exec_prefix	= $(prefix)
 
 bindir		= $(exec_prefix)/bin
@@ -36,9 +36,9 @@
 # BSD-like install-script/-program
 INSTALL		= make/install-sh
 
-INSTALL_DATA	= $(INSTALL) -c -m 644
-INSTALL_PROG	= $(INSTALL) -c -m 755
-INSTALL_STRIP	= $(INSTALL_PROG) -s
+INSTALL_DATA	= ${BSD_INSTALL_DATA}
+INSTALL_PROG	= ${BSD_INSTALL_SCRIPT}
+INSTALL_STRIP	= ${BSD_INSTALL_PROGRAM}
 
 # This file-name extension is needed on DOS/Windows systems.
 ifdef COMSPEC
@@ -52,7 +52,7 @@
 # a system on the command-line.  (A user can do those rules with their
 # defaults by putting "all samples tests" on the command-line.)
 #
-all:	bins libs docs $(SYS:%=samples tests)
+all:	bins libs $(SYS:%=samples tests)
 
 bins:
 	@$(MAKE) -C src -f make/gcc.mak CC65_INC=\\\"${CC65INC}/\\\" CC65_LIB=\\\"${CC65LIB}/\\\"
