
$FreeBSD$

--- src/gtkextext/gtkextext.h.orig	Fri Oct 26 23:57:02 2001
+++ src/gtkextext/gtkextext.h	Mon Nov 19 13:16:44 2001
@@ -30,8 +30,10 @@
 
 #include <sys/types.h>
 
+#include "config.h"
+
 #ifdef WITH_SYSTEM_REGEX
-#include <regex.h>
+#include <gnuregex.h>
 #else
 #include "regex.h"
 #endif
