
$FreeBSD$

--- intl/gettextP.h	2001/07/27 15:27:33	1.1
+++ intl/gettextP.h	2001/07/27 15:27:49
@@ -25,7 +25,7 @@
 # include "../iconv/gconv_int.h"
 #else
 # if HAVE_ICONV
-#  include <iconv.h>
+#  include <giconv.h>
 # endif
 #endif
 
