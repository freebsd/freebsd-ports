--- src/launch/camllight.tpl--	Fri Jun 23 22:28:07 1995
+++ src/launch/camllight.tpl	Sun Aug  6 12:00:50 2006
@@ -1,6 +1,7 @@
 #!/bin/sh
 
 stdlib=LIBDIR
+camlrun=BINDIR/camlrun
 includes=""
 options=""
 
@@ -12,7 +13,7 @@
 while : ; do
   case $1 in
     "")
-      exec camlrun $stdlib/camltop -stdlib $stdlib $includes $options;;
+      exec $camlrun $stdlib/camltop -stdlib $stdlib $includes $options;;
     -I|-include)
       includes="$includes -I $2"
       shift;;
