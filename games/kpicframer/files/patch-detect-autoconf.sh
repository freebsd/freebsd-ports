Index: detect-autoconf.sh
===================================================================
RCS file: /cvs/kde/kde-common/admin/detect-autoconf.sh,v
retrieving revision 1.6
diff -u -r1.6 detect-autoconf.sh
--- admin/detect-autoconf.sh	30 Nov 2002 02:48:03 -0000	1.6
+++ admin/detect-autoconf.sh	29 Aug 2003 11:31:32 -0000
@@ -25,6 +25,8 @@
     AUTOCONF="`$WHICH autoconf-2.52`"
   elif test -x "`$WHICH autoconf2.50`" ; then
     AUTOCONF="`$WHICH autoconf2.50`"
+  elif test -x "`$WHICH autoconf257`" ; then
+    AUTOCONF="`$WHICH autoconf257`"
   fi
 }
 
@@ -46,6 +48,9 @@
     AUTOHEADER="`$WHICH autoheader-2.52`"
   elif test -x "`$WHICH autoheader2.50`" ; then
     AUTOHEADER="`$WHICH autoheader2.50`"
+  elif test -x "`$WHICH autoheader257`" ; then
+    AUTOHEADER="`$WHICH autoheader257`"
+    AUTOM4TE="`$WHICH autom4te257`"
   fi
 }
 
@@ -58,6 +63,9 @@
     elif test -x "`$WHICH automake-1.7`" ; then
       AUTOMAKE="`$WHICH automake-1.7`"
       ACLOCAL="`$WHICH aclocal-1.7`"
+    elif test -x "`$WHICH automake17`" ; then
+      AUTOMAKE="`$WHICH automake17`"
+      ACLOCAL="`$WHICH aclocal17`"
     fi
   else
      AUTOMAKE="$UNSERMAKE"
