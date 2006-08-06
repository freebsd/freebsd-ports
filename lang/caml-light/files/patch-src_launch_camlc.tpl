--- src/launch/camlc.tpl--	Sun Aug  6 12:07:15 2006
+++ src/launch/camlc.tpl	Sun Aug  6 12:00:03 2006
@@ -1,5 +1,6 @@
 #!/bin/sh
 
+camlrun=BINDIR/camlrun
 stdlib=LIBDIR
 linkalso=true
 includes=""
@@ -30,14 +31,14 @@
       if $profile
       then 
 	$stdlib/camlinstr -m $proflags -stdlib $stdlib $includes $compopt $1 ${1}t || { rc=$?; rm -f ${1}t; exit $rc; }
-        camlrun $stdlib/camlcomp -stdlib $stdlib $includes $compopt ${1}t || { rc=$?; rm -f ${1}t; exit $rc; }
+        $camlrun $stdlib/camlcomp -stdlib $stdlib $includes $compopt ${1}t || { rc=$?; rm -f ${1}t; exit $rc; }
 	rm -f ${1}t
       else
-        camlrun $stdlib/camlcomp -stdlib $stdlib $includes $compopt $1 || exit $?
+        $camlrun $stdlib/camlcomp -stdlib $stdlib $includes $compopt $1 || exit $?
       fi
       linkfiles="$linkfiles $1";;
     *.mli)
-      camlrun $stdlib/camlcomp -stdlib $stdlib $includes $compopt $1 || exit $?
+      $camlrun $stdlib/camlcomp -stdlib $stdlib $includes $compopt $1 || exit $?
       ;;
     *.zo)
       linkfiles="$linkfiles $1";;
@@ -63,9 +64,9 @@
     -v|-version)
       echo "The Caml Light system, version" VERSION
       echo "  (standard library from $stdlib)"
-      camlrun -V
-      camlrun $stdlib/camlcomp -version
-      camlrun $stdlib/camllink -version;;
+      $camlrun -V
+      $camlrun $stdlib/camlcomp -version
+      $camlrun $stdlib/camllink -version;;
     -files)
       linkfiles="$linkfiles $1 $2"
       shift;;
@@ -106,7 +107,7 @@
 done
 
 if $linkalso && test -n "$linkfiles"; then
-  camlrun $stdlib/camllink -stdlib $stdlib $includes $custom $linkopt \
+  $camlrun $stdlib/camllink -stdlib $stdlib $includes $custom $linkopt \
     -exec $linkout $stdlib/stdlib$p.zo $linkfiles $prodump || exit $?
   if test -n "$custom"; then
     if mv $linkout /tmp/camlcode.$$ \
