--- scripts/ReferenceOpt.sh.orig	2019-05-03 12:58:47 UTC
+++ scripts/ReferenceOpt.sh
@@ -400,7 +400,7 @@ done
 
 cut -f4 -d " " kopt.data > plot.kopt.data
 gnuplot << \EOF
-set terminal dumb size 120, 30
+set terminal dumb size 80, 30
 set autoscale
 unset label
 set title "Histogram of number of reference contigs"
