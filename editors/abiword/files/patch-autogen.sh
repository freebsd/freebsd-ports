--- autogen.sh.orig	Fri Feb 20 08:29:23 2004
+++ autogen.sh	Sat Mar  6 03:36:00 2004
@@ -10,7 +10,7 @@
 
 rm -f autogen.err
 
-automake --version | perl -ne 'if (/\(GNU automake\) ([0-9].[0-9])/) {print;  if ($1 < 1.4) {exit 1;}}'
+%%AUTOMAKE%% --version | perl -ne 'if (/\(GNU automake\) ([0-9].[0-9])/) {print;  if ($1 < 1.4) {exit 1;}}'
 
 if [ $? -ne 0 ]; then
     echo "Error: you need automake 1.4 or later.  Please upgrade."
@@ -19,9 +19,9 @@
 
 # Produce aclocal.m4, so autoconf gets the automake macros it needs
 # 
-echo "Creating aclocal.m4: aclocal -I ac-helpers $ACLOCAL_FLAGS"
+echo "Creating aclocal.m4: %%ACLOCAL%% -I ac-helpers $ACLOCAL_FLAGS"
 
-aclocal -I ac-helpers $ACLOCAL_FLAGS 2>> autogen.err
+%%ACLOCAL%% -I ac-helpers $ACLOCAL_FLAGS 2>> autogen.err
 
 if test -f autom4te.cache/requests; then
     echo "Checking for PKG_CHECK_MODULES in autom4te.cache/requests ..."
@@ -32,9 +32,9 @@
 fi
 
 if test "x$pkgcheckdef" = "x"; then
-  echo "Running aclocal -I ac-helpers -I ac-helpers/pkg-config $ACLOCAL_FLAGS"
-  (aclocal -I ac-helpers -I ac-helpers/pkg-config $ACLOCAL_FLAGS 2>> autogen.err) || {
-    echo "aclocal failed! Unable to continue."
+  echo "Running %%ACLOCAL%% -I ac-helpers -I ac-helpers/pkg-config $ACLOCAL_FLAGS"
+  (%%ACLOCAL%% -I ac-helpers -I ac-helpers/pkg-config $ACLOCAL_FLAGS 2>> autogen.err) || {
+    echo "%%ACLOCAL%% failed! Unable to continue."
     exit 1
   }
   if test -f autom4te.cache/requests; then
@@ -62,9 +62,9 @@
 # Produce all the `GNUmakefile.in's and create neat missing things
 # like `install-sh', etc.
 # 
-echo "automake --add-missing --copy --foreign"
+echo "%%AUTOMAKE%% --add-missing --copy --foreign"
 
-automake --add-missing --copy --foreign 2>> autogen.err || {
+%%AUTOMAKE%% --add-missing --copy --foreign 2>> autogen.err || {
     echo ""
     echo "* * * warning: possible errors while running automake - check autogen.err"
     echo ""
@@ -80,7 +80,7 @@
 # 
 echo "Creating configure..."
 
-autoconf 2>> autogen.err || {
+%%AUTOCONF%% 2>> autogen.err || {
     echo ""
     echo "* * * warning: possible errors while running automake - check autogen.err"
     echo ""
