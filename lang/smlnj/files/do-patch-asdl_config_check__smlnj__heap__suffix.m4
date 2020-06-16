--- asdl/config/check_smlnj_heap_suffix.m4.orig	2019-10-21 18:02:45 UTC
+++ asdl/config/check_smlnj_heap_suffix.m4
@@ -45,6 +45,7 @@ AC_DEFUN([CHECK_SMLNJ_HEAP_SUFFIX], [
     sparc:solaris3*)	SMLNJ_ARCH=sparc;	SMLNJ_OPSYS=solaris;;
     x86_64:linux*)	SMLNJ_ARCH=x86_64;	SMLNJ_OPSYS=linux;;
     x86_64:darwin*)	SMLNJ_ARCH=x86_64;	SMLNJ_OPSYS=darwin;;
+    x86_64:freebsd*)	SMLNJ_ARCH=x86_64;	SMLNJ_OPSYS=freebsd;;
     *) $1 ;;
   esac
   if test z$SMLNJ_ARCH != z -a z$SMLNJ_OPSYS != z ; then
