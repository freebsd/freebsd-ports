--- m4/ax_boost.m4.orig	2006-11-30 09:36:48.000000000 +0200
+++ m4/ax_boost.m4	2007-12-12 18:39:43.000000000 +0200
@@ -97,7 +97,7 @@
         dnl this location ist chosen if boost libraries are installed with the --layout=system option
         dnl or if you install boost with RPM
         if test "$ac_boost_path" != ""; then
-                BOOST_LDFLAGS="-L$ac_boost_path/lib"
+                BOOST_LDFLAGS="-L$ac_boost_path/lib $PTHREAD_LIBS"
                 BOOST_CPPFLAGS="-I$ac_boost_path/include"
         else
                 for ac_boost_path_tmp in /usr /usr/local /opt ; do
@@ -331,7 +331,7 @@
                                                 for BT in "-mt" ""; do
                                                     for BL in "" "-s" ; do
                                                         ax_lib=$BP$BN$BC$BT$BL$BV;
-                                                        AC_CHECK_LIB($ax_lib, main, [BOOST_THREAD_LIB="-l$ax_lib" AC_SUBST(BOOST_THREAD_LIB) link_thread="yes"
+                                                        AC_CHECK_LIB($ax_lib, main, [BOOST_THREAD_LIB="-l$ax_lib $BOOST_LDFLAGS" AC_SUBST(BOOST_THREAD_LIB) link_thread="yes"
  break 5],
                                                         [link_thread="no"])
                                                     done
