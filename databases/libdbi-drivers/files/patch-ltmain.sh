--- ltmain.sh.orig	Thu Oct 30 11:32:24 2003
+++ ltmain.sh	Thu Oct 30 11:32:37 2003
@@ -3457,11 +3457,13 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false ; then
 	if test "$install_ltlibs" = yes; then
 	  name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	  instname="$dir/$name"i
 	  $show "$install_prog $instname $destdir/$name"
 	  $run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 	fi
 
 	# Maybe install the static library, too.
