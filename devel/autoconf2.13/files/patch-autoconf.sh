--- autoconf.sh.orig	2000-02-27 16:18:10 UTC
+++ autoconf.sh
@@ -45,7 +45,6 @@ esac
 esac
 
 : ${TMPDIR=/tmp}
-tmpout=${TMPDIR}/acout.$$
 localdir=
 show_version=no
 
@@ -95,9 +94,12 @@ esac
   *) echo "$usage" >&2; exit 1 ;;
 esac
 
+tmpout=`mktemp ${TMPDIR}/acout.XXXXXXXXXX` || exit 1
+tmpin=`mktemp ${TMPDIR}/acin.XXXXXXXXXX` || { rm -f $tmpout; exit 1; }
+
 trap 'rm -f $tmpin $tmpout; exit 1' 1 2 15
 
-tmpin=${TMPDIR}/acin.$$ # Always set this, to avoid bogus errors from some rm's.
+# Always set this, to avoid bogus errors from some rm's.
 if test z$infile = z-; then
   infile=$tmpin
   cat > $infile
@@ -118,7 +120,7 @@ case `$M4 --help < /dev/null 2>&1` in
 case `$M4 --help < /dev/null 2>&1` in
 *reload-state*) test -r $AC_MACRODIR/autoconf.m4f && { r=--reload f=f; } ;;
 *traditional*) ;;
-*) echo Autoconf requires GNU m4 1.1 or later >&2; rm -f $tmpin; exit 1 ;;
+*) echo Autoconf requires GNU m4 1.1 or later >&2; rm -f $tmpin $tmpout; exit 1 ;;
 esac
 
 $M4 -I$AC_MACRODIR $use_localdir $r autoconf.m4$f $infile > $tmpout ||
@@ -154,6 +156,6 @@ $AWK '
 /__oline__/s/^\([0-9][0-9]*\):\(.*\)__oline__/\2\1/
 ' >&4
 
-rm -f $tmpout
+rm -f $tmpin $tmpout
 
 exit $status
