--- src/backends/libgbf_am/gbf-am-build.c.orig	Thu Oct 16 11:34:19 2003
+++ src/backends/libgbf_am/gbf-am-build.c	Thu Oct 16 11:35:42 2003
@@ -27,9 +27,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
-#include <regex.h>
 #include "gbf-i18n.h"
 #include "gbf-am-build.h"
+#include <gnuregex.h>
 
 /* FIXME: mark strings for translation and this file to POTFILES.in */
 
