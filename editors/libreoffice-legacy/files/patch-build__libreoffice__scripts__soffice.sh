--- build/libreoffice/desktop/scripts/soffice.sh.orig	2010-12-12 21:12:42.000000000 +0100
+++ build/libreoffice/desktop/scripts/soffice.sh	2011-01-30 09:50:00.890272369 +0100
@@ -64,7 +64,7 @@
 
 # this is a temporary hack until we can live with the default search paths
 case "`uname -s`" in
-OpenBSD)
+OpenBSD|FreeBSD)
     sd_prog1="$sd_prog/../basis-link/program"
     sd_prog2="$sd_prog/../basis-link/ure-link/lib"
     LD_LIBRARY_PATH=$sd_prog1:$sd_prog2${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
