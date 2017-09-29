--- src/ght_hash.c.orig	2013-07-11 17:41:23 UTC
+++ src/ght_hash.c
@@ -7,6 +7,7 @@
 ******************************************************************************/
 
 #include "ght_internal.h"
+#include <ctype.h>
 
 #define MAX_HASH_LENGTH 22
 
