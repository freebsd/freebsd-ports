
$FreeBSD$

--- ../stage0/corelib/string.c	2001/07/31 07:20:17	1.1
+++ ../stage0/corelib/string.c	2001/07/31 07:21:08
@@ -12,6 +12,7 @@
 #define _C_STRING
 #include "corelib_p.h"
 #include <rscheme/vinsns.h>
+#include <ctype.h>
 extern struct module_descr module_corelib;
 extern struct part_descr corelib_part_string;
 static char sccsid[] = "@(#)corelib modules/corelib/string.scm[71979012] (RS v0.7.3.1, 2000-11-26)";
