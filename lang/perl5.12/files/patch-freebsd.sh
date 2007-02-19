--- hints/freebsd.sh.orig	Wed Mar 24 22:47:33 2004
+++ hints/freebsd.sh	Mon Feb 19 20:53:50 2007
@@ -88,6 +88,8 @@ case "$osvers" in
 	esac
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
 	libswanted=`echo $libswanted | sed 's/ bind / /'`
+	libswanted=`echo $libswanted | sed 's/ dl / /'`
+	libswanted=`echo $libswanted | sed 's/ c / /'`
 	# iconv gone in Perl 5.8.1, but if someone compiles 5.8.0 or earlier.
 	libswanted=`echo $libswanted | sed 's/ iconv / /'`
 	d_setregid='define'
@@ -102,6 +104,10 @@ case "$osvers" in
 	        ;;
 	esac
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
+	libswanted=`echo $libswanted | sed 's/ bind / /'`
+	libswanted=`echo $libswanted | sed 's/ dl / /'`
+	libswanted=`echo $libswanted | sed 's/ iconv / /'`
+	libswanted=`echo $libswanted | sed 's/ c / /'`
 	;;
 esac
 
@@ -116,17 +122,17 @@ case "$osvers" in
 
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
+            ldflags="%%PTHREAD_LIBS%% -Wl,-E"
+            lddlflags="-shared "
         fi
         cccdlflags='-DPIC -fPIC'
         ;;
@@ -136,7 +142,7 @@ case "$osvers" in
 0*|1*|2*|3*) ;;
 
 *)
-	ccflags="${ccflags} -DHAS_FPSETMASK -DHAS_FLOATINGPOINT_H"
+	ccflags="${ccflags} %%PTHREAD_CFLAGS%% -DHAS_FPSETMASK -DHAS_FLOATINGPOINT_H"
 	if /usr/bin/file -L /usr/lib/libc.so | /usr/bin/grep -vq "not stripped" ; then
 	    usenm=false
 	fi
@@ -183,7 +189,9 @@ esac
 
 # This script UU/usethreads.cbu will get 'called-back' by Configure 
 # after it has prompted the user for whether to use threads.
-cat > UU/usethreads.cbu <<'EOCBU'
+## not quite - modern FreeBSD perl port is supposed to take care of that
+## we just add extra libraries and cflags nowadays
+cat > /dev/null <<'EOCBU'
 case "$usethreads" in
 $define|true|[yY]*)
         lc_r=`/sbin/ldconfig -r|grep ':-lc_r'|awk '{print $NF}'|sed -n '$p'`
