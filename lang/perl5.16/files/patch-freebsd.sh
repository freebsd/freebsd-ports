--- hints/freebsd.sh.orig	Wed Mar 24 22:47:33 2004
+++ hints/freebsd.sh	Sun Jan 30 23:39:33 2005
@@ -88,6 +88,8 @@ case "$osvers" in
 	esac
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
 	libswanted=`echo $libswanted | sed 's/ bind / /'`
+	libswanted=`echo $libswanted | sed 's/ dl / /'`
+	libswanted=`echo $libswanted | sed 's/ c / /'`
 	# iconv gone in Perl 5.8.1, but if someone compiles 5.8.0 or earlier.
 	libswanted=`echo $libswanted | sed 's/ iconv / /'`
 	d_setregid='define'
@@ -102,6 +103,10 @@ case "$osvers" in
 	        ;;
 	esac
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
+	libswanted=`echo $libswanted | sed 's/ bind / /'`
+	libswanted=`echo $libswanted | sed 's/ dl / /'`
+	libswanted=`echo $libswanted | sed 's/ iconv / /'`
+	libswanted=`echo $libswanted | sed 's/ c / /'`
 	;;
 esac
 
@@ -119,7 +123,7 @@ case "$osvers" in
         if [ x$objformat = xelf ]; then
             libpth="/usr/lib /usr/local/lib"
             glibpth="/usr/lib /usr/local/lib"
-            ldflags="-Wl,-E "
+            ldflags="%%PTHREAD_LIBS%% -Wl,-E"
             lddlflags="-shared "
         else
             if [ -e /usr/lib/aout ]; then
@@ -136,7 +140,7 @@ case "$osvers" in
 0*|1*|2*|3*) ;;
 
 *)
-	ccflags="${ccflags} -DHAS_FPSETMASK -DHAS_FLOATINGPOINT_H"
+	ccflags="${ccflags} %%PTHREAD_CFLAGS%% -DHAS_FPSETMASK -DHAS_FLOATINGPOINT_H"
 	if /usr/bin/file -L /usr/lib/libc.so | /usr/bin/grep -vq "not stripped" ; then
 	    usenm=false
 	fi
@@ -183,7 +187,9 @@ esac
 
 # This script UU/usethreads.cbu will get 'called-back' by Configure 
 # after it has prompted the user for whether to use threads.
-cat > UU/usethreads.cbu <<'EOCBU'
+## not quite - modern FreeBSD perl port is supposed to take care of that
+## we just add extra libraries and cflags nowadays
+cat > /dev/null <<'EOCBU'
 case "$usethreads" in
 $define|true|[yY]*)
         lc_r=`/sbin/ldconfig -r|grep ':-lc_r'|awk '{print $NF}'|sed -n '$p'`
