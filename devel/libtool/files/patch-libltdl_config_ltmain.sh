--- libltdl/config/ltmain.sh.orig	2010-09-22 09:45:43.000000000 -0500
+++ libltdl/config/ltmain.sh	2011-01-18 12:59:46.000000000 -0600
@@ -1376,2 +1376,17 @@
     $opt_debug
+
+    # FreeBSD-specific: where we install compilers with non-standard names
+    tag_compilers_CC="*cc cc* *gcc gcc* clang"
+    tag_compilers_CXX="*c++ c++* *g++ g++* clang++"
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
@@ -1412,3 +1427,18 @@
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
@@ -3516,2 +3546,5 @@
 	;;
+      *-*-freebsd*)
+	# FreeBSD doesn't need this...
+	;;
       *)
@@ -5585,2 +5618,3 @@
 	esac
+	deplibs="$deplibs $arg"
 	continue
@@ -6155,9 +6189,26 @@
 	    func_append compiler_flags " $deplib"
-	    if test "$linkmode" = lib ; then
-		case "$new_inherited_linker_flags " in
-		    *" $deplib "*) ;;
-		    * ) func_append new_inherited_linker_flags " $deplib" ;;
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
