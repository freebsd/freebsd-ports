--- aclocal.m4.orig	Fri Jun 29 04:55:26 2001
+++ aclocal.m4	Tue Nov  4 22:05:22 2003
@@ -18,6 +18,7 @@
 AC_DEFUN(AC_HAS_KPSE_FORMATS,
 	[AC_MSG_CHECKING([whether you have kpathsea headers and they whether they know about the required file formats])
 	 AC_TRY_COMPILE([#include <stdio.h>
+#include <kpathsea/c-auto.h>
 #include <kpathsea/tex-file.h>],
 	     	        [kpse_tex_ps_header_format;
 			 kpse_type1_format;kpse_vf_format],
@@ -36,6 +37,7 @@
 AC_DEFUN(AC_HAS_OMEGA_FORMATS,
 	[AC_MSG_CHECKING([whether your kpathsea supports Omega OFM file formats])
 	 AC_TRY_COMPILE([#include <stdio.h>
+#include <kpathsea/c-auto.h>
 #include <kpathsea/tex-file.h>],
 	     	        [kpse_ofm_format],
 			[AC_MSG_RESULT(yes); AC_DEFINE(HAVE_OMEGA_FORMATS)],
@@ -43,6 +45,7 @@
 AC_DEFUN(AC_HAS_TTF_FORMATS,
 	[AC_MSG_CHECKING([whether your kpathsea supports Truetype (TTF) file formats])
 	 AC_TRY_COMPILE([#include <stdio.h>
+#include <kpathsea/c-auto.h>
 #include <kpathsea/tex-file.h>],
 	     	        [kpse_truetype_format],
                         [AC_MSG_RESULT(yes)
