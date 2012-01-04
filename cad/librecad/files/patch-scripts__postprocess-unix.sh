--- ./scripts/postprocess-unix.sh.orig	2011-12-14 18:07:34.000000000 +0000
+++ ./scripts/postprocess-unix.sh	2012-01-03 10:28:08.510074137 +0000
@@ -18,19 +18,9 @@
 cp support/patterns/*.dxf $RESOURCEDIR/patterns
 #cp support/fonts/*.cxf $RESOURCEDIR/fonts
 cp support/fonts/*.lff* $RESOURCEDIR/fonts
-#cp support/doc/*.qhc $RESOURCEDIR/doc
-#cp support/doc/*.qch $RESOURCEDIR/doc
+cp support/doc/*.qhc $RESOURCEDIR/doc
+cp support/doc/*.qch $RESOURCEDIR/doc
 find support/library -type d -not -path "*.svn*"  | sed s/support// | xargs -IFILES  mkdir $RESOURCEDIR/FILES
 find support/library -type f -iname *.dxf -not -path "*.svn*"  | sed s/support// | xargs -IFILES  cp support/FILES $RESOURCEDIR/FILES
 
-# Generate translations
-lrelease librecad.pro
-mkdir -p $RESOURCEDIR/qm
- 
-# Go into translations directory
-cd "$TSDIR"
-for tf in *.qm
-do
-		cp $tf $RESOURCEDIR/qm/$tf
-done
 
