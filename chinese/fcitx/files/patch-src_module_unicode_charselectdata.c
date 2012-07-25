--- src/module/unicode/charselectdata.c~	2012-07-17 15:21:04.000000000 -0500
+++ src/module/unicode/charselectdata.c	2012-07-18 00:20:19.447890414 -0500
@@ -4,7 +4,7 @@
  * original file is licensed under GPLv2+
  */
 
-#include <endian.h>
+#include <sys/endian.h>
 #include <ctype.h>
 #include <libintl.h>
 #include <fcitx-utils/uthash.h>
