# Workround for: Bug #78614 	Does not compile with DTRACE anymore
# See: https://bugs.php.net/bug.php?id=78614
--- build/php.m4.orig	2019-10-03 20:45:52 UTC
+++ build/php.m4
@@ -2326,7 +2326,7 @@ dnl header-file.
 dnl Add providerdesc.o or .lo into global objects when needed.
   case $host_alias in
   *freebsd*)
-    PHP_GLOBAL_OBJS="[$]PHP_GLOBAL_OBJS [$]ac_bdir[$]ac_provsrc.o"
+    PHP_GLOBAL_OBJS="[$]PHP_GLOBAL_OBJS [$]ac_bdir[$]ac_provsrc.lo"
     PHP_LDFLAGS="$PHP_LDFLAGS -lelf"
     ;;
   *solaris*)
@@ -2374,7 +2374,7 @@ $ac_bdir[$]ac_hdrobj: $abs_srcdir/$ac_pr
 EOF
 
   case $host_alias in
-  *solaris*|*linux*)
+  *solaris*|*linux*|*freebsd*)
     dtrace_prov_name="`echo $ac_provsrc | $SED -e 's#\(.*\)\/##'`.o"
     dtrace_lib_dir="`echo $ac_bdir[$]ac_provsrc | $SED -e 's#\(.*\)/[^/]*#\1#'`/.libs"
     dtrace_d_obj="`echo $ac_bdir[$]ac_provsrc | $SED -e 's#\(.*\)/\([^/]*\)#\1/.libs/\2#'`.o"
