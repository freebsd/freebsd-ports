--- aclocal.m4.orig	Sat Mar 23 15:44:56 2002
+++ aclocal.m4	Sat Mar 23 15:44:17 2002
@@ -572,7 +572,8 @@
       oz_tmp_ok=no
       AC_MSG_WARN([$YACC is not GNU bison])
     else
-      OZ_PROG_VERSION_CHECK(oz_tmp_ok,$YACC,OZ_VERSION_BISON)
+      # OZ_PROG_VERSION_CHECK(oz_tmp_ok,$YACC,OZ_VERSION_BISON)
+      oz_tmp_ok=yes
     fi
     if test "$oz_tmp_ok" = yes; then
       oz_cv_YACC=$YACC
