--- autogen.sh.orig	Sat Nov  1 14:50:38 2003
+++ autogen.sh	Mon Nov 10 16:24:17 2003
@@ -8,7 +8,7 @@
 SRCDIR=`dirname $0`
 DIE=0
 
-VER=`autoconf --version|grep '^[Aa]utoconf'|sed 's/^[^0-9]*//'`
+VER=`autoconf257 --version|grep '^[Aa]utoconf'|sed 's/^[^0-9]*//'`
 case "$VER" in
  0* | 1\.* | 2\.[0-9] | 2\.[0-9][a-z]* | \
  2\.[1-4][0-9] | 2\.5[0-6][a-z]* )
@@ -20,7 +20,7 @@
   ;;
 esac
 
-VER=`libtool --version|grep ' libtool)'|sed 's/.*) \([0-9][0-9.]*\) .*/\1/'`
+VER=`libtool13 --version|grep ' libtool)'|sed 's/.*) \([0-9][0-9.]*\) .*/\1/'`
 case "$VER" in
  0* | 1\.[0-2] | 1\.[0-2][a-z]* | \
  1\.3\.[0-2] | 1\.3\.[0-2][a-z]* )
@@ -50,18 +50,18 @@
 
 # Generate configure from configure.in
 echo "Running libtoolize ..."
-LIBTOOL_M4=`libtoolize --copy --force --dry-run|grep 'You should add the contents of'|sed "s,^[^/]*\(/[^']*\).*$,\1,"`
+LIBTOOL_M4=`libtoolize13 --copy --force --dry-run|grep 'You should add the contents of'|sed "s,^[^/]*\(/[^']*\).*$,\1,"`
 if test "x$LIBTOOL_M4" != "x"; then
  rm -f aclocal.m4
  cp $LIBTOOL_M4 aclocal.m4
 fi
-libtoolize --copy --force || exit 1
+libtoolize13 --copy --force || exit 1
 
 echo "Running autoheader ..."
-autoheader || exit 1
+autoheader257 || exit 1
 
 echo "Running autoconf ..."
-autoconf || exit 1
+autoconf257 || exit 1
 
 # If NOCONFIGURE is set, skip the call to configure
 if test "x$NOCONFIGURE" = "x"; then
