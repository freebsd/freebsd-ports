--- admin/cvs.sh.orig	2005-05-27 12:57:46.000000000 -0700
+++ admin/cvs.sh	2007-09-22 22:42:52.000000000 -0700
@@ -31,61 +31,5 @@
 {
-required_autoconf_version="2.53 or newer"
 AUTOCONF_VERSION=`$AUTOCONF --version | head -n 1`
-case $AUTOCONF_VERSION in
-  Autoconf*2.5* | autoconf*2.5* ) : ;;
-  "" )
-    echo "*** AUTOCONF NOT FOUND!."
-    echo "*** KDE requires autoconf $required_autoconf_version"
-    exit 1
-    ;;
-  * )
-    echo "*** YOU'RE USING $AUTOCONF_VERSION."
-    echo "*** KDE requires autoconf $required_autoconf_version"
-    exit 1
-    ;;
-esac
- 
 AUTOHEADER_VERSION=`$AUTOHEADER --version | head -n 1`
-case $AUTOHEADER_VERSION in
-  Autoconf*2.5* | autoheader*2.5* ) : ;;
-  "" )
-    echo "*** AUTOHEADER NOT FOUND!."
-    echo "*** KDE requires autoheader $required_autoconf_version"
-    exit 1
-    ;;
-  * )
-    echo "*** YOU'RE USING $AUTOHEADER_VERSION."
-    echo "*** KDE requires autoheader $required_autoconf_version"
-    exit 1
-    ;;
-esac
-
-unset UNSERMAKE || :
-
 AUTOMAKE_STRING=`$AUTOMAKE --version | head -n 1`
-required_automake_version="1.6.1 or newer"
-case $AUTOMAKE_STRING in
-  automake*1.5d* | automake*1.5* | automake*1.5-* )
-    echo "*** YOU'RE USING $AUTOMAKE_STRING."
-    echo "*** KDE requires automake $required_automake_version"
-    exit 1
-    ;;
-  automake*1.6.* | automake*1.7* | automake*1.8* | automake*1.9*) : ;;
-  "" )
-    echo "*** AUTOMAKE NOT FOUND!."
-    echo "*** KDE requires automake $required_automake_version"
-    exit 1
-    ;;
-  *unsermake* ) :
-    echo "*** YOU'RE USING UNSERMAKE."
-    echo "*** GOOD LUCK!! :)"
-    UNSERMAKE=unsermake
-    ;;
-  * )
-    echo "*** YOU'RE USING $AUTOMAKE_STRING."
-    echo "*** KDE requires automake $required_automake_version"
-    exit 1
-    ;;
-esac
-unset required_automake_version
 }
