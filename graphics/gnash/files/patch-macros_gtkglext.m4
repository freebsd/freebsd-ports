--- macros/gtkglext.m4.orig	Sat Apr 22 11:45:05 2006
+++ macros/gtkglext.m4	Sat Apr 22 11:38:54 2006
@@ -132,7 +132,7 @@
           for i in $libslist; do
 	    if test -f $i/libgtkglext-x11-${version}.a -o -f $i/libgtkglext-x11-${version}.so; then
 	      if test x"$i" != x"/usr/lib"; then
-	        ac_cv_path_glext_lib="$i"
+	        ac_cv_path_glext_lib="-L$i -lgtkglext-x11-${version} -lgdkglext-x11-${version}"
 	        break
               fi
 	    else
