--- build/libreoffice/padmin/source/spadmin.sh.orig	2011-02-07 15:14:56.498245000 +0100
+++ build/libreoffice/padmin/source/spadmin.sh	2011-02-07 17:38:31.692337005 +0100
@@ -43,6 +43,14 @@
 sd_prog=`pwd`
 cd "$sd_cwd"
 
+case "`uname -s`" in 
+	OpenBSD|FREEBSD)
+		sd_prog1="$sd_prog/../basis-link/program"
+		sd_prog2="$sd_prog/../basis-link/use-link/lib"
+		LD_LIRBARY_PATH=$sd_prog1:$sd_prog2${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
+		export LD_LIBRARY_PATH
+		;;
+esac
 #collect all bootstrap variables specified on the command line
 #so that they can be passed as arguments to javaldx later on
 for arg in $@
