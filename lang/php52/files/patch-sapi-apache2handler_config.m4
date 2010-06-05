
--- sapi/apache2handler/config.m4.old   2010-03-18 14:52:27.000000000 +0000
+++ sapi/apache2handler/config.m4       2010-03-18 14:52:56.000000000 +0000
@@ -117,7 +117,7 @@
     ;;
   esac

-  if test "$APXS_MPM" != "prefork"; then
+  if test "$APXS_MPM" != "itk" -a "$APXS_MPM" != "prefork"; then
     PHP_BUILD_THREAD_SAFE
   fi
   AC_MSG_RESULT(yes)
~           


