--- perl_api/perl.xs.orig	Thu Apr  3 00:34:52 2003
+++ perl_api/perl.xs	Thu Apr  3 00:35:05 2003
@@ -31,11 +31,12 @@ static const char sccsid[] = "@(#)perl.x
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
 
