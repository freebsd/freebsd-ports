--- leif/autogen.sh	Thu Dec 11 15:29:55 2003
+++ leif/autogen.sh	Wed Feb 16 16:53:53 2005
@@ -6,6 +6,14 @@
 
 DIE=0
 
+LIBTOOL=libtool15
+INTLTOOLIZE=intltoolize
+LIBTOOLIZE=libtoolize15
+ACLOCAL=aclocal15
+AUTOHEADER=autoheader253
+AUTOMAKE=automake15
+AUTOCONF=autoconf253
+
 ACLOCAL_FLAGS="-I ../acfiles $ACLOCAL_FLAGS"
 
 if [ -n "$GNOME2_DIR" ]; then
@@ -22,7 +30,7 @@
     exit 1
 }
 
-(autoconf --version) < /dev/null > /dev/null 2>&1 || {
+(${AUTOCONF} --version) < /dev/null > /dev/null 2>&1 || {
   echo
   echo "**Error**: You must have \`autoconf' installed."
   echo "Download the appropriate package for your distribution,"
@@ -31,7 +39,7 @@
 }
 
 (grep "^AC_PROG_INTLTOOL" $srcdir/configure.ac >/dev/null) && {
-  (intltoolize --version) < /dev/null > /dev/null 2>&1 || {
+  (${INTLTOOLIZE} --version) < /dev/null > /dev/null 2>&1 || {
     echo 
     echo "**Error**: You must have \`intltool' installed."
     echo "You can get it from:"
@@ -41,7 +49,7 @@
 }
 
 (grep "^AM_PROG_LIBTOOL" $srcdir/configure.ac >/dev/null) && {
-  (libtool --version) < /dev/null > /dev/null 2>&1 || {
+  (${LIBTOOL} --version) < /dev/null > /dev/null 2>&1 || {
     echo
     echo "**Error**: You must have \`libtool' installed."
     echo "You can get it from: ftp://ftp.gnu.org/pub/gnu/"
@@ -59,7 +67,7 @@
   }
 }
 
-(automake --version) < /dev/null > /dev/null 2>&1 || {
+(${AUTOMAKE} --version) < /dev/null > /dev/null 2>&1 || {
   echo
   echo "**Error**: You must have \`automake' installed."
   echo "You can get it from: ftp://ftp.gnu.org/pub/gnu/"
@@ -69,7 +77,7 @@
 
 
 # if no automake, don't bother testing for aclocal
-test -n "$NO_AUTOMAKE" || (aclocal --version) < /dev/null > /dev/null 2>&1 || {
+test -n "$NO_AUTOMAKE" || (${ACLOCAL} --version) < /dev/null > /dev/null 2>&1 || {
   echo
   echo "**Error**: Missing \`aclocal'.  The version of \`automake'"
   echo "installed doesn't appear recent enough."
@@ -114,24 +122,24 @@
       fi
       if grep "^AC_PROG_INTLTOOL" configure.ac >/dev/null; then
         echo "Running intltoolize..."
-	intltoolize --copy --force --automake
+	${INTLTOOLIZE} --copy --force --automake
       fi
       if grep "^AM_PROG_LIBTOOL" configure.ac >/dev/null; then
 	if test -z "$NO_LIBTOOLIZE" ; then 
 	  echo "Running libtoolize..."
-	  libtoolize --force --copy
+	  ${LIBTOOLIZE} --force --copy
 	fi
       fi
       echo "Running aclocal $aclocalinclude ..."
-      aclocal $aclocalinclude
+      ${ACLOCAL} $aclocalinclude
       if grep "^AM_CONFIG_HEADER" configure.ac >/dev/null; then
 	echo "Running autoheader..."
-	autoheader
+	${AUTOHEADER}
       fi
       echo "Running automake --gnu $am_opt ..."
-      automake --add-missing --copy --gnu $am_opt
+      ${AUTOMAKE} --add-missing --copy --gnu $am_opt
       echo "Running autoconf ..."
-      autoconf
+      ${AUTOCONF}
     )
   fi
 done
