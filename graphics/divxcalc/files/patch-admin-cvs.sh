--- admin/cvs.sh.orig	2003-05-25 06:51:54.000000000 -0700
+++ admin/cvs.sh	2007-09-22 19:53:05.000000000 -0700
@@ -30,54 +30,4 @@
 AUTOCONF_VERSION=`$AUTOCONF --version | head -1`
-case $AUTOCONF_VERSION in
-  Autoconf*2.5* | autoconf*2.5* ) : ;;
-  "" )
-    echo "*** AUTOCONF NOT FOUND!."
-    echo "*** KDE requires autoconf 2.52, 2.53 or 2.54"
-    exit 1
-    ;;
-  * )
-    echo "*** YOU'RE USING $AUTOCONF_VERSION."
-    echo "*** KDE requires autoconf 2.52, 2.53 or 2.54"
-    exit 1
-    ;;
-esac
- 
 AUTOHEADER_VERSION=`$AUTOHEADER --version | head -1`
-case $AUTOHEADER_VERSION in
-  Autoconf*2.5* | autoheader*2.5* ) : ;;
-  "" )
-    echo "*** AUTOHEADER NOT FOUND!."
-    echo "*** KDE requires autoheader 2.52 or 2.53 (part of autoconf)"
-    exit 1
-    ;;
-  * )
-    echo "*** YOU'RE USING $AUTOHEADER_VERSION."
-    echo "*** KDE requires autoheader 2.52 or 2.53 (part of autoconf)"
-    exit 1
-    ;;
-esac
-
 AUTOMAKE_STRING=`$AUTOMAKE --version | head -1`
-case $AUTOMAKE_STRING in
-  automake*1.5d* )
-    echo "*** YOU'RE USING $AUTOMAKE_STRING."
-    echo "*** KDE requires automake 1.5"
-    exit 1
-    ;;
-  automake*1.4* | automake*1.5* | automake*1.5-* | automake*1.6.* | automake*1.7* ) : ;;
-  "" )
-    echo "*** AUTOMAKE NOT FOUND!."
-    echo "*** KDE requires automake 1.5"
-    exit 1
-    ;;
-  unsermake* ) :
-    echo "*** YOU'RE USING UNSERMAKE."
-    echo "*** GOOD LUCK!! :)"
-    ;;
-  * )
-    echo "*** YOU'RE USING $AUTOMAKE_STRING."
-    echo "*** KDE requires automake 1.5"
-    exit 1
-    ;;
-esac
 }
