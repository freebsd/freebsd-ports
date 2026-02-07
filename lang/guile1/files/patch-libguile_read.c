--- libguile/read.c.orig	2010-12-13 17:24:40 UTC
+++ libguile/read.c
@@ -27,7 +27,7 @@
 #include <ctype.h>
 #include <string.h>
 #ifdef HAVE_STRINGS_H
-# include <strings.h>
+# include "/usr/include/strings.h"
 #endif
 
 #include "libguile/_scm.h"
