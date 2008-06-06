--- ttfm.sh.orig	2001-01-31 17:34:46.000000000 +0800
+++ ttfm.sh	2008-06-04 22:02:46.000000000 +0800
@@ -38,7 +38,7 @@
 
 VERSION=0.9.3
 
-export PREFIX; PREFIX=/usr/local
+export PREFIX; PREFIX=%%PREFIX%%
 export PATH; PATH=/bin:/sbin:/usr/bin:/usr/sbin:$PREFIX/bin:$PREFIX/sbin
 export DefaultFontPath; DefaultFontPath=$PREFIX/share/fonts/TrueType
 export ScriptDir; ScriptDir=$PREFIX/share/ttfm
@@ -258,7 +258,7 @@
 	# Call script with --remove
 	for i in "$INSTALLSCRIPT"; do
 	    if [ -x "$i" ] ; then
-		$i --remove "$FONTFILENAME" || {
+		$i --remove "${DefaultFontPath}/$FONTFILENAME" || {
 		    echo "Error in running $i to remove $DefaultFontPath/$FONTFILENAME." > /dev/stderr
 		}
 	    else
