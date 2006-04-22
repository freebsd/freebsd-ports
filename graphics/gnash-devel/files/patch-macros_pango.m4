--- macros/pango.m4.orig	Sat Apr 22 10:10:07 2006
+++ macros/pango.m4	Sat Apr 22 11:34:01 2006
@@ -56,7 +56,7 @@
     dnl doesn't seem to get a directory that is unversioned.
     if test x"${ac_cv_path_pango_incl}" = x; then
       AC_MSG_CHECKING([for the Pango Version])
-        pathlist="/sw/include /usr/local/include /home/latest/include /opt/include /usr/include /usr/pkg/include .. ../.."
+        pathlist="${prefix}/include /sw/include /usr/local/include /home/latest/include /opt/include /usr/include /usr/pkg/include .. ../.."
 
         topdir=""
         version=""
@@ -82,7 +82,7 @@
         AC_CHECK_HEADERS(pango/pango.h, [ac_cv_path_pango_incl=""],[
           if test x"${ac_cv_path_pango_incl}" = x; then
             AC_MSG_CHECKING([for libpango header])
-            incllist="/sw/include /usr/local/include /home/latest/include /opt/include /usr/include /usr/pkg/include .. ../.."
+            incllist="${prefix}/include /sw/include /usr/local/include /home/latest/include /opt/include /usr/include /usr/pkg/include .. ../.."
 
             for i in $incllist; do
 	      if test -f $i/pango/pango.h; then
@@ -122,7 +122,7 @@
       if test x"${ac_cv_path_pango_incl}" != x; then
         AC_CHECK_LIB(pango-${version}, pango_engine_shape_class_init, [ac_cv_path_pango_lib="-lpango-${version}"],[
           AC_MSG_CHECKING([for libpango library])
-          libslist="/usr/lib64 /usr/lib /sw/lib /usr/local/lib /home/latest/lib /opt/lib /usr/pkg/lib .. ../.."
+          libslist="${prefix}/lib /usr/lib64 /usr/lib /sw/lib /usr/local/lib /home/latest/lib /opt/lib /usr/pkg/lib .. ../.."
           for i in $libslist; do
 	    if test -f $i/libpango-${version}.a -o -f $i/libpango-${version}.so; then
 	      if test x"$i" != x"/usr/lib"; then
