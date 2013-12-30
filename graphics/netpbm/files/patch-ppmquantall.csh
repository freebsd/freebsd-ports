--- editor/ppmquantall.csh.orig	2006-08-19 05:12:28.000000000 +0200
+++ editor/ppmquantall.csh	2013-12-25 21:56:17.183814873 +0100
@@ -30,8 +30,8 @@
 set widths=()
 set heights=()
 foreach i ( $files )
-    set widths=( $widths `sed '1d; s/ .*//; 2q' $i` )
-    set heights=( $heights `sed '1d; s/.* //; 2q' $i` )
+    set widths=( $widths `grep -v '^#' "$i" | sed '1d; s/ .*//; 2q'` )
+    set heights=( $heights `grep -v '^#' "$i" | sed '1d; s/.* //; 2q'` )
 end
 
 set all=/tmp/pqa.all.$$
