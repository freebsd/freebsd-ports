--- aclocal.m4.orig	Fri Aug  8 05:02:36 2003
+++ aclocal.m4	Fri Aug  8 05:03:04 2003
@@ -385,7 +385,7 @@
 LN_S="$LN_S" NM="$NM" RANLIB="$RANLIB" \
 DLLTOOL="$DLLTOOL" AS="$AS" OBJDUMP="$OBJDUMP" \
 ${CONFIG_SHELL-/bin/sh} $ac_aux_dir/ltconfig --no-reexec \
-$libtool_flags --no-verify $ac_aux_dir/ltmain.sh $host \
+$libtool_flags --no-verify $host \
 || AC_MSG_ERROR([libtool configure failed])
 
 # Reload cache, that may have been modified by ltconfig
