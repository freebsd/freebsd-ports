--- hints/freebsd.sh.orig	Mon Jan 31 22:08:10 2005
+++ hints/freebsd.sh	Mon Jan 31 22:10:17 2005
@@ -101,7 +101,14 @@ case "$osvers" in
 	    "") usemymalloc='n'
 	        ;;
 	esac
+	d_setregid='define'
+	d_setreuid='define'
+	d_setegid='define'
+	d_seteuid='define'
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
+	libswanted=`echo $libswanted | sed 's/ bind / /'`
+	libswanted=`echo $libswanted | sed 's/ iconv / /'`
+	libswanted=`echo $libswanted | sed 's/ dl / /'`
 	;;
 esac
 
