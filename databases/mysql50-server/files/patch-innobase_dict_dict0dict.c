--- innobase/dict/dict0dict.c.orig	Fri Jan 26 22:17:57 2007
+++ innobase/dict/dict0dict.c	Fri Jan 26 22:20:11 2007
@@ -28,7 +28,7 @@
 #include "rem0cmp.h"
 
 /* Implement isspace() in a locale-independent way. (Bug #24299) */
-#define ib_isspace(c) strchr(" \v\f\t\r\n", c)
+#define ib_isspace(c) (strchr(" \v\f\t\r\n", c) && c != '\0')
 
 dict_sys_t*	dict_sys	= NULL;	/* the dictionary system */
 
