--- sapi/apache2filter/config.m4.orig	2010-07-26 13:06:55.000000000 +0200
+++ sapi/apache2filter/config.m4	2010-07-26 13:07:19.000000000 +0200
@@ -118,7 +118,7 @@
     ;;
   esac
 
-  if test "$APXS_MPM" != "prefork" && test "$APXS_MPM" != "peruser"; then
+  if test "$APXS_MPM" != "prefork" && test "$APXS_MPM" != "peruser" && test "$APXS_MPM" != "itk"; then
     PHP_BUILD_THREAD_SAFE
   fi
   AC_MSG_RESULT(yes)
