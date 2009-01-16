--- autogen.sh	2009-01-15 18:47:45.000000000 -0500
+++ autogen.sh	2009-01-15 18:48:58.000000000 -0500
@@ -1,61 +1,24 @@
 #! /bin/sh
 
-if [ "$USER" = "root" ]; then
-	echo "*** You cannot do this as "$USER" please use a normal user account."
-	exit 1
-fi
 if test ! -f configure.ac ; then
 	echo "*** Please invoke this script from directory containing configure.ac."
 	exit 1
 fi
 
 echo "running aclocal"
-aclocal
-rc=$?
-
-if test $rc -eq 0; then
-	echo "running libtool"
-	libtoolize --force --automake --copy
-	rc=$?
-else
-	echo "An error occured, autogen.sh stopping."
-	exit $rc
-fi
+%%ACLOCAL%%
 
-if test $rc -eq 0; then
-	echo "libtool worked."
-else
-	echo "libtool not found. trying glibtool."
-	glibtoolize --force --automake --copy
-	rc=$?
-fi
+echo "running libtool"
+%%LIBTOOLIZE%% --force --automake --copy
 
-if test $rc -eq 0; then
-	echo "running automake"
-	automake --add-missing --copy
-	rc=$?
-else
-	echo "An error occured, autogen.sh stopping."
-	exit $rc
-fi
+echo "running automake"
+%%AUTOMAKE%% --add-missing --copy
 
-if test $rc -eq 0; then
-	echo "running autoheader"
-	autoheader
-	rc=$?
-else
-	echo "An error occured, autogen.sh stopping."
-	exit $rc
-fi
+echo "running autoheader"
+%%AUTOHEADER%%
 
-if test $rc -eq 0; then
-	echo "running autoconf"
-	autoconf
-	rc=$?
-else
-	echo "An error occured, autogen.sh stopping."
-	exit $rc
-fi
+echo "running autoconf"
+%%AUTOCONF%%
 
 echo "autogen.sh complete"
 exit $rc
