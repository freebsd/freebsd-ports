--- ltmain.sh.orig	Tue Jun 25 20:57:40 2002
+++ ltmain.sh	Sat Dec 21 03:49:50 2002
@@ -967,6 +967,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -1063,7 +1064,7 @@
 	  case $host in
 	 *-*-openbsd* | *-*-freebsd*)
 	    # Do not include libc_r directly, use -pthread flag.
-	    continue
+	    #continue
 	    ;;
 	  esac
 	fi
@@ -4273,10 +4274,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
