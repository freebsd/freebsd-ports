--- admin/cvs.sh.orig	2009-07-15 01:33:20.000000000 -0700
+++ admin/cvs.sh	2012-04-24 09:22:32.000000000 -0700
@@ -65,8 +65,3 @@
 case $AUTOMAKE_STRING in
-  automake*1.5d* | automake*1.5* | automake*1.5-* )
-    echo "*** YOU'RE USING $AUTOMAKE_STRING."
-    echo "*** KDE requires automake $required_automake_version"
-    exit 1
-    ;;
-  automake*1.6.* | automake*1.7* | automake*1.8* | automake*1.9* | automake*1.10*) : ;;
+  automake*%%AUTOMAKE_VERSION%%* ) : ;;
   "" )
