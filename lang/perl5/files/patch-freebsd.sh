--- hints/freebsd.sh.orig	Wed Oct 15 22:26:16 2003
+++ hints/freebsd.sh	Mon Feb 19 21:16:03 2007
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
 
@@ -116,17 +123,17 @@ case "$osvers" in
 
 *)
         objformat=`/usr/bin/objformat`
-        if [ x$objformat = xelf ]; then
-            libpth="/usr/lib /usr/local/lib"
-            glibpth="/usr/lib /usr/local/lib"
-            ldflags="-Wl,-E "
-            lddlflags="-shared "
-        else
+        if [ x$objformat = xaout ]; then
             if [ -e /usr/lib/aout ]; then
                 libpth="/usr/lib/aout /usr/local/lib /usr/lib"
                 glibpth="/usr/lib/aout /usr/local/lib /usr/lib"
             fi
             lddlflags='-Bshareable'
+        else
+            libpth="/usr/lib /usr/local/lib"
+            glibpth="/usr/lib /usr/local/lib"
+            ldflags="-Wl,-E "
+            lddlflags="-shared "
         fi
         cccdlflags='-DPIC -fPIC'
         ;;
