--- config.sh.orig	Wed Feb 23 21:23:18 2005
+++ config.sh	Thu Jul 21 18:18:59 2005
@@ -320,14 +320,16 @@
 		echo "#define CONFOPT_GETTEXT 1" >> config.h
 	else
 		# try now with -lintl
-		TMP_LDFLAGS="-lintl"
+		TMP_LDFLAGS="-L/usr/local/lib -lintl"
+		TMP_CFLAGS="-I/usr/local/include"
 
-		$CC .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
+		$CC $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
 
 		if [ $? = 0 ] ; then
 			echo "OK (libintl needed)"
 			echo "#define CONFOPT_GETTEXT 1" >> config.h
 			echo "$TMP_LDFLAGS" >> config.ldflags
+			echo "$TMP_CFLAGS" >> config.cflags
 		else
 			echo "No"
 			WITHOUT_GETTEXT=1
