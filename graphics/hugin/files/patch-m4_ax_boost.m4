--- m4/ax_boost.m4.orig	Tue Feb 21 01:45:30 2006
+++ m4/ax_boost.m4	Mon Jan 22 17:52:39 2007
@@ -97,7 +97,7 @@
         dnl this location ist chosen if boost libraries are installed with the --layout=system option
         dnl or if you install boost with RPM
         if test "$ac_boost_path" != ""; then
-                BOOST_LDFLAGS="-L$ac_boost_path/lib"
+                BOOST_LDFLAGS="-L$ac_boost_path/lib $PTHREAD_LIBS"
                 BOOST_CPPFLAGS="-I$ac_boost_path/include"
         else
                 for ac_boost_path_tmp in /usr /usr/local /opt ; do
