--- libguile/read.c	2008-02-23 18:05:20.175715735 -0600
+++ libguile/read.c	2008-02-23 18:06:27.495397147 -0600
@@ -27,7 +27,7 @@
 #include <ctype.h>
 #include <string.h>
 #ifdef HAVE_STRINGS_H
-# include <strings.h>
+# include "/usr/include/strings.h"
 #endif
 
 #include "libguile/_scm.h"
