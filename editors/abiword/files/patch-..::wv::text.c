
$FreeBSD$

--- ../wv/text.c.orig	Tue Jun 26 19:04:10 2001
+++ ../wv/text.c	Wed Aug  8 14:47:29 2001
@@ -5,7 +5,7 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-#include "iconv.h"
+#include "giconv.h"
 #include "wv.h"
 
 extern TokenTable s_Tokens[];
