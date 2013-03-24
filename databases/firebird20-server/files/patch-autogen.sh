--- autogen.sh	2013-03-23 22:16:00.000000000 -0500
+++ autogen.sh	2013-03-23 22:17:07.000000000 -0500
@@ -19,10 +19,13 @@
 AUTOMAKE=true
 export AUTOMAKE
 
+ACLOCAL='aclocal -I .'
+export ACLOCAL
+
 VER=`$AUTORECONF --version|grep '^[Aa]utoreconf'|sed 's/^[^0-9]*//'`
 case "$VER" in
  0* | 1\.* | 2\.[0-9] | 2\.[0-9][a-z]* | \
- 2\.[1-4][0-9] | 2\.[1-4][0-9][a-z]* | 2\.5[0-5] | 2\.5[0-5][a-z]* )
+ 2\.[1-4][0-9] | 2\.5[0-5][a-z]* )
   echo
   echo "**Error**: You must have autoconf 2.56 or later installed."
   echo "Download the appropriate package for your distribution/OS,"
@@ -55,14 +58,14 @@
 
 # Ensure correct utilities are called by AUTORECONF
 autopath=`dirname $AUTORECONF`
-if [ "x$autopath" != "x" ]; then
+if [ "$autopath" != "x" ]; then
 	PATH=$autopath:$PATH
 	export PATH
 fi
 
 # Generate configure from configure.in
 echo "Running autoreconf ..."
-$AUTORECONF --install --force --verbose || exit 1
+$AUTORECONF --install --force --verbose -I ./m4 || exit 1
 
 # Hack to bypass bug in autoreconf - --install switch not passed to libtoolize,
 # therefore missing config.sub and confg.guess files
