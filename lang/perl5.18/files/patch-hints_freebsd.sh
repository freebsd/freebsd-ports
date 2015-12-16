--- hints/freebsd.sh.orig	2014-01-31 21:55:51 UTC
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
 
@@ -126,7 +132,7 @@
         else
             libpth="/usr/lib /usr/local/lib"
             glibpth="/usr/lib /usr/local/lib"
-            ldflags="-Wl,-E "
+            ldflags="%%PTHREAD_LIBS%% -Wl,-E "
             lddlflags="-shared "
         fi
         cccdlflags='-DPIC -fPIC'
@@ -134,7 +140,7 @@
 *)
        libpth="/usr/lib /usr/local/lib"
        glibpth="/usr/lib /usr/local/lib"
-       ldflags="-Wl,-E "
+       ldflags="%%PTHREAD_LIBS%% -Wl,-E "
         lddlflags="-shared "
         cccdlflags='-DPIC -fPIC'
        ;;
@@ -191,7 +197,9 @@
 
 # This script UU/usethreads.cbu will get 'called-back' by Configure 
 # after it has prompted the user for whether to use threads.
-cat > UU/usethreads.cbu <<'EOCBU'
+## not quite - modern FreeBSD perl port is supposed to take care of that
+## we just add extra libraries and cflags nowadays
+cat > /dev/null <<'EOCBU'
 case "$usethreads" in
 $define|true|[yY]*)
         lc_r=`/sbin/ldconfig -r|grep ':-lc_r'|awk '{print $NF}'|sed -n '$p'`
