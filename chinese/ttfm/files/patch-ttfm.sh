--- ttfm.sh.orig	Wed Jan 31 17:34:46 2001
+++ ttfm.sh	Sat Feb 19 09:14:56 2005
@@ -258,7 +258,7 @@
 	# Call script with --remove
 	for i in "$INSTALLSCRIPT"; do
 	    if [ -x "$i" ] ; then
-		$i --remove "$FONTFILENAME" || {
+		$i --remove "${DefaultFontPath}/$FONTFILENAME" || {
 		    echo "Error in running $i to remove $DefaultFontPath/$FONTFILENAME." > /dev/stderr
 		}
 	    else
