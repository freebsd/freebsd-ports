--- build/libreoffice/desktop/scripts/unopkg.sh.orig	2010-12-12 21:12:42.000000000 +0100
+++ build/libreoffice/desktop/scripts/unopkg.sh	2011-02-08 07:56:57.385242809 +0100
@@ -45,7 +45,7 @@
 
 # this is a temporary hack until we can live with the default search paths
 case "`uname -s`" in
-OpenBSD)
+OpenBSD|FreeBSD)
     sd_prog1="$sd_prog/../basis-link/program"
     sd_prog2="$sd_prog/../basis-link/ure-link/lib"
     LD_LIBRARY_PATH=$sd_prog1:$sd_prog2${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
