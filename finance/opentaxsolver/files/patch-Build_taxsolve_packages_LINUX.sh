$FreeBSD$

--- Build_taxsolve_packages_LINUX.sh.orig	2009-05-09 11:10:10.000000000 -0600
+++ Build_taxsolve_packages_LINUX.sh	2012-02-11 09:23:27.000000000 -0700
@@ -1,11 +1,15 @@
 #!/bin/sh
 
+# die on errors
+set -e
+
 TAXSOLVEDIR=${PWD}/`dirname $0`
 
 if [ ! -d ${TAXSOLVEDIR}/bin ] ; then
    mkdir ${TAXSOLVEDIR}/bin
 fi
 
+if [ -z "$WITHOUT_X11" -a -z "${WITHOUT_X11+isset}" ] ; then
 cd ${TAXSOLVEDIR}/src/GUI/
 if [ !  -d  otk_lib ] ; then
    echo ""
@@ -23,6 +27,7 @@
 else 
    make -f Makefile.linux 
 fi 
+fi 
 
 cd  "${TAXSOLVEDIR}/src"
 make -f Makefile.unix
