--- scripts/copyExamples.sh.orig	Thu Aug  7 08:38:02 2003
+++ scripts/copyExamples.sh	Sat Dec 16 14:51:22 2006
@@ -1,4 +1,4 @@
-#!/bin/sh -h
+#!/bin/sh
 
 # copyExamples.sh <srcdir> <dstdir>
 
@@ -37,15 +37,13 @@
   for f in *[chp] *.v* *.tcl README; do
     if test -r $f; then
       rm -f $dstdir/$f
-      cp $f $dstdir
-      chmod u+w $dstdir/$f
+      install -m 644 $f $dstdir
     fi
   done
   # only copy Makefile in leaf dirs
   if test -r Makefile -a $isleaf = "yes"; then
     rm -f $dstdir/Makefile
-    cp Makefile $dstdir
-    chmod u+w $dstdir/Makefile
+    install -m 644 Makefile $dstdir
   fi
 
 fi
