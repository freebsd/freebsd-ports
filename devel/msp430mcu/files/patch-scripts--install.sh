--- scripts/install.sh.orig	2014-06-07 20:49:35.000000000 +0400
+++ scripts/install.sh	2014-06-07 20:50:51.000000000 +0400
@@ -4,6 +4,7 @@
 # This file is part of msp430mcu (http://sourceforge.net/projects/mspgcc/)
 
 PREFIX=${1:-/msp430/install/dev}
+DISTDIR=${2:-${PREFIX}}
 MSP430MCU_ROOT=${MSP430MCU_ROOT:-${MSP430_ROOT:-/msp430}/msp430mcu}
 UPSTREAM=${MSP430MCU_ROOT}/upstream
 ANALYSIS=${MSP430MCU_ROOT}/analysis
@@ -11,9 +12,13 @@
 VERSION=`cat ${MSP430MCU_ROOT}/.version`
 UPSTREAM_VERSION=`cat ${MSP430MCU_ROOT}/upstream/.version`
 
-BINPATH=${PREFIX}/bin
-INCPATH=${PREFIX}/msp430/include
-LIBPATH=${PREFIX}/msp430/lib
+PBINPATH=${PREFIX}/bin
+PINCPATH=${PREFIX}/msp430/include
+PLIBPATH=${PREFIX}/msp430/lib
+
+BINPATH=${DISTDIR}/bin
+INCPATH=${DISTDIR}/msp430/include
+LIBPATH=${DISTDIR}/msp430/lib
 
 mkdir -p ${INCPATH} ${LIBPATH} ${BINPATH}
 
@@ -37,8 +42,8 @@
 cat bin/msp430mcu-config.in \
 | sed \
     -e 's!@PREFIX@!'"${PREFIX}"'!g' \
-    -e 's!@SCRIPTPATH@!'"${LIBPATH}/ldscripts"'!g' \
-    -e 's!@INCPATH@!'"${INCPATH}"'!g' \
+    -e 's!@SCRIPTPATH@!'"${PLIBPATH}/ldscripts"'!g' \
+    -e 's!@INCPATH@!'"${PINCPATH}"'!g' \
     -e 's!@VERSION@!'"${VERSION}"'!g' \
     -e 's!@UPSTREAM_VERSION@!'"${UPSTREAM_VERSION}"'!g' \
 > ${BINPATH}/msp430mcu-config \
