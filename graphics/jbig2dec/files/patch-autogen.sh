--- autogen.sh.orig	2019-10-02 12:52:19 UTC
+++ autogen.sh
@@ -22,7 +22,7 @@ VERSIONGREP="sed -e s/.*[^0-9\.]\([0-9][
 VERSIONMKMAJ="sed -e s/\([0-9][0-9]*\)[^0-9].*/\\1/"
 VERSIONMKMIN="sed -e s/.*[0-9][0-9]*\.//"
 
-JBIG2VERSIONGREP="sed -e s/^.*(\([0-9]\+\)).*/\\1/"
+JBIG2VERSIONGREP="sed -e s/^.*(\([0-9]*\)).*/\1/"
 JBIG2MAJOR=$(grep 'define JBIG2_VERSION_MAJOR' jbig2.h | $JBIG2VERSIONGREP)
 JBIG2MINOR=$(grep 'define JBIG2_VERSION_MINOR' jbig2.h | $JBIG2VERSIONGREP)
 sed -e "s/^\(AC_INIT[^,]*,\)[^,]*\(,.*\)$/\1 [$JBIG2MAJOR.$JBIG2MINOR]\2/" configure.ac.in > configure.ac
@@ -169,12 +169,3 @@ $AUTOMAKE --add-missing --copy $AUTOMAKE
 
 echo "  autoconf"
 autoconf
-
-if test -z "$*"; then
-        echo "I am going to run ./configure with no arguments - if you wish "
-        echo "to pass any to it, please specify them on the $0 command line."
-else
-	echo "running ./configure $@"
-fi
-
-$srcdir/configure "$@" && echo
