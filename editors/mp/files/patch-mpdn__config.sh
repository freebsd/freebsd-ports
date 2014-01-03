--- mpdm/config.sh.orig	2009-11-05 17:18:27.000000000 +0900
+++ mpdm/config.sh	2011-03-19 08:40:21.000000000 +0900
@@ -309,13 +309,15 @@
 		echo "#define CONFOPT_GETTEXT 1" >> config.h
 	else
 		# try now with -lintl
-		TMP_LDFLAGS="-lintl"
+		TMP_CFLAGS="-I%%LOCALBASE%%/include"
+		TMP_LDFLAGS="-L%%LOCALBASE%%/lib -lintl"
 
-		$CC .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
+		$CC $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
 
 		if [ $? = 0 ] ; then
 			echo "OK (libintl needed)"
 			echo "#define CONFOPT_GETTEXT 1" >> config.h
+			echo "$TMP_CFLAGS" >> config.cflags
 			echo "$TMP_LDFLAGS" >> config.ldflags
 		else
 			echo "No"
@@ -342,13 +344,15 @@
 		echo "#define CONFOPT_ICONV 1" >> config.h
 	else
 		# try now with -liconv
-		TMP_LDFLAGS="-liconv"
+		TMP_CFLAGS="-I%%ICONV_PREFIX%%/include"
+		TMP_LDFLAGS="-L%%ICONV_PREFIX%%/lib %%ICONV_LIB%%"
 
-		$CC .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
+		$CC $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
 
 		if [ $? = 0 ] ; then
 			echo "OK (libiconv needed)"
 			echo "#define CONFOPT_ICONV 1" >> config.h
+			echo "$TMP_CFLAGS" >> config.cflags
 			echo "$TMP_LDFLAGS" >> config.ldflags
 		else
 			echo "No"
