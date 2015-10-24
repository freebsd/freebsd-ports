--- desktop/scripts/soffice.sh.orig	2014-02-25 08:22:34 UTC
+++ desktop/scripts/soffice.sh
@@ -90,11 +90,11 @@ if [ -x "$sd_prog/javaldx" ] ; then
     case "`uname -s`" in
     FreeBSD)
 	sd_prog1="$sd_prog"
-	LD_LIBRARY_PATH=$sd_prog1:${LD_LIBRARY_PATH}}
+	LD_LIBRARY_PATH=$sd_prog1${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
 	export LD_LIBRARY_PATH
 	;;
     esac
-    my_path=`"$sd_prog/javaldx" $BOOTSTRAPVARS \
+    my_path=`JAVA_HOME="%%JAVA_HOME%%" "$sd_prog/javaldx" $BOOTSTRAPVARS \
         "-env:INIFILENAME=vnd.sun.star.pathname:$sd_prog/redirectrc"`
     if [ -n "$my_path" ] ; then
         LD_LIBRARY_PATH=$my_path${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
