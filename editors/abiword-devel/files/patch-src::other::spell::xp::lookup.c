
$FreeBSD$

--- src/other/spell/xp/lookup.c	2001/08/08 13:01:57	1.1
+++ src/other/spell/xp/lookup.c	2001/08/08 13:02:13
@@ -140,6 +140,7 @@
 #include <ctype.h>
 
 #include "ispell.h"
+#include "iconv.h"
 #include "msgs.h"
 
 #if 0
