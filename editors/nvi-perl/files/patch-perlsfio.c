--- perl_api/perlsfio.c.orig	Thu Apr  3 00:41:06 2003
+++ perl_api/perlsfio.c	Thu Apr  3 00:41:23 2003
@@ -27,11 +27,12 @@ static const char sccsid[] = "@(#)perlsf
 #include <termios.h>
 #include <unistd.h>
 
-#include "../common/common.h"
-
 #include <EXTERN.h>
 #include <perl.h>
 #include <XSUB.h>
+
+#undef ARGS
+#include "../common/common.h"
 
 #include "perl_extern.h"
 
