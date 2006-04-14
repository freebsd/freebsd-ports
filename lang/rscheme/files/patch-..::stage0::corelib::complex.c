
$FreeBSD$

--- ../stage0/corelib/complex.c.orig	Fri Apr 14 18:22:39 2006
+++ ../stage0/corelib/complex.c	Fri Apr 14 18:22:51 2006
@@ -12,6 +12,7 @@
 #define _C_COMPLEX
 #include "corelib_p.h"
 #include <rscheme/vinsns.h>
+#include <math.h>
 extern struct module_descr module_corelib;
 extern struct part_descr corelib_part_complex;
 static char sccsid[] = "@(#)corelib modules/corelib/complex.scm [191848459] (RS v0.7.3.3, 2005-06-13)";
