--- autogen.sh.orig	Thu Oct 17 08:19:31 2002
+++ autogen.sh	Fri Feb 21 23:47:48 2003
@@ -10,20 +10,20 @@
 
 rm -f autogen.err
 
-automake --version | perl -ne 'if (/\(GNU automake\) ([0-9].[0-9])/) {print;  if ($1 < 1.4) {exit 1;}}'
+%%AUTOMAKE%% --version | perl -ne 'if (/\(GNU automake\) ([0-9].[0-9])/) {print; if ($1 < 1.4) {exit 1;}}'
 
 if [ $? -ne 0 ]; then
     echo "Error: you need automake 1.4 or later.  Please upgrade."
     exit 1
 fi
 
-if test ! -d `aclocal --print-ac-dir 2>> autogen.err`; then
-  echo "Bad aclocal (automake) installation"
+if test ! -d `%%ACLOCAL%% --print-ac-dir 2>> autogen.err`; then
+  echo "Bad %%ACLOCAL%% (automake) installation"
   exit 1
 fi
 
 for script in `cd ac-helpers/fallback; echo *.m4`; do
-  if test -r `aclocal --print-ac-dir 2>> autogen.err`/$script; then
+  if test -r `%%ACLOCAL%% --print-ac-dir 2>> autogen.err`/$script; then
     # Perhaps it was installed recently
     rm -f ac-helpers/$script
   else
@@ -34,17 +34,17 @@
 
 # Produce aclocal.m4, so autoconf gets the automake macros it needs
 # 
-echo "Creating aclocal.m4: aclocal -I ac-helpers $ACLOCAL_FLAGS"
+echo "Creating aclocal.m4: %%ACLOCAL%% -I ac-helpers $ACLOCAL_FLAGS"
 
-aclocal -I ac-helpers $ACLOCAL_FLAGS 2>> autogen.err
+%%ACLOCAL%% -I ac-helpers $ACLOCAL_FLAGS 2>> autogen.err
 
 echo "Checking for PKG_CHECK_MODULES..."
 
 pkgcheckdef=`grep PKG_CHECK_MODULES aclocal.m4 | grep AC_DEFUN`
 if test "x$pkgcheckdef" = "x"; then
-  echo "Running aclocal -I ac-helpers -I ac-helpers/pkg-config $ACLOCAL_FLAGS"
-  (aclocal -I ac-helpers -I ac-helpers/pkg-config $ACLOCAL_FLAGS 2>> autogen.err) || {
-    echo "aclocal failed! Unable to continue."
+  echo "Running %%ACLOCAL%% -I ac-helpers -I ac-helpers/pkg-config $ACLOCAL_FLAGS"
+  (%%ACLOCAL%% -I ac-helpers -I ac-helpers/pkg-config $ACLOCAL_FLAGS 2>> autogen.err) || {
+    echo "%%ACLOCAL%% failed! Unable to continue."
     exit 1
   }
   pkgcheckdef=`grep PKG_CHECK_MODULES aclocal.m4 | grep AC_DEFUN`
@@ -66,9 +66,9 @@
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
@@ -84,7 +84,7 @@
 # 
 echo "Creating configure..."
 
-autoconf 2>> autogen.err || {
+%%AUTOCONF%% 2>> autogen.err || {
     echo ""
     echo "* * * warning: possible errors while running automake - check autogen.err"
     echo ""
