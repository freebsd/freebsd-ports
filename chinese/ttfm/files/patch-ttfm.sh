--- ./ttfm.sh.orig	Wed Jan 31 17:34:46 2001
+++ ./ttfm.sh	Mon Nov 27 02:03:54 2006
@@ -258,7 +258,7 @@
 	# Call script with --remove
 	for i in "$INSTALLSCRIPT"; do
 	    if [ -x "$i" ] ; then
-		$i --remove "$FONTFILENAME" || {
+		$i --remove "${DefaultFontPath}/$FONTFILENAME" || {
 		    echo "Error in running $i to remove $DefaultFontPath/$FONTFILENAME." > /dev/stderr
 		}
 	    else
