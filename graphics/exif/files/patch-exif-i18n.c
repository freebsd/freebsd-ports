--- exif/exif-i18n.c	2003/09/30 22:53:37	1.2
+++ exif/exif-i18n.c	2004/08/27 16:28:18	1.3
@@ -1,7 +1,10 @@
 #include <config.h>
 #include "exif-i18n.h"
 
-#include <iconv.h>
+#ifdef HAVE_ICONV
+#  include <iconv.h>
+#endif
+
 #include <string.h>
 #include <sys/types.h>
 
@@ -11,6 +14,7 @@
 const char *
 exif_i18n_convert_utf8_to_lat1 (const char *in)
 {
+#ifdef HAVE_ICONV
 	static iconv_t tr = 0;
 	size_t t = (in ? strlen (in) : 0);
 	static char buf[2048];
@@ -23,4 +27,7 @@
 	if (!tr) tr = iconv_open ("ISO-8859-1", "UTF-8");
 	iconv (tr, (char **) &in, &t, (char **) &out, &buf_size);
 	return buf;
+#else
+	return in;
+#endif
 }
