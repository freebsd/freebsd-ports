--- ltmain.sh.old	Thu Jun 12 05:09:04 2003
+++ ltmain.sh	Thu Jul 31 19:03:06 2003
@@ -1280,7 +1280,7 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
@@ -1290,8 +1290,16 @@
 	continue
 	;;
 
+      -pthread)
+	compile_command="$compile_command -pthread"
+	finalize_command="$finalize_command -pthread"
+	compiler_flags="$compiler_flags -pthread"
+	continue
+	;;
+
       -module)
 	module=yes
+	build_old_libs=no
 	continue
 	;;
 
@@ -4305,11 +4313,11 @@
 	  $show "(cd $output_objdir && $LTCC -c$no_builtin_flag$pic_flag_for_symtable \"$dlsyms\")"
 	  $run eval '(cd $output_objdir && $LTCC -c$no_builtin_flag$pic_flag_for_symtable "$dlsyms")' || exit $?
 
-	  # Clean up the generated files.
-	  $show "$rm $output_objdir/$dlsyms $nlist ${nlist}S ${nlist}T"
-	  $run $rm "$output_objdir/$dlsyms" "$nlist" "${nlist}S" "${nlist}T"
-
-	  # Transform the symbol file into the correct name.
+	        # Clean up the generated files.
+	        $show "$rm $output_objdir/$dlsyms $nlist ${nlist}S ${nlist}T"
+	        $run $rm "$output_objdir/$dlsyms" "$nlist" "${nlist}S" "${nlist}T"
+               
+	        # Transform the symbol file into the correct name.
 	  compile_command=`$echo "X$compile_command" | $Xsed -e "s%@SYMFILE@%$output_objdir/${outputname}S.${objext}%"`
 	  finalize_command=`$echo "X$finalize_command" | $Xsed -e "s%@SYMFILE@%$output_objdir/${outputname}S.${objext}%"`
 	  ;;
@@ -5428,10 +5436,12 @@
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
