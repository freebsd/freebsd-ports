--- hints/freebsd.sh
+++ hints/freebsd.sh
@@ -88,6 +88,8 @@
 	esac
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
 	libswanted=`echo $libswanted | sed 's/ bind / /'`
+	libswanted=`echo $libswanted | sed 's/ dl / /'`
+	libswanted=`echo $libswanted | sed 's/ c / /'`
 	# iconv gone in Perl 5.8.1, but if someone compiles 5.8.0 or earlier.
 	libswanted=`echo $libswanted | sed 's/ iconv / /'`
 	d_setregid='define'
@@ -102,6 +104,10 @@
 	        ;;
 	esac
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
+	libswanted=`echo $libswanted | sed 's/ bind / /'`
+	libswanted=`echo $libswanted | sed 's/ dl / /'`
+	libswanted=`echo $libswanted | sed 's/ iconv / /'`
+	libswanted=`echo $libswanted | sed 's/ c / /'`
 	;;
 esac
 
@@ -125,7 +131,7 @@
         else
             libpth="/usr/lib /usr/local/lib"
             glibpth="/usr/lib /usr/local/lib"
-            ldflags="-Wl,-E "
+            ldflags="%%PTHREAD_LIBS%% -Wl,-E "
             lddlflags="-shared "
         fi
         cccdlflags='-DPIC -fPIC'
@@ -133,7 +139,7 @@
 *)
        libpth="/usr/lib /usr/local/lib"
        glibpth="/usr/lib /usr/local/lib"
-       ldflags="-Wl,-E "
+       ldflags="%%PTHREAD_LIBS%% -Wl,-E "
         lddlflags="-shared "
         cccdlflags='-DPIC -fPIC'
        ;;
@@ -143,7 +149,7 @@
 0*|1*|2*|3*) ;;
 
 *)
-	ccflags="${ccflags} -DHAS_FPSETMASK -DHAS_FLOATINGPOINT_H"
+	ccflags="${ccflags} %%PTHREAD_CFLAGS%% -DHAS_FPSETMASK -DHAS_FLOATINGPOINT_H"
 	if /usr/bin/file -L /usr/lib/libc.so | /usr/bin/grep -vq "not stripped" ; then
 	    usenm=false
 	fi
@@ -190,7 +196,9 @@
 
 # This script UU/usethreads.cbu will get 'called-back' by Configure 
 # after it has prompted the user for whether to use threads.
-cat > UU/usethreads.cbu <<'EOCBU'
+## not quite - modern FreeBSD perl port is supposed to take care of that
+## we just add extra libraries and cflags nowadays
+cat > /dev/null <<'EOCBU'
 case "$usethreads" in
 $define|true|[yY]*)
         lc_r=`/sbin/ldconfig -r|grep ':-lc_r'|awk '{print $NF}'|sed -n '$p'`
