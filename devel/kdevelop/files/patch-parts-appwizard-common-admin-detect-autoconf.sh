--- parts/appwizard/common/admin/detect-autoconf.sh.orig	Wed Mar  3 22:22:59 2004
+++ parts/appwizard/common/admin/detect-autoconf.sh	Wed Mar  3 21:47:49 2004
@@ -17,6 +17,8 @@
     AUTOCONF="`$WHICH autoconf-2.5x`"
   elif test -x "`$WHICH autoconf-2.57 2>/dev/null`" ; then
     AUTOCONF="`$WHICH autoconf-2.57`"
+  elif test -x "`$WHICH autoconf259 2>/dev/null`" ; then
+    AUTOCONF="`$WHICH autoconf259`"
   elif test -x "`$WHICH autoconf-2.56 2>/dev/null`" ; then
     AUTOCONF="`$WHICH autoconf-2.56`"
   elif test -x "`$WHICH autoconf-2.55 2>/dev/null`" ; then
@@ -42,6 +44,9 @@
   elif test -x "`$WHICH autoheader-2.57 2>/dev/null`" ; then
     AUTOHEADER="`$WHICH autoheader-2.57`"
     AUTOM4TE="`$WHICH autom4te-2.57`"
+  elif test -x "`$WHICH autoheader259 2>/dev/null`" ; then
+    AUTOHEADER="`$WHICH autoheader259`"
+    AUTOM4TE="`$WHICH autom4te259`"
   elif test -x "`$WHICH autoheader-2.56 2>/dev/null`" ; then
     AUTOHEADER="`$WHICH autoheader-2.56`"
     AUTOM4TE="`$WHICH autom4te-2.56`"
@@ -72,6 +77,9 @@
   elif test -x "`$WHICH automake-1.7 2>/dev/null`" ; then
     AUTOMAKE="`$WHICH automake-1.7`"
     ACLOCAL="`$WHICH aclocal-1.7`"
+  elif test -x "`$WHICH automake19 2>/dev/null`" ; then
+    AUTOMAKE="`$WHICH automake19`"
+    ACLOCAL="`$WHICH aclocal19`"
   fi
   if test -n "$UNSERMAKE"; then 
      AUTOMAKE="$UNSERMAKE"
