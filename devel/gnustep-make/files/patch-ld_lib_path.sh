--- ld_lib_path.sh~	Mon Feb  4 05:43:38 2002
+++ ld_lib_path.sh	Wed Mar 20 16:00:00 2002
@@ -50,6 +50,8 @@
     additional="${additional}${dir}:"
   done
   unset dir
+else
+  additional=
 fi
 lib_paths="${additional}${lib_paths}"
 unset additional
