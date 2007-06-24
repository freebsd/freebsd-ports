--- src/common.h	Sat Apr  9 20:06:20 2005
+++ src/common.h	Sun Jun 24 06:03:13 2007
@@ -3,3 +3,5 @@
 #include <libintl.h>
 
 #define _(String) gettext (String)
+
+#include "url2filename.cpp"
