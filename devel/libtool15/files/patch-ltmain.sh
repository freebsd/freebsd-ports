--- ltmain.sh.orig	Sun Dec 18 14:14:54 2005
+++ ltmain.sh	Mon Feb 20 17:37:04 2006
@@ -228,2 +228,16 @@
 {
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
@@ -268,3 +282,18 @@
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
@@ -1606,2 +1635,3 @@
 	finalize_command="$finalize_command $arg"
+	deplibs="$deplibs $arg"
 	continue
@@ -2103,2 +2133,25 @@
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
@@ -4706,2 +4759,5 @@
           esac
+	  ;;
+	*-*-freebsd*)
+	  # FreeBSD doesn't need this...
 	  ;;
