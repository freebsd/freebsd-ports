--- desktop/scripts/soffice.sh.orig	2015-09-17 13:33:12 UTC
+++ desktop/scripts/soffice.sh
@@ -128,7 +128,7 @@ if echo "$checks" | grep -q "cc" ; then
 fi
 
 case "`uname -s`" in
-NetBSD|OpenBSD|FreeBSD|DragonFly)
+NetBSD|OpenBSD|DragonFly)
 # this is a temporary hack until we can live with the default search paths
     LD_LIBRARY_PATH="$sd_prog${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
     JAVA_HOME=$(javaPathHelper -h libreoffice-java 2> /dev/null)
