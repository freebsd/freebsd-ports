
$FreeBSD$

--- src/wp/impexp/xp/ie_imp_RTF.cpp	2001/08/08 12:59:57	1.1
+++ src/wp/impexp/xp/ie_imp_RTF.cpp	2001/08/08 13:01:08
@@ -27,6 +27,7 @@
 #include <stddef.h>
 #include <ctype.h>
 #include <math.h>
+#include "iconv.h"
 #include "ut_types.h"
 #include "ut_assert.h"
 #include "ut_debugmsg.h"
