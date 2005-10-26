--- data/makefonts.sh.orig	Mon May  5 03:07:30 1997
+++ data/makefonts.sh	Wed Oct 26 11:30:34 2005
@@ -4,5 +4,5 @@
 ../fnttobdf -tr <$i | bdftopcf > `basename $i .fnt`-iso.pcf
 done
 mkfontdir .
-xset fp+ `pwd`
-xset fp rehash
+#xset fp+ `pwd`
+#xset fp rehash
