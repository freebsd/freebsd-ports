--- libgtop-sysdeps.m4.orig	2008-04-21 14:58:38.000000000 -0400
+++ libgtop-sysdeps.m4	2008-12-06 16:16:00.000000000 -0500
@@ -158,6 +160,9 @@ AC_DEFUN([GNOME_LIBGTOP_SYSDEPS],[
 		if test -n "${osreldate}" && test ${osreldate} -ge 600000 ; then
 		    EXTRA_SYSDEPS_LIBS="-lgeom -ldevstat"
 		fi
+		AC_CHECK_LIB(util, kinfo_getfile,
+			[EXTRA_SYSDEPS_LIBS="${EXTRA_SYSDEPS_LIBS} -lutil"
+			 AC_DEFINE(HAVE_KINFO_GETFILE, 1, [Define if you have the kinfo_getfile function])], [:])
 		;;
           esac
 
