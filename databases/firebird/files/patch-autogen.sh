--- autogen.sh.orig	Fri Apr 18 04:41:28 2003
+++ autogen.sh	Sun Aug 24 18:39:45 2003
@@ -20,7 +20,7 @@
   ;;
 esac
 
-VER=`libtool --version|grep ' libtool)'|sed 's/.*) \([0-9][0-9.]*\) .*/\1/'`
+VER=`libtool13 --version|grep ' libtool)'|sed 's/.*) \([0-9][0-9.]*\) .*/\1/'`
 case "$VER" in
  0* | 1\.[0-2] | 1\.[0-2][a-z]* | \
  1\.3\.[0-2] | 1\.3\.[0-2][a-z]* )
@@ -50,12 +50,12 @@
 
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
 
 echo "Running autoconf ..."
 autoconf || exit 1
