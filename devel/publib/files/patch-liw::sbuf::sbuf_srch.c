--- liw/sbuf/sbuf_srch.c.orig	Thu Apr 25 13:48:36 2002
+++ liw/sbuf/sbuf_srch.c	Thu Apr 25 13:48:54 2002
@@ -7,6 +7,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
+#include <sys/types.h>
 #include <regex.h>
 #include "publib/sbuf.h"
 
