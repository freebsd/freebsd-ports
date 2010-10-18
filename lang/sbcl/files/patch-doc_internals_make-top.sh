--- doc/internals/make-top.sh.orig	2010-10-18 11:50:18.000000000 -0700
+++ doc/internals/make-top.sh	2010-10-18 11:50:53.000000000 -0700
@@ -31,7 +31,7 @@
 for texinfo in *.texinfo
 do
   if ! [ $texinfo = sbcl-internals.texinfo ]; then
-      grep @node $texinfo | head -n 1 | perl -p -e "s/\@node\ (.*)/* \$1::/" >> top-menu.include
+      sed '/@node/ { s/@node \(.*\)/* \1::/; q; }' $texinfo >> top-menu.include
       echo "@include $texinfo" >> top-include.include
   fi
 done
