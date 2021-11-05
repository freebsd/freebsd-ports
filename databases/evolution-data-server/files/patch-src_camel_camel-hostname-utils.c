--- src/camel/camel-hostname-utils.c.orig	2021-11-05 17:23:49 UTC
+++ src/camel/camel-hostname-utils.c
@@ -24,6 +24,7 @@
 
 #include <unicode/uchar.h>
 #include <unicode/uscript.h>
+#include <unicode/ustring.h>
 
 #include "camel-string-utils.h"
 #include "camel-hostname-utils.h"
