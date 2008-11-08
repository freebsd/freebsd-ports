--- ltmain.sh.orig	2008-11-09 00:28:51.000000000 +0800
+++ ltmain.sh	2008-11-09 00:32:32.000000000 +0800
@@ -3420,7 +3420,7 @@
 	  if test "$?" -eq 0 ; then
 	    ldd_output=`ldd conftest`
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr X$i : 'X-l\(.*\)'`"
 	      # If $name is empty we are operating on a -L argument.
               if test "$name" != "" && test "$name" -ne "0"; then
 		if test "X$allow_libtool_libs_with_static_runtimes" = "Xyes" ; then
@@ -3457,7 +3457,7 @@
 	    # Error occurred in the first compile.  Let's try to salvage
 	    # the situation: Compile a separate program for each library.
 	    for i in $deplibs; do
-	      name="`expr $i : '-l\(.*\)'`"
+	      name="`expr X$i : 'X-l\(.*\)'`"
 	      # If $name is empty we are operating on a -L argument.
               if test "$name" != "" && test "$name" != "0"; then
 		$rm conftest
@@ -3509,7 +3509,7 @@
 	  set dummy $deplibs_check_method
 	  file_magic_regex=`expr "$deplibs_check_method" : "$2 \(.*\)"`
 	  for a_deplib in $deplibs; do
-	    name="`expr $a_deplib : '-l\(.*\)'`"
+	    name="`expr X$a_deplib : 'X-l\(.*\)'`"
 	    # If $name is empty we are operating on a -L argument.
             if test "$name" != "" && test  "$name" != "0"; then
 	      if test "X$allow_libtool_libs_with_static_runtimes" = "Xyes" ; then
@@ -3578,7 +3578,7 @@
 	  set dummy $deplibs_check_method
 	  match_pattern_regex=`expr "$deplibs_check_method" : "$2 \(.*\)"`
 	  for a_deplib in $deplibs; do
-	    name="`expr $a_deplib : '-l\(.*\)'`"
+	    name="`expr X$a_deplib : 'X-l\(.*\)'`"
 	    # If $name is empty we are operating on a -L argument.
 	    if test -n "$name" && test "$name" != "0"; then
 	      if test "X$allow_libtool_libs_with_static_runtimes" = "Xyes" ; then
