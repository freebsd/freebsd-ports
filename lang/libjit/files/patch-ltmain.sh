--- ltmain.sh.orig	Wed May 12 23:24:02 2004
+++ ltmain.sh	Fri May 14 14:47:58 2004
@@ -1865,7 +1865,7 @@
 	  if test $? -eq 0 ; then
 	    ldd_output=`ldd conftest`
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr X$i : 'X-l\(.*\)'`"
 	      # If $name is empty we are operating on a -L argument.
 	      if test "$name" != "" ; then
 		libname=`eval \\$echo \"$libname_spec\"`
@@ -1890,7 +1890,7 @@
 	    # Error occured in the first compile.  Let's try to salvage the situation:
 	    # Compile a seperate program for each library.
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr X$i : 'X-l\(.*\)'`"
 	     # If $name is empty we are operating on a -L argument.
 	      if test "$name" != "" ; then
 		$rm conftest
@@ -1930,7 +1930,7 @@
 	  set dummy $deplibs_check_method
 	  file_magic_regex="`expr \"$deplibs_check_method\" : \"$2 \(.*\)\"`"
 	  for a_deplib in $deplibs; do
-	    name="`expr $a_deplib : '-l\(.*\)'`"
+	    name="`expr X$a_deplib : 'X-l\(.*\)'`"
 	    # If $name is empty we are operating on a -L argument.
 	    if test "$name" != "" ; then
 	      libname=`eval \\$echo \"$libname_spec\"`
@@ -3360,11 +3360,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false ; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
-
+	fi
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
 	;;
