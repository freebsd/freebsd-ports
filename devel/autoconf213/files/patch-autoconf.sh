--- autoconf.sh.orig	Tue Jan  5 07:27:53 1999
+++ autoconf.sh	Thu May 31 15:56:39 2001
@@ -47,3 +47,2 @@
 : ${TMPDIR=/tmp}
-tmpout=${TMPDIR}/acout.$$
 localdir=
@@ -97,5 +96,8 @@
 
+tmpout=`mktemp ${TMPDIR}/acout.XXXXXXXXXX` || exit 1
+tmpin=`mktemp ${TMPDIR}/acin.XXXXXXXXXX` || { rm -f $tmpout; exit 1; }
+
 trap 'rm -f $tmpin $tmpout; exit 1' 1 2 15
 
-tmpin=${TMPDIR}/acin.$$ # Always set this, to avoid bogus errors from some rm's.
+# Always set this, to avoid bogus errors from some rm's.
 if test z$infile = z-; then
@@ -120,3 +122,3 @@
 *traditional*) ;;
-*) echo Autoconf requires GNU m4 1.1 or later >&2; rm -f $tmpin; exit 1 ;;
+*) echo Autoconf requires GNU m4 1.1 or later >&2; rm -f $tmpin $tmpout; exit 1 ;;
 esac
@@ -156,3 +158,3 @@
 
-rm -f $tmpout
+rm -f $tmpin $tmpout
 
