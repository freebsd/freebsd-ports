$FreeBSD$

--- ../../j2se/make/java/java/localegen.sh.orig	2008-01-06 16:38:14.000000000 +0100
+++ ../../j2se/make/java/java/localegen.sh	2008-01-06 16:51:26.000000000 +0100
@@ -22,7 +22,7 @@
 localelist=
 getlocalelist() {
     localelist=""
-    localelist=`$NAWK -F$1_ '{print $2}' $2 | sort`
+    localelist=`$SED -e 'y/ /\n/' -e 's/\\\n//g' $2 | $NAWK -F$1_ '{print \$2}' | sort`
 }
 
 sed_script="$SED -e \"s@^#warn .*@// -- This file was mechanically generated: Do not edit! -- //@\" " 


