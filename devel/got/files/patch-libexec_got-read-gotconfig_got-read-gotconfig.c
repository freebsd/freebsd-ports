XXX remove after 0.39
--- libexec/got-read-gotconfig/got-read-gotconfig.c.orig	2020-09-14 16:29:32 UTC
+++ libexec/got-read-gotconfig/got-read-gotconfig.c
@@ -27,6 +27,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sha1.h>
+#include <unistd.h>
 #include <zlib.h>
 
 #include "got_error.h"
