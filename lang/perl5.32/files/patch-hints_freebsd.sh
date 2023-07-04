Remove libs that are not here on FreeBSD.

--- hints/freebsd.sh.orig	2020-12-18 09:58:48 UTC
+++ hints/freebsd.sh
@@ -88,8 +88,6 @@ case "$osvers" in
 	esac
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
 	libswanted=`echo $libswanted | sed 's/ bind / /'`
-	# iconv gone in Perl 5.8.1, but if someone compiles 5.8.0 or earlier.
-	libswanted=`echo $libswanted | sed 's/ iconv / /'`
 	d_setregid='define'
 	d_setreuid='define'
 	d_setegid='define'
@@ -102,8 +100,13 @@ case "$osvers" in
 	        ;;
 	esac
 	libswanted=`echo $libswanted | sed 's/ malloc / /'`
+	libswanted=`echo $libswanted | sed 's/ bind / /'`
 	;;
 esac
+libswanted=`echo $libswanted | sed 's/ c / /'`
+# Use -pthread so the compiler adds -lpthread at the right place on the
+# linker command line so its init functions run early.
+libswanted=`echo $libswanted | sed 's/ pthread / /'`
 
 case "$osvers" in
 10.*)
@@ -269,19 +272,6 @@ EOM
 
 	esac
 
-        case "$osvers" in
-        [1-4]*)
-	    set `echo X "$libswanted "| sed -e 's/ c / c_r /'`
-	    shift
-	    libswanted="$*"
-	    ;;
-        *)
-	    set `echo X "$libswanted "| sed -e 's/ c //'`
-	    shift
-	    libswanted="$*"
-	    ;;
-	esac
-	    
 	# Configure will probably pick the wrong libc to use for nm scan.
 	# The safest quick-fix is just to not use nm at all...
 	usenm=false
