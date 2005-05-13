Issutracker : #i48988#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : at configure stage,  ENABLE_PASF is settend to NO.
---config_office/configure.in start
dnl ===================================================================
dnl Test whether wwe want to use portaudio/sndfile
dnl ===================================================================
AC_MSG_CHECKING([whether to use portaudio/sndfile])
ENABLE_PASF=NO
if test -n "$enable_pasf"; then
        ENABLE_PASF=YES
        AC_MSG_RESULT([yes])
else
        AC_MSG_RESULT([no])
fi
AC_SUBST(ENABLE_PASF)
---end

Index: vcl/unx/source/app/makefile.mk
===================================================================
RCS file: /cvs/gsl/vcl/unx/source/app/makefile.mk,v
retrieving revision 1.9.250.3
diff -u -r1.9.250.3 makefile.mk
--- vcl/unx/source/app/makefile.mk	29 Apr 2005 14:25:56 -0000	1.9.250.3
+++ vcl/unx/source/app/makefile.mk	10 May 2005 05:53:27 -0000
@@ -113,7 +113,7 @@
 			$(SLO)$/rptpsound.obj		\
 			$(SLO)$/nassound.obj		
 
-.IF "$(ENABLE_PASF)" != ""
+.IF "$(ENABLE_PASF)" == "YES"
 CFLAGS+=-DUSE_PASF
 .IF "$(SYSTEM_PORTAUDIO)" == "YES"
 CFLAGS+=-DSYSTEM_PORTAUDIO
