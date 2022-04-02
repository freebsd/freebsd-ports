Remove libs that are not here on FreeBSD.

--- hints/freebsd.sh.orig	2020-12-18 09:58:48 UTC
+++ hints/freebsd.sh
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
 
@@ -124,24 +130,24 @@ case "$osvers" in
 	;;
 
 3*|4*|5*|6*)
-        objformat=`/usr/bin/objformat`
+        objformat=`$sysroot/usr/bin/objformat`
         if [ x$objformat = xaout ]; then
-            if [ -e /usr/lib/aout ]; then
-                libpth="/usr/lib/aout /usr/local/lib /usr/lib"
-                glibpth="/usr/lib/aout /usr/local/lib /usr/lib"
+            if [ -e $sysroot/usr/lib/aout ]; then
+                libpth="$sysroot/usr/lib/aout $sysroot/usr/local/lib $sysroot/usr/lib"
+                glibpth="$sysroot/usr/lib/aout $sysroot/usr/local/lib $sysroot/usr/lib"
             fi
             lddlflags='-Bshareable'
         else
-            libpth="/usr/lib /usr/local/lib"
-            glibpth="/usr/lib /usr/local/lib"
+            libpth="$sysroot/usr/lib $sysroot/usr/local/lib"
+            glibpth="$sysroot/usr/lib $sysroot/usr/local/lib"
             ldflags="-Wl,-E "
             lddlflags="-shared "
         fi
         cccdlflags='-DPIC -fPIC'
         ;;
 *)
-       libpth="/usr/lib /usr/local/lib"
-       glibpth="/usr/lib /usr/local/lib"
+       libpth="$sysroot/usr/lib $sysroot/usr/local/lib"
+       glibpth="$sysroot/usr/lib $sysroot/usr/local/lib"
        ldflags="-Wl,-E "
         lddlflags="-shared "
         cccdlflags='-DPIC -fPIC'
@@ -153,7 +159,7 @@ case "$osvers" in
 
 *)
 	ccflags="${ccflags} -DHAS_FPSETMASK -DHAS_FLOATINGPOINT_H"
-	if /usr/bin/file -L /usr/lib/libc.so | /usr/bin/grep -vq "not stripped" ; then
+	if /usr/bin/file -L $sysroot/usr/lib/libc.so | /usr/bin/grep -vq "not stripped" ; then
 	    usenm=false
 	fi
         ;;
