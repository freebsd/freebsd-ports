--- acinclude.m4.orig	2010-01-01 08:21:00 UTC
+++ acinclude.m4
@@ -422,7 +422,7 @@ if test "$alsa_prefix" != "" ; then
 fi
 
 dnl add the alsa library
-ALSA_LIBS="$ALSA_LIBS -lasound -lm -ldl -lpthread"
+ALSA_LIBS="$ALSA_LIBS -lasound -lm -lpthread"
 LIBS="$ALSA_LIBS $LIBS"
 AC_MSG_RESULT($ALSA_LIBS)
 
@@ -541,7 +541,7 @@ AC_ARG_ENABLE(aotest, [  --disable-aotes
 
   # see where dl* and friends live
   AC_CHECK_FUNCS(dlopen, [AO_DL_LIBS=""], [
-    AC_CHECK_LIB(dl, dlopen, [AO_DL_LIBS="-ldl"], [
+    AC_CHECK_LIB(dl, dlopen, [
       AC_MSG_WARN([could not find dlopen() needed by libao sound drivers
       your system may not be supported.])
     ])
