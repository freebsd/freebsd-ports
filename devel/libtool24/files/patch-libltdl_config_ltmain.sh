--- libltdl/config/ltmain.sh.orig	2009-06-29 12:36:19.000000000 -0500
+++ libltdl/config/ltmain.sh	2009-06-29 12:57:44.000000000 -0500
@@ -1010,6 +1010,21 @@
 func_infer_tag ()
 {
     $opt_debug
+
+    # FreeBSD-specific: where we install compilers with non-standard names
+    tag_compilers_CC="*cc cc* *gcc gcc*"
+    tag_compilers_CXX="*c++ c++* *g++ g++*"
+    base_compiler=`set -- "$@"; echo $1`
+
+    # If $tagname isn't set, then try to infer if the default "CC" tag applies
+    if test -z "$tagname"; then
+      for zp in $tag_compilers_CC; do
+        case $base_compiler in
+	 $zp) tagname="CC"; break;;
+	esac
+      done
+    fi
+
     if test -n "$available_tags" && test -z "$tagname"; then
       CC_quoted=
       for arg in $CC; do
@@ -1042,7 +1057,22 @@
 	      break
 	      ;;
 	    esac
-	  fi
+
+	    # FreeBSD-specific: try compilers based on inferred tag
+	    if test -z "$tagname"; then
+	      eval "tag_compilers=\$tag_compilers_${z}"
+	      if test -n "$tag_compilers"; then
+		for zp in $tag_compilers; do
+		  case $base_compiler in   
+		    $zp) tagname=$z; break;;
+		  esac
+		done
+		if test -n "$tagname"; then
+		  break
+		fi
+	      fi
+            fi
+          fi
 	done
 	# If $tagname still isn't set, then no tagged configuration
 	# was found and let the user know that the "--tag" command
@@ -2528,6 +2558,9 @@
 	  ;;
 	esac
 	;;
+      *-*-freebsd*)
+	# FreeBSD doesn't need this...
+	;;
       *)
 	func_fatal_error "unknown suffix for \`$my_dlsyms'"
 	;;
@@ -4584,6 +4617,7 @@
 	    *" $arg "*) ;;
 	    * ) new_inherited_linker_flags="$new_inherited_linker_flags $arg" ;;
 	esac
+	deplibs="$deplibs $arg"
 	continue
 	;;
 
@@ -5073,13 +5107,30 @@
 	    finalize_deplibs="$deplib $finalize_deplibs"
 	  else
 	    compiler_flags="$compiler_flags $deplib"
-	    if test "$linkmode" = lib ; then
-		case "$new_inherited_linker_flags " in
-		    *" $deplib "*) ;;
-		    * ) new_inherited_linker_flags="$new_inherited_linker_flags $deplib" ;;
-		esac
-	    fi
 	  fi
+
+	  case $linkmode in
+	  lib)
+	    deplibs="$deplib $deplibs"
+	    test "$pass" = conv && continue
+	    newdependency_libs="$deplib $newdependency_libs"
+	    ;;
+	  prog)
+	    if test "$pass" = conv; then
+	      deplibs="$deplib $deplibs"
+	      continue
+	    fi
+	    if test "$pass" = scan; then
+	      deplibs="$deplib $deplibs"
+	    else
+	      compile_deplibs="$deplib $compile_deplibs"
+	      finalize_deplibs="$deplib $finalize_deplibs"
+	    fi
+	    ;;
+	  *)
+	    ;;
+	  esac # linkmode
+
 	  continue
 	  ;;
 	-l*)
