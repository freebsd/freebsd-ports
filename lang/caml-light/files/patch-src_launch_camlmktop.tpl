--- src/launch/camlmktop.tpl--	Mon Feb 24 16:01:07 1997
+++ src/launch/camlmktop.tpl	Sun Aug  6 12:01:27 2006
@@ -1,5 +1,6 @@
 #!/bin/sh
 
+camlrun=BINDIR/camlrun
 stdlib=LIBDIR
 linkfiles=""
 custom=""
@@ -58,11 +59,11 @@
   shift
 done
 
-camlrun $stdlib/provide -stdlib $stdlib $includes $perv > /tmp/camlreq.$$ \
+$camlrun $stdlib/provide -stdlib $stdlib $includes $perv > /tmp/camlreq.$$ \
   || exit $?
-camlrun $stdlib/camllink -stdlib $stdlib $custom -require /tmp/camlreq.$$ \
+$camlrun $stdlib/camllink -stdlib $stdlib $custom -require /tmp/camlreq.$$ \
   -exec /tmp/camlout.$$ -g $includes stdlib$p.zo toplib.zo $linkfiles topmain.zo || exit $?
-camlrun $stdlib/expunge $debug /tmp/camlout.$$ $output sys $perv || exit $?
+$camlrun $stdlib/expunge $debug /tmp/camlout.$$ $output sys $perv || exit $?
 rm -f /tmp/camlreq.$$ /tmp/camlout.$$
 if test -n "$custom"; then
   if mv $output /tmp/camlcode.$$ \
